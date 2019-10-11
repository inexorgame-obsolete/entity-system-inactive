#include "EntityTypeManagerModule.hpp"
#include "scripting/utils/EcmaScriptUtils.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace scripting {

	using EntityTypePtrOpt = std::optional<EntityTypePtr>;
	using EntityAttributeTypePtr = std::shared_ptr<entity_system::EntityAttributeType>;
	using EntityAttributeTypePtrList = std::vector<EntityAttributeTypePtr>;

	EntityTypeManagerModule::EntityTypeManagerModule(
		EntityTypeManagerPtr entity_type_manager
	)
	{
		this->entity_type_manager = entity_type_manager;
	}

	EntityTypeManagerModule::~EntityTypeManagerModule()
	{
	}

	void EntityTypeManagerModule::init()
	{
	}

	void EntityTypeManagerModule::shutdown()
	{
	}

	void EntityTypeManagerModule::create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent)
	{
		// Create module object
		v8::Local<v8::Object> entity_type_manager_module = v8::Local<v8::Object>::New(isolate, v8::Object::New(isolate));
		// Wrap the service class pointer as v8::External, which have to be unwrapped in the function callbacks again
		v8::Local<v8::External> entity_type_manager_ref = v8::External::New(isolate, (void *) entity_type_manager.get());
		// Create module function callbacks
		entity_type_manager_module->Set(context, v8::String::NewFromUtf8(isolate, "create_entity_type"), v8::Function::New(context, EntityTypeManagerModule::create_entity_type, entity_type_manager_ref.As<v8::Value>()).ToLocalChecked());
		entity_type_manager_module->Set(context, v8::String::NewFromUtf8(isolate, "does_entity_type_exist"), v8::Function::New(context, EntityTypeManagerModule::does_entity_type_exist, entity_type_manager_ref.As<v8::Value>()).ToLocalChecked());
		entity_type_manager_module->Set(context, v8::String::NewFromUtf8(isolate, "get_entity_type"), v8::Function::New(context, EntityTypeManagerModule::get_entity_type, entity_type_manager_ref.As<v8::Value>()).ToLocalChecked());
		entity_type_manager_module->Set(context, v8::String::NewFromUtf8(isolate, "get_entity_type_count"), v8::Function::New(context, EntityTypeManagerModule::get_entity_type_count, entity_type_manager_ref.As<v8::Value>()).ToLocalChecked());
		// Set module object in parent module object
		parent->Set(context, v8::String::NewFromUtf8(isolate, "entityTypeManager"), entity_type_manager_module);
	}

	void EntityTypeManagerModule::create_entity_type(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		entity_system::EntityTypeManager* entity_type_manager = static_cast<entity_system::EntityTypeManager*>(args.Data().As<v8::External>()->Value());
		v8::ReturnValue<v8::Value> return_value = args.GetReturnValue();
		if (args.Length() > 0)
		{
			v8::String::Utf8Value str(isolate, args[0]);
			EntityTypePtrOpt o_entity_type = entity_type_manager->create_entity_type(std::string(*str));
			if (o_entity_type.has_value())
			{
				EntityTypePtr* entity_type = &o_entity_type.value();

				// Get the object template
				v8::Local<v8::ObjectTemplate> entity_type_template = EntityTypeManagerModule::get_entity_type_template(isolate);

				// Create a new JS-object which represents the c++ EntityType
				v8::Local<v8::Object> entity_type_object = entity_type_template->NewInstance(context).ToLocalChecked();

				// Store the actual entity type as "internal field",
				// which is non-visible to the javascript, but can be
				// unwrapped by the handlers (see also: get_entity_type_template)
				entity_type_object->SetInternalField(0, v8::External::New(isolate, entity_type));

				// Return the entity type as object
				return_value.Set(entity_type_object);
				spdlog::info("Entity type {} created", (*str));
				return;
			}
		}
		return_value.Set(v8::Null(isolate));
	}

	void EntityTypeManagerModule::does_entity_type_exist(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		entity_system::EntityTypeManager* entity_type_manager = static_cast<entity_system::EntityTypeManager*>(args.Data().As<v8::External>()->Value());
		v8::ReturnValue<v8::Value> return_value = args.GetReturnValue();
		if (args.Length() > 0)
		{
			v8::String::Utf8Value str(isolate, args[0]);
			return_value.Set(v8::Boolean::New(isolate, entity_type_manager->does_entity_type_exist(std::string(*str))));
			return;

//			std::optional<xg::Guid> guid = get_guid(str);
//			if (guid.has_value())
//			{
//				return_value.Set(v8::Boolean::New(isolate, entity_type_manager->does_entity_type_exist(guid.value())));
//				return;
//			} else {
//				return_value.Set(v8::Boolean::New(isolate, entity_type_manager->does_entity_type_exist(std::string(*str))));
//				return;
//			}
		}
		return_value.Set(v8::Boolean::New(isolate, false));
	}

	void EntityTypeManagerModule::get_entity_type(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		entity_system::EntityTypeManager* entity_type_manager = static_cast<entity_system::EntityTypeManager*>(args.Data().As<v8::External>()->Value());
		v8::ReturnValue<v8::Value> return_value = args.GetReturnValue();
		if (args.Length() > 0)
		{
			v8::String::Utf8Value str(isolate, args[0]);
			EntityTypePtrOpt o_entity_type = entity_type_manager->get_entity_type(std::string(*str));
			if (o_entity_type.has_value())
			{
				EntityTypePtr* entity_type = &o_entity_type.value();

				// Get the object template
				v8::Local<v8::ObjectTemplate> entity_type_template = EntityTypeManagerModule::get_entity_type_template(isolate);

				// Create a new JS-object which represents the c++ EntityInstance
				v8::Local<v8::Object> entity_type_object = entity_type_template->NewInstance(context).ToLocalChecked();

				// Store the actual entity type as "internal field",
				// which is non-visible to the javascript, but can be
				// unwrapped by the handlers (see also: get_entity_type_template)
				entity_type_object->SetInternalField(0, v8::External::New(isolate, entity_type));

				// Return the entity type as object
				return_value.Set(entity_type_object);
				return;
			}
		}
		return_value.Set(v8::Null(isolate));
	}

	void EntityTypeManagerModule::get_entity_type_count(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		entity_system::EntityTypeManager* entity_type_manager = static_cast<entity_system::EntityTypeManager*>(args.Data().As<v8::External>()->Value());
		v8::ReturnValue<v8::Value> return_value = args.GetReturnValue();
		return_value.Set(v8::Integer::New(isolate, entity_type_manager->get_entity_type_count()));
	}

	v8::Local<v8::ObjectTemplate> EntityTypeManagerModule::get_entity_type_template(v8::Isolate* isolate)
	{
		// Create the object template for an entity type.
		v8::Local<v8::ObjectTemplate> entity_type_template = v8::ObjectTemplate::New(isolate);
		// There is one non-visible internal field, which stores the pointer to
		// the actual entity type.
		entity_type_template->SetInternalFieldCount(1);
		// Define the property accessors (getter and setter) as well as the
		// enummeration handler for reflecting the object. The allows the use
		// of Object.getOwnPropertyNames() on entity types.
		entity_type_template->SetHandler(
			v8::NamedPropertyHandlerConfiguration(

				// GenericNamedPropertyGetterCallback
				EntityTypeManagerModule::entity_type_get_attribute_value,

				// GenericNamedPropertySetterCallback
				EntityTypeManagerModule::entity_type_set_attribute_value,

				// GenericNamedPropertyQueryCallback
				nullptr,

				// GenericNamedPropertyDeleterCallback
				nullptr,

				// GenericNamedPropertyEnumeratorCallback
				EntityTypeManagerModule::entity_type_get_attributes_names

				// Local<Value> data
				// if we need to wrap something

			)
		);
		return entity_type_template;
	}

	void EntityTypeManagerModule::entity_type_get_attribute_value(v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info)
	{
		v8::Isolate* isolate = info.GetIsolate();
		v8::Local<v8::Object> self = info.Holder();
		v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(self->GetInternalField(0));
		void* ptr = wrap->Value();
		EntityTypePtr* entity_type = static_cast<EntityTypePtr*>(ptr);

		std::string attr_name = object_to_string(isolate, property);

		v8::ReturnValue<v8::Value> return_value = info.GetReturnValue();
		if (attr_name == "uuid")
		{
			return_value.Set(EntityTypeManagerModule::entity_type_get_uuid(isolate, (*entity_type)));
		} else if (attr_name == "name") {
			return_value.Set(EntityTypeManagerModule::entity_type_get_name(isolate, (*entity_type)));
		} else {
//			(*entity_type)->get_linked_attribute_types()
//			EntityAttributeInstancePtrOpt o_attr = (*entity_type)->get_attribute_instance(attr_name);
//			if (o_attr.has_value())
//			{
//				return_value.Set(EntityTypeManagerModule::entity_attribute_instance_get_value(isolate, o_attr.value()));
//			} else {
//				spdlog::warn("ei_get_attr_value: attr {} not found", attr_name);
//				return_value.Set(v8::Null(isolate));
//			}
			return_value.Set(v8::Null(isolate));
		}
	}

	void EntityTypeManagerModule::entity_type_set_attribute_value(v8::Local<v8::Name> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<v8::Value>& info)
	{
		v8::Isolate* isolate = info.GetIsolate();
		v8::Local<v8::Object> self = info.Holder();
		v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(self->GetInternalField(0));
		void* ptr = wrap->Value();
		EntityTypePtr* entity_type = static_cast<EntityTypePtr*>(ptr);

		std::string attr_name = object_to_string(isolate, property);
		spdlog::debug("ei_get_attr_value: attr {}", attr_name);

		v8::ReturnValue<v8::Value> return_value = info.GetReturnValue();
		if (attr_name == "uuid")
		{
			// We do not change the uuid, but we return the exiting uuid
			return_value.Set(EntityTypeManagerModule::entity_type_get_uuid(isolate, (*entity_type)));
		} else if (attr_name == "name") {
			// We do not change the name, but we return the exiting name
			return_value.Set(EntityTypeManagerModule::entity_type_get_name(isolate, (*entity_type)));
		} else {
//			EntityAttributeInstancePtrOpt o_attr = (*entity_type)->get_attribute_instance(attr_name);
//			if (o_attr.has_value())
//			{
//				// Change the attribute value (if possible).
//				// It is not possible, if the data type is not compatible
//				EntityAttributeInstancePtr attr = o_attr.value();
//				EntityTypeManagerModule::entity_attribute_instance_set_value(isolate, attr, value);
//				// Return the value of the attribute
//				// The actual calculated value is returned which might
//				// be different if there's a connector attached to this
//				// attribute!
//				return_value.Set(EntityTypeManagerModule::entity_attribute_instance_get_value(isolate, attr));
//			} else {
//				// TODO: shall we create the attribute?
//				spdlog::warn("ei_get_attr_value: attr {} not found! TODO: shall be create the attribute?", attr_name);
//				return_value.Set(v8::Null(isolate));
//			}
			return_value.Set(v8::Null(isolate));
		}
	}

	void EntityTypeManagerModule::entity_type_get_attributes_names(const v8::PropertyCallbackInfo<v8::Array>& info)
	{
		v8::Isolate* isolate = info.GetIsolate();
		v8::Local<v8::Object> self = info.Holder();
		v8::Local<v8::External> wrap = v8::Local<v8::External>::Cast(self->GetInternalField(0));
		void* ptr = wrap->Value();
		EntityTypePtr* entity_type = static_cast<EntityTypePtr*>(ptr);

		v8::Local<v8::Array> attr_names = v8::Array::New(isolate, 2);
		attr_names->Set(0, string_to_name(isolate, "uuid"));
		attr_names->Set(1, string_to_name(isolate, "name"));
		std::optional<EntityAttributeTypePtrList> o_linked_attribute_types = (*entity_type)->get_linked_attribute_types();
		if (o_linked_attribute_types.has_value())
		{
			EntityAttributeTypePtrList linked_attribute_types = o_linked_attribute_types.value();
			int i = 2;
			for (EntityAttributeTypePtr linked_attribute_type : linked_attribute_types)
			{
				attr_names->Set(i, string_to_name(isolate, linked_attribute_type->get_type_name()));
				i++;
			}
		}
		info.GetReturnValue().Set(attr_names);
	}

	v8::Local<v8::String> EntityTypeManagerModule::entity_type_get_uuid(v8::Isolate* isolate, EntityTypePtr entity_type)
	{
		return v8::String::NewFromUtf8(isolate, entity_type->get_GUID().str().c_str());
	}

	v8::Local<v8::String> EntityTypeManagerModule::entity_type_get_name(v8::Isolate* isolate, EntityTypePtr entity_type)
	{
		return v8::String::NewFromUtf8(isolate, entity_type->get_type_name().c_str());
	}

}
}
