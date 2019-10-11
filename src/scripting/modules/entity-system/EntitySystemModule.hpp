#pragma once

#include "EntityTypeManagerModule.hpp"
#include "EntityInstanceManagerModule.hpp"

#include "v8.h"

namespace inexor {
namespace scripting {

	using EntityTypeManagerModulePtr = std::shared_ptr<EntityTypeManagerModule>;
	using EntityInstanceManagerModulePtr = std::shared_ptr<EntityInstanceManagerModule>;

	/// @class EntitySystemModule
    /// @brief Module for accessing the entity system from ECMA-Script.
	class EntitySystemModule
	{
		public:

			/// Constructor.
			EntitySystemModule(
				EntityTypeManagerModulePtr entity_type_manager_module,
				EntityInstanceManagerModulePtr entity_instance_manager_module
			);

			/// Destructor.
			~EntitySystemModule();

			/// Initialization of the EntitySystemModule.
			void init();

			/// Shuts down the EntitySystemModule.
			void shutdown();

			/// Creates the EntitySystemModule.
			void create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent);

		private:

			/// The entity type manager module.
			EntityTypeManagerModulePtr entity_type_manager_module;

			/// The entity instance manager module.
			EntityInstanceManagerModulePtr entity_instance_manager_module;

	};

}
}
