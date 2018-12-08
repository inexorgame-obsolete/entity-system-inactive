// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../data-container/DataTypes.hpp"
#include "../data-validation/DataValidation.hpp"


namespace inexor {
namespace entity_system {


	/// @brief A base class for attributes of any type.
	/// @note This base class does not implement
	/// a data validation method! Every class which
	/// inherits from AttributeBase must do this!
	/// @note AttributeBase does not have a GUID,
	/// because it is only defined by ENTSYS_DATA_TYPE.
	/// @note We can only inherit from AttributeTypeBase
	/// but we can't create instances of the class directly
	/// because it is an abstract class.
	class AttributeBase : public DataValidation
	{
		private:

			/// The data type of the attribute.
			ENTSYS_DATA_TYPE attribute_data_type;

		protected:
			
			/// Constructor.
			/// @param attr_data_type The data type of this attribute.
			AttributeBase(const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~AttributeBase();
			
			/// Returns the data type of the attribute type.
			/// @return The data type of the attribute type.
			ENTSYS_DATA_TYPE get_attribute_data_type() const;


	};

};
};
