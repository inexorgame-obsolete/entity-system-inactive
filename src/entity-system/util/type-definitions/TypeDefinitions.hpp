#pragma once

#include <memory>

namespace inexor {
namespace entity_system {

	#define ENT_ATTR_TYPE           std::shared_ptr<class EntityAttributeType>
	#define ENT_ATTR_INST           std::shared_ptr<class EntityAttributeInstance>
	#define ENT_TYPE                std::shared_ptr<class EntityType>
	#define ENT_INST                std::shared_ptr<class EntityInstance>
	#define REL_TYPE                std::shared_ptr<class RelationType>
	#define REL_INST                std::shared_ptr<class RelationInstance>
	#define REL_ATTR_TYPE           std::shared_ptr<class RelationAttributeType>
	#define REL_ATTR_INST           std::shared_ptr<class RelationAttributeInstance>

	// std::optional values.
	#define O_ENT_ATTR_TYPE         std::optional<ENT_ATTR_TYPE>
	#define O_ENT_ATTR_INST         std::optional<ENT_ATTR_INST>
	#define O_ENT_TYPE              std::optional<ENT_TYPE>
	#define O_ENT_INST              std::optional<ENT_INST>
	#define O_REL_TYPE              std::optional<REL_TYPE>
	#define O_REL_INST              std::optional<REL_INST>
	#define O_REL_ATTR_TYPE         std::optional<REL_ATTR_TYPE>
	#define O_REL_ATTR_INST         std::optional<REL_ATTR_INST>

}
}
