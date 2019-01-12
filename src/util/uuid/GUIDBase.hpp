// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <crossguid/guid.hpp>


namespace inexor {
namespace entity_system {


	/// A class for globally unique identifiers.
	class GUIDBase
	{
		private:

            // 
            std::mutex guid_base_mutex;

			/// The GUID of the class.
			xg::Guid globally_unique_identifier = xg::newGuid();

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

};
};
