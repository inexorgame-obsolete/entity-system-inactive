#pragma once

#include "scripting/modules/LoggingModule.hpp"
#include "scripting/modules/entity-system/EntitySystemModule.hpp"
#include "scripting/modules/UtilModule.hpp"

#include "v8.h"

#include <string>

namespace inexor {
namespace scripting {

	using LoggingModulePtr = std::shared_ptr<LoggingModule>;
	using EntitySystemModulePtr = std::shared_ptr<EntitySystemModule>;
	using UtilModulePtr = std::shared_ptr<UtilModule>;

	/// @class EcmaScriptPlatform
    /// @brief Service for executing ECMA scripts.
	class EcmaScriptPlatform
		: public std::enable_shared_from_this<EcmaScriptPlatform>
	{
		public:

			/// Constructor.
			EcmaScriptPlatform(
				LoggingModulePtr logging_module,
				EntitySystemModulePtr entity_system_module,
				UtilModulePtr util_module
			);

			/// Destructor.
			~EcmaScriptPlatform();

			/// Initialization of the EcmaScriptPlatform.
			void init();

			/// Shuts down the EcmaScriptPlatform.
			void shutdown();

			/// Returns the platform.
			v8::Platform* get_platform();

			/// Requires a module.
			static void require_module(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Returns the exception message.
			static std::string report_exception(v8::Isolate* isolate, v8::TryCatch* try_catch);

		private:

			/// The v8 platform.
			std::unique_ptr<v8::Platform> platform;

			/// The logging module.
			LoggingModulePtr logging_module;

			/// The entity system module.
			EntitySystemModulePtr entity_system_module;

			/// The util module.
			UtilModulePtr util_module;

	};

}
}
