#pragma once

#include "EntityInstanceManagerModule.hpp"
#include "logging/managers/LogManager.hpp"

#include "v8/v8.h"
//#include "v8/v8-platform.h"

#include <string>

namespace inexor {
namespace scripting {

	using EntityInstanceManagerModulePtr = std::shared_ptr<EntityInstanceManagerModule>;
	using LogManagerPtr = std::shared_ptr<logging::LogManager>;

	/// @class EntitySystemModule
    /// @brief Module for accessing the entity system from ECMA-Script.
	class EntitySystemModule
	{
		public:

			/// Constructor.
			EntitySystemModule(
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

			/// The entity instance manager module.
			EntityInstanceManagerModulePtr entity_instance_manager_module;

	};

}
}
