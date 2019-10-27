#pragma once

#include "relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "relations/relation-type-manager/RelationTypeManager.hpp"
#include "relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace entity_system {

	/// @class RelationManager
	/// @brief A manager class for relations between entities.
	class RelationManager
	{
		public:

			/// @brief Constructor.
			/// @param entity_relation_type_manager The relation type manager.
			/// @param entity_relation_instance_manager The relation instance manager.
			/// @param entity_relation_attribute_type_manager The relation attribute type manager.
			/// @param entity_relation_attribute_instance_manager The relation attribute instance manager.
			RelationManager(
				std::shared_ptr<RelationTypeManager> entity_relation_type_manager,
				std::shared_ptr<RelationInstanceManager> entity_relation_instance_manager,
				std::shared_ptr<RelationAttributeTypeManager> entity_relation_attribute_type_manager,
				std::shared_ptr<RelationAttributeInstanceManager> entity_relation_attribute_instance_manager
			);

			/// @brief Destructor.
			~RelationManager();

			/// @brief Resets relation types, relation instances, relation attribute types and relation attribute instances.
			/// @note Order of destruction:
			/// <ol>
			///		<li> relation attribute instances
			///		<li> relation attribute types
			///		<li> relation instances
			///		<li> relation types
			/// </ol>
			void reset_relations_and_relation_attributes();

		private:

			/// The relation type manager.
			std::shared_ptr<RelationTypeManager> relation_type_manager;

			/// The relation instance manager.
			std::shared_ptr<RelationInstanceManager> relation_instance_manager;

			/// The relation attribute type manager.
			std::shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager;

			/// The relation attribute instance manager.
			std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager;

			/// The mutex of this class.
			std::mutex relation_manager_mutex;

		};

}
}
