// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <mutex>

#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


    /// @class TypeBase
	/// @brief A template base class for types.
	/// @note It does not make sense to let TypeBase inherit
    /// from GUIDBase, because then all classes which inherit
    /// from TypeBase would have multiple get_GUID() methods!
	class TypeBase
	{
		private:

			/// Unique name of this type.
			std::string type_title;

            /// Mutex for this base class.
            std::mutex type_base_mutex;

		protected:

			/// @brief Constructor.
			TypeBase(const std::string&);

			/// @brief Destructor.
			~TypeBase();

		public:

			/// @brief Returns the name of this type.
			/// @return The name of this type.
			std::string get_type_name() const;


	};

};
};
