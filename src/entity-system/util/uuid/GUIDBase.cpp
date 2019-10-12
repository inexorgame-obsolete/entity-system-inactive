#include "GUIDBase.hpp"

namespace inexor {
namespace entity_system {

	GUIDBase::GUIDBase()
	{
		// If the GUID is not given to us like in the copy constructor
		// we generate a new one in this standard constructor.
		generate_new_GUID();
	}

	GUIDBase::GUIDBase(const xg::Guid& param_GUID)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(guid_base_mutex);

		// Copy the GUID which is given as parameter.
		this->globally_unique_identifier = param_GUID;
	}

	GUIDBase::~GUIDBase()
	{
	}

	xg::Guid GUIDBase::get_GUID() const
	{
		// No mutex required as this is a read-only operation.
		return globally_unique_identifier;
	}

	void GUIDBase::generate_new_GUID()
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(guid_base_mutex);

		// Generate a new GUID.
		globally_unique_identifier = xg::newGuid();
	}

}
}
