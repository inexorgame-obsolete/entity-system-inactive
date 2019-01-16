// Inexor entity system
// (c)2018-2019 Inexor

#include "TypeBase.hpp"


namespace inexor {
namespace entity_system {


	TypeBase::TypeBase(const std::string& type_name)
	{
        // Use lock guard to ensure thread safety for this write operation!
        std::lock_guard<std::mutex> lock(type_base_mutex);
		type_title = type_name;
	}


	TypeBase::~TypeBase()
	{
		// TODO: Implement!
	}


	std::string TypeBase::get_type_name() const
	{
        // Read only, no mutex required.
		return type_title;
	}


};
};
