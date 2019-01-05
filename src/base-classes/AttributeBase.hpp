// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../data-container/DataTypes.hpp"
#include "../data-validation/DataValidationBase.hpp"


namespace inexor {
namespace entity_system {


	/// @brief A base class for attributes.
	/// @note This base class does not implement
	/// a data validation method. Every class which
	/// inherits from AttributeBase must do this!
	/// @note We can only inherit from AttributeTypeBase
	/// but we can't create instances of the class
	/// directly because it is an abstract class.
	/// @note AttributeBase does not have a GUID,
	/// because it is an abstract base class. The
	/// GUID is created by the classes which inherit
	/// from AttributeBase.
	class AttributeBase : public DataValidationBase
	{
		private:

			/// The data type of the attribute.
			/// @note The data is managed in the
			/// instance, not in this base class.
			ENTSYS_DATA_TYPE attribute_data_type;


		protected:
			
			/// Constructor.
			/// @param attr_data_type The data type
			/// of the attribute.
			AttributeBase(const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~AttributeBase();
			
		public:

			/// Returns the data type of the attribute.
			/// @return The data type of the attribute.
			ENTSYS_DATA_TYPE get_attribute_data_type() const;


	};

};
};
