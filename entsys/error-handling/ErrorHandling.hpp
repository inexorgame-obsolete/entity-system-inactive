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


	// A handling class for errors in Inexor's entity system prototype.
	class EntitySystemErrorHandler
	{
		protected:

			void error_message(const std::string&);

		public:

			EntitySystemErrorHandler();
			~EntitySystemErrorHandler();

	};


};
};
