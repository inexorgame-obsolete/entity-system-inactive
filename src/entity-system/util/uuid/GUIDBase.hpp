#pragma once

#include <mutex>
#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class GUIDBase
	/// @brief A base class for globally unique identifiers (GUIDs).
	/// @note This implementation is based on crossguid.
	class GUIDBase
	{
		private:

			/// The mutex of this class.
			std::mutex guid_base_mutex;

			/// GUID of the class.
			xg::Guid globally_unique_identifier;

		protected:

			/// Constructor.
			GUIDBase();

			/// @brief Copy Constructor.
			/// @param The GUID which will be copied.
			GUIDBase(const xg::Guid& param_GUID);

			/// Destructor.
			~GUIDBase();

		public:

			/// @brief Returns the GUID of the class instance.
			/// @return The GUID of the class instance.
			xg::Guid get_GUID() const;

			/// Generates a new GUID.
			void generate_new_GUID();

	};

}
}
