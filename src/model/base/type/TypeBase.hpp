// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <string>

#include "../../../model/data/validation/DataValidationBase.hpp"
#include "../../../util/uuid/GUIDBase.hpp"


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
