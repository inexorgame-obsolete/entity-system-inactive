// Inexor entity system prototype
// (c)2018 Inexor

#include "TypeBase.hpp"


namespace inexor {
namespace entity_system {


	TypeBase::TypeBase(const std::string& type_name)
	{
		type_title = type_name;
	}


	TypeBase::~TypeBase()
	{
		// TODO: Implement!
	}


	std::string TypeBase::get_type_name() const
	{
		return type_title;
	}

	
	ENTSYS_DATA_VALIDATION_RESULT TypeBase::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_INVALID;
	}


};
};
