#include "EntityInstanceManagerModule.hpp"
#include "EcmaScriptUtils.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace scripting {

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	using EntityAttributeTypePtr = std::shared_ptr<entity_system::EntityAttributeType>;
	using EntityAttributeTypePtrList = std::vector<EntityAttributeTypePtr>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	EntityInstanceManagerModule::EntityInstanceManagerModule(
		EntityInstanceManagerPtr entity_instance_manager
	)
	{
		this->entity_instance_manager = entity_instance_manager;
	}

	EntityInstanceManagerModule::~EntityInstanceManagerModule()
	{
	}

	void EntityInstanceManagerModule::init()
	{
	}

	void EntityInstanceManagerModule::shutdown()
	{
	}

	void EntityInstanceManagerModule::create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent)
	{
		// Create module object
		v8::Local<v8::Object> entity_instance_manager_module = v8::Local<v8::Object>::New(isolate, v8::Object::New(isolate));
		// Wrap the service class pointer as v8::External, which have to be unwrapped in the function callbacks again
		v8::Local<v8::External> entity_instance_manager_ref = v8::External::New(isolate, (void *) entity_instance_manager.get());
		// Create module function callbacks
		entity_instance_manager_module->Set(context, v8::String::NewFromUtf8(isolate, "does_entity_instance_exist"), v8::Function::New(context, EntityInstanceManagerModule::does_entity_instance_exist, entity_instance_manager_ref.As<v8::Value>()).ToLocalChecked());
		entity_instance_manager_module->Set(context, v8::String::NewFromUtf8(isolate, "get_entity_instance"), v8::Function::New(context, EntityInstanceManagerModule::get_entity_instance, entity_instance_manager_ref.As<v8::Value>()).ToLocalChecked());
		entity_instance_manager_module->Set(context, v8::String::NewFromUtf8(isolate, "get_entity_instance_count"), v8::Function::New(context, EntityInstanceManagerModule::get_entity_instance_count, entity_instance_manager_ref.As<v8::Value>()).ToLocalChecked());
		// Set module object in parent module object
		parent->Set(context, v8::String::NewFromUtf8(isolate, "entityInstanceManager"), entity_instance_manager_module);
	}

	void EntityInstanceManagerModule::does_entity_instance_exist(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		entity_system::EntityInstanceManager* entity_instance_manager = static_cast<entity_system::EntityInstanceManager*>(args.Data().As<v8::External>()->Value());
		v8::ReturnValue<v8::Value> return_value = args.GetReturnValue();
		if (args.Length() > 0)
		{
			v8::String::Utf8Value str(isolate, args[0]);
			std::optional<xg::Guid> guid = get_guid(str);
			if (guid.has_value())
			{
				return_value.Set(v8::Boolean::New(isolate, entity_instance_manager->does_entity_instance_exist(guid.value())));
				return;
			}
		}
		return_value.Set(v8::Boolean::New(isolate, false));
	}

	void EntityInstanceManagerModule::get_entity_instance(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		entity_system::EntityInstanceManager* entity_instance_manager = static_cast<entity_system::EntityInstanceManager*>(args.Data().As<v8::External>()->Value());
		v8::ReturnValue<v8::Value> return_value = args.GetReturnValue();
		if (args.Length() > 0)
		{
			v8::String::Utf8Value str(isolate, args[0]);
			std::optional<xg::Guid> guid = get_guid(str);
			if (guid.has_value())
			{
				EntityInstancePtrOpt o_entity_instance = entity_instance_manager->get_entity_instance(guid.value());
				if (o_entity_instance.has_value())
				{
					EntityInstancePtr entity_instance = o_entity_instance.value();

					// Get the object template
					v8::Local<v8::ObjectTemplate> entity_instance_template = EntityInstanceManagerModule::get_entity_instance_template(isolate);

					// Create a new JS-object which represents the c++ EntityInstance
					v8::Local<v8::Object> entity_instance_object = entity_instance_template->NewInstance(context).ToLocalChecked();

					// Store the actual entity instance as "internal field",
					// which is non-visible to the javascript, but can be
					// unwrapped by the handlers (see also: get_entity_instance_template)
					entity_instance_object->SetInternalField(0, v8::External::New(isolate, entity_instance.get()));

					// Return the entity instance as object
					return_value.Set(entity_instance_object);
					return;
				}
			}
		}
		return_value.Set(v8::Null(isolate));
	}

	void EntityInstanceManagerModule::get_entity_instance_count(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		entity_system::EntityInstanceManager* entity_instance_manager = static_cast<entity_system::EntityInstanceManager*>(args.Data().As<v8::External>()->Value());
		v8::ReturnValue<v8::Value> return_value = args.GetReturnValue();
		return_value.Set(v8::Integer::New(isolate, entity_instance_manager->get_entity_instance_count()));
	}

	v8::Local<v8::ObjectTemplate> EntityInstanceManagerModule::get_entity_instance_template(v8::Isolate* isolate)
	{
		// Create the object template for an entity instance.
		v8::Local<v8::ObjectTemplate> entity_instance_template = v8::ObjectTemplate::New(isolate);
		// There is one non-visible internal field, which stores the pointer to
		// the actual entity instance.
		entity_instance_template->SetInternalFieldCount(1);
		// Define the property accessors (getter and setter) as well as the
		// enummeration handler for reflecting the object. The allows the use
		// of Object.getOwnPropertyNames() on entity instances.
		entity_instance_template->SetHandler(
			v8::NamedPropertyHandlerConfiguration(

				// GenericNamedPropertyGetterCallback
				EntityInstanceManagerModule::entity_instance_get_attribute_value,

				// GenericNamedPropertySetterCallback
				EntityInstanceManagerModule::entity_instance_set_attribute_value,

				// GenericNamedPropertyQueryCallback
				nullptr,

				// GenericNamedPropertyDeleterCallback
				nullptr,

				// GenericNamedPropertyEnumeratorCallback
				EntityInstanceManagerModule::entity_instance_get_attributes_names

				// Local<Value> data
				// if we need to wrap something

			)
		);
		return entity_instance_template;
	}

	void EntityInstanceManagerModule::entity_instance_get_attribute_value(v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info)
	{
		v8::Isolate* isolate = info.GetIsolate();
		v8::Local<v8::Object> self = info.Holder();
		v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(self->GetInternalField(0));
		void* ptr = wrap->Value();
		EntityInstance* entity_instance = static_cast<EntityInstance*>(ptr);

		std::string attr_name = object_to_string(isolate, property);

		v8::ReturnValue<v8::Value> return_value = info.GetReturnValue();
		if (attr_name == "uuid")
		{
			return_value.Set(EntityInstanceManagerModule::entity_instance_get_uuid(isolate, entity_instance));
		} else if (attr_name == "type") {
			return_value.Set(EntityInstanceManagerModule::entity_instance_get_type_name(isolate, entity_instance));
		} else {
			EntityAttributeInstancePtrOpt o_attr = entity_instance->get_attribute_instance(attr_name);
			if (o_attr.has_value())
			{
				return_value.Set(EntityInstanceManagerModule::entity_attribute_instance_get_value(isolate, o_attr.value()));
			} else {
				spdlog::warn("ei_get_attr_value: attr {} not found", attr_name);
				return_value.Set(v8::Null(isolate));
			}
		}
	}

	void EntityInstanceManagerModule::entity_instance_set_attribute_value(v8::Local<v8::Name> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<v8::Value>& info)
	{
		v8::Isolate* isolate = info.GetIsolate();
		v8::Local<v8::Object> self = info.Holder();
		v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(self->GetInternalField(0));
		void* ptr = wrap->Value();
		EntityInstance* entity_instance = static_cast<EntityInstance*>(ptr);

		std::string attr_name = object_to_string(isolate, property);
		spdlog::debug("ei_get_attr_value: attr {}", attr_name);

		v8::ReturnValue<v8::Value> return_value = info.GetReturnValue();
		if (attr_name == "uuid")
		{
			// We do not change the uuid, but we return the exiting uuid
			return_value.Set(EntityInstanceManagerModule::entity_instance_get_uuid(isolate, entity_instance));
		} else if (attr_name == "type") {
			return_value.Set(EntityInstanceManagerModule::entity_instance_get_type_name(isolate, entity_instance));
		} else {
			EntityAttributeInstancePtrOpt o_attr = entity_instance->get_attribute_instance(attr_name);
			if (o_attr.has_value())
			{
				// Change the attribute value (if possible).
				// It is not possible, if the data type is not compatible
				EntityAttributeInstancePtr attr = o_attr.value();
				EntityInstanceManagerModule::entity_attribute_instance_set_value(isolate, attr, value);
				// Return the value of the attribute
				// The actual calculated value is returned which might
				// be different if there's a connector attached to this
				// attribute!
				return_value.Set(EntityInstanceManagerModule::entity_attribute_instance_get_value(isolate, attr));
			} else {
				// TODO: shall we create the attribute?
				spdlog::warn("ei_get_attr_value: attr {} not found! TODO: shall be create the attribute?", attr_name);
				return_value.Set(v8::Null(isolate));
			}
		}
	}

	void EntityInstanceManagerModule::entity_instance_get_attributes_names(const v8::PropertyCallbackInfo<v8::Array>& info)
	{
		v8::Isolate* isolate = info.GetIsolate();
		v8::Local<v8::Object> self = info.Holder();
		v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(self->GetInternalField(0));
		void* ptr = wrap->Value();
		EntityInstance* entity_instance = static_cast<EntityInstance*>(ptr);

		std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> o_attributes = entity_instance->get_instances();
		if (o_attributes.has_value())
		{
			std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr> attributes = o_attributes.value();
			v8::Local<v8::Array> attr_names = v8::Array::New(isolate, attributes.size() + 2);
			attr_names->Set(0, string_to_name(isolate, "uuid"));
			attr_names->Set(1, string_to_name(isolate, "type"));
			int i = 2;
			for (auto kv : attributes)
			{
				attr_names->Set(i, string_to_name(isolate, kv.first->get_type_name()));
				i++;
			}
			info.GetReturnValue().Set(attr_names);
		} else {
			// Return empty array
			spdlog::warn("The entity instance seems to have no attributes?");
			v8::Local<v8::Array> attr_names = v8::Array::New(isolate, 2);
			attr_names->Set(0, string_to_name(isolate, "uuid"));
			attr_names->Set(1, string_to_name(isolate, "type"));
			info.GetReturnValue().Set(attr_names);
		}
	}

	v8::Local<v8::Value> EntityInstanceManagerModule::entity_attribute_instance_get_value(v8::Isolate* isolate, EntityAttributeInstancePtr ent_attr_inst)
	{
		// Get the signaled value, not the own value
		return data_value_to_value(isolate, ent_attr_inst->type, ent_attr_inst->value.Value());
	}

	void EntityInstanceManagerModule::entity_attribute_instance_set_value(v8::Isolate* isolate, EntityAttributeInstancePtr ent_attr_inst, v8::Local<v8::Value> value)
	{
		// Set the own value, not the resulting signaled value!
		// If there is a signal connected to this attribute, the own_value is set, but the resulting value does not change of course
		// Perform a type check before attempting to set the value of the entity instance attribute
		if (has_data_type(ent_attr_inst->type, value))
		{
			ent_attr_inst->own_value.Set(value_to_data_value(isolate, ent_attr_inst->type, value));
		} else {
			spdlog::warn("eai_set: datatype {} is not compatible", ent_attr_inst->type._to_string());
		}
	}

	v8::Local<v8::String> EntityInstanceManagerModule::entity_instance_get_uuid(v8::Isolate* isolate, EntityInstance* entity_instance)
	{
		return v8::String::NewFromUtf8(isolate, entity_instance->get_GUID().str().c_str());
	}

	v8::Local<v8::String> EntityInstanceManagerModule::entity_instance_get_type_name(v8::Isolate* isolate, EntityInstance* entity_instance)
	{
		return v8::String::NewFromUtf8(isolate, entity_instance->get_entity_type()->get_type_name().c_str());
	}

}
}
