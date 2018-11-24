// Inexor entity system prototype
// (c)2018 Inexor

#include "ErrorHandling.hpp"


namespace inexor {
namespace entity_system {


	void EntitySystemErrorHandler::entsys_message(const ENTSYS_ERROR_LEVEL& level,
		                                          const std::string& param_error_message)
	{
		#ifdef INEXOR_ENTSYS_DEBUG
		std::cout << param_error_message << std::endl;
		#endif
	}


	EntitySystemErrorHandler::EntitySystemErrorHandler()
	{
	}

	
	EntitySystemErrorHandler::~EntitySystemErrorHandler()
	{
	}


};
};
