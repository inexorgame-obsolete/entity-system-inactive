// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../data-validation/DataValidation.hpp"
#include "../../../data-container/DataTypes.hpp"
#include "../../../base-classes/TypeBase.hpp"
#include "../../../base-classes/AttributeBase.hpp"


namespace inexor {
namespace entity_system {
    

	/// A base class for types of entity attributes.
    class EntityRelationAttributeType : public TypeBase, public AttributeBase
    {
        public:

			/// Constructor.
			/// @param ent_rel_attr_type_name The name of the new entity relation attribute type.
			/// @param ent_rel_attr_type_data_type The data type of the new entity relation attribute type.
			/// @return A shared pointer to the entity relation attribute type which was created.
			/// TODO entity_relation_attribute_type_ERROR!
			EntityRelationAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~EntityRelationAttributeType();

			/// 
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
