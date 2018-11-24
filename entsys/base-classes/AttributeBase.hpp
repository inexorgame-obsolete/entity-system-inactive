// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../data-container/DataTypes.hpp"
#include "../data-validation/DataValidation.hpp"


namespace inexor {
namespace entity_system {


	// A base class for attributes of any type.
	class AttributeBase : public DataValidation
	{
		private:

			// The data type of this attribute.
			ENTSYS_DATA_TYPE attribute_data_type;

		protected:
			
			// 
			AttributeBase();

			// 
			~AttributeBase();

			// Set the data type of this attribute's data container.
			void set_attribute_data_type(const ENTSYS_DATA_TYPE&);
			
			// Return the data type of the attribute type.
			ENTSYS_DATA_TYPE get_attribute_data_type() const;


	};

};
};
