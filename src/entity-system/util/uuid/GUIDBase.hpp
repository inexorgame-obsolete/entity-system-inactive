#pragma once

#include <mutex>
#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class GUIDBase
	/// @brief A base class for globally unique identifiers (GUIDs).
	/// @note The implementation is based on crossguid.
	class GUIDBase
	{
		private:

			/// Mutex for this GUID base class.
			std::mutex guid_base_mutex;

			/// GUID of the class.
			xg::Guid globally_unique_identifier;

		protected:

			/// Constructor.
			GUIDBase();

			/// Copy Constructor.
			GUIDBase(const xg::Guid&);

			/// Destructor.
			~GUIDBase();

		public:

			/// Returns the GUID of the class instance.
			/// @return The GUID of the class instance.
			xg::Guid get_GUID() const;

			/// Generates a new GUID
			void generate_new_GUID();

	};

}
}
