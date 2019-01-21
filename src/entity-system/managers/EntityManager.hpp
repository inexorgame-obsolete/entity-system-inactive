// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>

#include "entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "relations/relation-type-manager/RelationTypeManager.hpp"
#include "relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {


    /// @class EntityManager
    /// @brief The entity manager class is responsible for adding,
    /// modifying and removing entity types, entity attributes,
    /// entity relations and instances of them.
    class EntityManager
    {

		public:

			/// Constructor.
		    EntityManager(
		    	std::shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager,
		    	std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager,
				std::shared_ptr<inexor::entity_system::EntityAttributeTypeManager> entity_attribute_type_manager,
				std::shared_ptr<inexor::entity_system::EntityAttributeInstanceManager> entity_attribute_instance_manager,
				std::shared_ptr<inexor::entity_system::RelationTypeManager> entity_relation_type_manager,
				std::shared_ptr<inexor::entity_system::RelationInstanceManager> entity_relation_instance_manager,
				std::shared_ptr<inexor::entity_system::RelationAttributeTypeManager> entity_relation_attribute_type_manager,
				std::shared_ptr<inexor::entity_system::RelationAttributeInstanceManager> entity_relation_attribute_instance_manager
		    );

			/// Destructor.
			~EntityManager();

			/// Resets the entire entity system.
			void reset_entity_system();

		private:

			/// The entity type manager.
			std::shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager;

			/// The entity instance manager.
			std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager;

			/// The entity attribute type manager.
			std::shared_ptr<inexor::entity_system::EntityAttributeTypeManager> entity_attribute_type_manager;

			/// The entity attribute instance manager.
			std::shared_ptr<inexor::entity_system::EntityAttributeInstanceManager> entity_attribute_instance_manager;

			/// The entity relation type manager.
			std::shared_ptr<inexor::entity_system::RelationTypeManager> entity_relation_type_manager;

			/// The entity relation instance manager.
			std::shared_ptr<inexor::entity_system::RelationInstanceManager> entity_relation_instance_manager;

			/// The entity relation attribute type manager.
			std::shared_ptr<inexor::entity_system::RelationAttributeTypeManager> entity_relation_attribute_type_manager;

			/// The entity relation attribute instance manager.
			std::shared_ptr<inexor::entity_system::RelationAttributeInstanceManager> entity_relation_attribute_instance_manager;

    };


};
};
