// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <iostream>

#include "ErrorLevels.hpp"

namespace inexor {
namespace entity_system {


	// 
	class EntitySystemErrorHandler
	{
		protected:

			// 
			void error_message(const std::string&);

		public:

			EntitySystemErrorHandler();

			~EntitySystemErrorHandler();

	};

};
};
