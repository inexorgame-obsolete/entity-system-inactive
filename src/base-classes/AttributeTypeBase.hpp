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
	/// @note This means we can only inherit from
	/// AttributeTypeBase but not create instances
	/// of it. This means it is an abstract class.
	class AttributeTypeBase : public DataValidation
	{
		private:

			/// The data type of this attribute.
			ENTSYS_DATA_TYPE attribute_data_type;

		protected:
			
			/// Constructor.
			/// @param attr_data_type The data type of this attribute.
			AttributeTypeBase(const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~AttributeTypeBase();
			
			/// Returns the data type of the attribute type.
			/// @return The data type of the attribute type.
			ENTSYS_DATA_TYPE get_attribute_data_type() const;


	};

};
};
