// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-type/EntityRelationType.hpp"
#include "../../entity-type-manager/entity-type-instance/EntityTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../entity-relation-attribute-manager/entity-relation-attribute-type-instance/EntityRelationAttributeTypeInstance.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for instances of types of relations between entity types.
	class EntityRelationTypeInstance : public TypeInstanceBase<EntityRelationType,EntityRelationTypeInstance>
	{
		private:
		
			/// The instance of the source entity type.
			ENT_TYPE_INST source_entity_type_instance;

			/// The instance of the target entity type.
			ENT_TYPE_INST destination_entity_type_instance;
			
			/// Instances of relation attribute types.
			std::unordered_map<ENT_REL_ATTR_TYPE, ENT_REL_ATTR_TYPE_INST> relation_attribute_instances;

		public:

			/// Constructor.
			/// @param ? TODO
			/// @param ? TODO
			/// @param ? TODO
			EntityRelationTypeInstance(const ENT_REL_TYPE&, const ENT_TYPE_INST&, const ENT_TYPE_INST&);

			/// Destructor.
			~EntityRelationTypeInstance();


			// TODO: get source entity type
			// TODO: get destination entity type
			// TODO: Set data !

			
	};


};
};
