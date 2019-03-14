#include "ConsoleProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	ConsoleProviders::ConsoleProviders(
		StdInEntityTypeProviderPtr std_in_entity_type_provider,
		StdOutEntityTypeProviderPtr std_out_entity_type_provider,
		StdErrEntityTypeProviderPtr std_err_entity_type_provider
	)
	{
		this->std_in_entity_type_provider = std_in_entity_type_provider;
		this->std_out_entity_type_provider = std_out_entity_type_provider;
		this->std_err_entity_type_provider = std_err_entity_type_provider;
	}

	ConsoleProviders::~ConsoleProviders()
	{
	}

	void ConsoleProviders::init()
	{
	}

}
}
}
