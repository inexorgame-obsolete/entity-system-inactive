#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"

#include "v8.h"
#include "v8-platform.h"

#include <string>

namespace inexor {
namespace scripting {

	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;

	using EntityType = entity_system::EntityType;
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityInstance = entity_system::EntityInstance;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

	/// @class EntityInstanceManagerModule
    /// @brief Module for accessing the EntityInstanceManager from ECMA-Script.
	class EntityInstanceManagerModule
	{
		public:

			/// Constructor.
			EntityInstanceManagerModule(
				EntityInstanceManagerPtr entity_instance_manager
			);

			/// Destructor.
			~EntityInstanceManagerModule();

			/// Initialization of the EntityInstanceManagerModule.
			void init();

			/// Shuts down the EntityInstanceManagerModule.
			void shutdown();

			/// Creates the EntityInstanceManagerModule.
			void create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent);

			/// Creates and returns an entity instance.
			static void create_entity_instance(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns true, if the entity instance exists with the given uuid.
			static void does_entity_instance_exist(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns the entity instance by uuid.
			static void get_entity_instance(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns the entity instance count.
			static void get_entity_instance_count(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns the object template for entity instances.
			static v8::Local<v8::ObjectTemplate> get_entity_instance_template(v8::Isolate* isolate);

			static void entity_instance_get_attribute_value(v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info);

			static void entity_instance_set_attribute_value(v8::Local<v8::Name> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<v8::Value>& info);

			/// Returns an array containing the attribute names of the entity instance.
			/// @note The values in the array must be of type v8::Name.
			/// @see Object.getOwnPropertyNames(entity_instance);
			static void entity_instance_get_attributes_names(const v8::PropertyCallbackInfo<v8::Array>& info);

			/// Attribute-Getter
			/// Returns the V8 representation of the value of an entity attribute instance.
			static v8::Local<v8::Value> entity_attribute_instance_get_value(v8::Isolate* isolate, EntityAttributeInstancePtr ent_attr_inst);

			/// Attribute-Setter
			/// Sets the value of the entity attribute instance if the value of
			/// the entity instance property was changed.
			static void entity_attribute_instance_set_value(v8::Isolate* isolate, EntityAttributeInstancePtr ent_attr_inst, v8::Local<v8::Value> value);

			/// Returns a V8 string of the UUID of the given entity instance.
			static v8::Local<v8::String> entity_instance_get_uuid(v8::Isolate* isolate, EntityInstancePtr entity_instance);

			/// Returns a V8 string of the type name of the given entity instance.
			static v8::Local<v8::String> entity_instance_get_type_name(v8::Isolate* isolate, EntityInstancePtr entity_instance);

		private:

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// Stores entity instances which are in use by JS.
			/// std::vector<EntityInstancePtr> entity_instances;

	};

}
}
