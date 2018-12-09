// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

/// TODO: Fix conan package manager for dependencies!
/// This file will not be contained in the repository itself.
/// https://github.com/graeme-hill/crossguid
#include <crossguid/guid.hpp>


namespace inexor {
namespace entity_system {


	/// A class for globally unique identifiers.
	class GUIDBase
	{
		private:

			/// The GUID of the class.
			xg::Guid the_GUID = xg::newGuid();

		protected:

			/// Constructor.
			GUIDBase();

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
