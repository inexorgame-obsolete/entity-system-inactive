// Inexor entity system prototype
// (c)2018 Inexor

#include "GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	GUIDBase::GUIDBase()
	{
		// TODO: Implement!
	}


	GUIDBase::GUIDBase(const xg::Guid& param_GUID)
	{
		globally_unique_identifier = param_GUID;
	}


	GUIDBase::~GUIDBase()
	{
		// TODO: Implement!
	}


	xg::Guid GUIDBase::get_GUID() const
	{
		return globally_unique_identifier;
	}


	void GUIDBase::generate_new_GUID()
	{
		/// Generate a new GUID.
		globally_unique_identifier = xg::newGuid();
	}


};
};
