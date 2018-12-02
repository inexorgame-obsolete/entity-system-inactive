// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <iostream>

#include "ErrorLevels.hpp"

// Undefine this macro when using release build.
#define INEXOR_ENTSYS_DEBUG


namespace inexor {
namespace entity_system {


	/// @brief An error handler class for in Inexor's entity system prototype.
	class EntitySystemErrorHandler
	{
		protected:

			/// @brief process an error/warning/info message in the entity system.
			/// @param level The error level which describes if its an info, warning of error message.
			/// @param param_error_message The message which will be processed.
			void entsys_message(const ENTSYS_ERROR_LEVEL&, const std::string&);

		public:

			/// Constructor.
			EntitySystemErrorHandler();
			
			/// Destructor.
			~EntitySystemErrorHandler();

	};


};
};
