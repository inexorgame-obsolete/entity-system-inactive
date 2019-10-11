#pragma once

#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"

#include "v8.h"
#include "v8-platform.h"

#include <string>

namespace inexor {
namespace scripting {

	using EntityTypeManagerPtr = std::shared_ptr<entity_system::EntityTypeManager>;

	using EntityType = entity_system::EntityType;
	using EntityTypePtr = std::shared_ptr<EntityType>;

	/// @class EntityTypeManagerModule
    /// @brief Module for accessing the EntityTypeManager from ECMA-Script.
	class EntityTypeManagerModule
	{
		public:

			/// Constructor.
			EntityTypeManagerModule(
				EntityTypeManagerPtr entity_type_manager
			);

			/// Destructor.
			~EntityTypeManagerModule();

			/// Initialization of the EntityTypeManagerModule.
			void init();

			/// Shuts down the EntityTypeManagerModule.
			void shutdown();

			/// Creates the EntityTypeManagerModule.
			void create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent);

			/// Creates and returns an entity type.
			static void create_entity_type(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns true, if the entity type exists with the given name.
			static void does_entity_type_exist(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns the entity type count.
			static void get_entity_type_count(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns the entity type by name.
			static void get_entity_type(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns the object template for entity types.
			static v8::Local<v8::ObjectTemplate> get_entity_type_template(v8::Isolate* isolate);

			static void entity_type_get_attribute_value(v8::Local<v8::Name> property, const v8::PropertyCallbackInfo<v8::Value>& info);

			static void entity_type_set_attribute_value(v8::Local<v8::Name> property, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<v8::Value>& info);

			/// Returns an array containing the attribute names of the entity type.
			/// @note The values in the array must be of type v8::Name.
			/// @see Object.getOwnPropertyNames(entity_type);
			static void entity_type_get_attributes_names(const v8::PropertyCallbackInfo<v8::Array>& info);

			/// Returns a V8 string of the UUID of the given entity type.
			static v8::Local<v8::String> entity_type_get_uuid(v8::Isolate* isolate, EntityTypePtr entity_type);

			/// Returns a V8 string of the name of the given entity type.
			static v8::Local<v8::String> entity_type_get_name(v8::Isolate* isolate, EntityTypePtr entity_type);

		private:

			/// The entity type manager.
			EntityTypeManagerPtr entity_type_manager;

	};

}
}
