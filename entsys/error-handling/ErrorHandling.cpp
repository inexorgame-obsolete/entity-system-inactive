#include "ErrorHandling.hpp"
#include "../tests/EntitySystemDebugging.hpp"


namespace inexor {
namespace entity_system {


	void EntitySystemErrorHandler::error_message(const std::string& param_error_message)
	{
		#ifdef INEXOR_DEBUG
		std::cout << param_error_message << std::endl;
		#endif
	}


	EntitySystemErrorHandler::EntitySystemErrorHandler()
	{
		// TODO: implement!
	}

	
	EntitySystemErrorHandler::~EntitySystemErrorHandler()
	{
		// TODO: implement!
	}


};
};
