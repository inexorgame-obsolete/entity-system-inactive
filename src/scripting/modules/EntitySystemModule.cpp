#include "EntitySystemModule.hpp"

namespace inexor {
namespace scripting {

	EntitySystemModule::EntitySystemModule(
		EntityInstanceManagerModulePtr entity_instance_manager_module
	)
	{
		this->entity_instance_manager_module = entity_instance_manager_module;
	}

	EntitySystemModule::~EntitySystemModule()
	{
	}

	void EntitySystemModule::init()
	{
		entity_instance_manager_module->init();
	}

	void EntitySystemModule::shutdown()
	{
		entity_instance_manager_module->shutdown();
	}

	void EntitySystemModule::create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent)
	{
		// Create module object
		v8::Local<v8::Object> entity_system_module = v8::Local<v8::Object>::New(isolate, v8::Object::New(isolate));
		// Create module function callbacks
		//  None
		// Create sub module(s)
		entity_instance_manager_module->create(isolate, context, entity_system_module);
		// Set module object in parent module object
		parent->Set(context, v8::String::NewFromUtf8(isolate, "entity_system"), entity_system_module);
	}

}
}
