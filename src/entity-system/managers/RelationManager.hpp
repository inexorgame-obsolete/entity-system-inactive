#pragma once

#include "relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "relations/relation-type-manager/RelationTypeManager.hpp"
#include "relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"

#include <vector>

using namespace inexor::entity_system;

namespace inexor {
namespace entity_system {

	/// @class RelationManager
	/// @brief The relation manager manages the relation managers.
	class RelationManager
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.<br>
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// https://boost-experimental.github.io/di/user_guide/index.html
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

			/// Destructor.
			~RelationManager();

			/// Resets the entire entity system.
			/// @note Order of destruction:
			/// <ul>
			///		<li> relation attribute instances
			///		<li> relation attribute types
			///		<li> relation instances
			///		<li> relation types
			/// </ul>
			void reset_entity_system();

		private:

			/// The entity relation type manager.
			std::shared_ptr<RelationTypeManager> relation_type_manager;

			/// The entity relation instance manager.
			std::shared_ptr<RelationInstanceManager> relation_instance_manager;

			/// The entity relation attribute type manager.
			std::shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager;

			/// The entity relation attribute instance manager.
			std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager;

		};

}
}
