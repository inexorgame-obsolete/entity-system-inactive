// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <mutex>

#include "entity-system/model/data/validation/DataValidationBase.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


    /// @class TypeBase
	/// @brief A template base class for types.
	/// @note It does not make sense to let TypeBase inherit
    /// from GUIDBase, because then all classes which inherit
    /// from TypeBase would have multiple get_GUID() methods!
	/// @note This base class does not implement a
    /// data validation method. Every class which
	/// inherits from TypeBase must do this!
	class TypeBase : public DataValidationBase
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
