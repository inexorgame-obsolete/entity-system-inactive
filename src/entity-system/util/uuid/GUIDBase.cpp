#include "GUIDBase.hpp"

namespace inexor {
namespace entity_system {

	GUIDBase::GUIDBase()
	{
		// Use lock guard to ensure thread safety for this write operation!
		std::lock_guard<std::mutex> lock(guid_base_mutex);

        globally_unique_identifier = xg::newGuid();
	}

	GUIDBase::GUIDBase(const xg::Guid& param_GUID)
	{
		// Use lock guard to ensure thread safety for this write operation!
		std::lock_guard<std::mutex> lock(guid_base_mutex);

        // Store the GUID which was given to us.
		globally_unique_identifier = param_GUID;
	}

	GUIDBase::~GUIDBase()
	{
	}

	xg::Guid GUIDBase::get_GUID() const
	{
        // Read only, no mutex required.
		return globally_unique_identifier;
	}

	void GUIDBase::generate_new_GUID()
	{
		// Use lock guard to ensure thread safety for this write operation!
		std::lock_guard<std::mutex> lock(guid_base_mutex);

		// Generate a new GUID.
		globally_unique_identifier = xg::newGuid();
	}

}
}
