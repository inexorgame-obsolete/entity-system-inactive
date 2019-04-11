#pragma once

#include <memory>
using namespace std;

namespace inexor {
namespace entity_system {

	#define ENT_ATTR_TYPE        shared_ptr<class EntityAttributeType>
	#define ENT_ATTR_INST        shared_ptr<class EntityAttributeInstance>
	#define ENT_TYPE             shared_ptr<class EntityType>
	#define ENT_INST             shared_ptr<class EntityInstance>
	#define REL_TYPE             shared_ptr<class RelationType>
	#define REL_INST             shared_ptr<class RelationInstance>
	#define REL_ATTR_TYPE        shared_ptr<class RelationAttributeType>
	#define REL_ATTR_INST        shared_ptr<class RelationAttributeInstance>

	#define O_ENT_ATTR_TYPE      optional<ENT_ATTR_TYPE>
	#define O_ENT_ATTR_INST      optional<ENT_ATTR_INST>
	#define O_ENT_TYPE           optional<ENT_TYPE>
	#define O_ENT_INST           optional<ENT_INST>
	#define O_REL_TYPE           optional<REL_TYPE>
	#define O_REL_INST           optional<REL_INST>
	#define O_REL_ATTR_TYPE      optional<REL_ATTR_TYPE>
	#define O_REL_ATTR_INST      optional<REL_ATTR_INST>

}
}
