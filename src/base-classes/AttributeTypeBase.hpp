// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../data-container/DataTypes.hpp"
#include "../data-validation/DataValidation.hpp"

/// TODO: Fix conan package manager for dependencies!
/// This file will not be contained in the repository itself.
/// https://github.com/graeme-hill/crossguid
#include <crossguid/guid.hpp>


namespace inexor {
namespace entity_system {


	/// @brief A base class for attributes of any type.
	/// @note This base class does not implement
	/// a data validation method! Every class which
	/// inherits from AttributeBase must do this!
	class AttributeTypeBase : public DataValidation
	{
		private:

			/// The data type of this attribute.
			ENTSYS_DATA_TYPE attribute_data_type;

			/// The Universally Unique Identifier (UUID)
			/// of this attribute type.
			xg::Guid type_UUID = xg::newGuid();

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
