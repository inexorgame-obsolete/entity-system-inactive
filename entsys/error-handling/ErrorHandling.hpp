// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ERROR_HANDLING_HEADER
#define INEXOR_ENTSYS_ERROR_HANDLING_HEADER

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

			// 
			EntitySystemErrorHandler();

			// 
			~EntitySystemErrorHandler();

	};

};
};

#endif // INEXOR_ENTSYS_ERROR_HANDLING_HEADER
