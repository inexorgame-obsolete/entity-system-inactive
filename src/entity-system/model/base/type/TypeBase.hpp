// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <mutex>

#include "entity-system/model/data/validation/DataValidationBase.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// @note It does not make sense to let TypeBase or AttributeBase
	/// inherit from GUIDBase, because then EntityAttributeType would
	/// contain multiple get_GUID() methods!

	/// @brief A template base class for types.
	/// @note This base class does not implement
	/// a data validation method. Every class which
	/// inherits from TypeBase must do this!
	class TypeBase : public DataValidationBase
	{
		private:

			/// The unique name of this type.
			std::string type_title;

            /// Mutex for this base class.
            std::mutex type_base_mutex;

		protected:

			/// Constructor.
			TypeBase(const std::string&);

			/// Destructor.
			~TypeBase();

		public:

			/// Returns the name of this type.
			/// @return The name of this type.
			std::string get_type_name() const;


	};

};
};
