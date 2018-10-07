// Inexor entity system prototype
// (c)2018 Inexor

#include "ErrorHandling.hpp"


namespace inexor {
namespace entity_system {


	void EntitySystemErrorHandler::error_message(const std::string& param_error_message)
	{
		#ifdef INEXOR_ENTSYS_DEBUG
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
