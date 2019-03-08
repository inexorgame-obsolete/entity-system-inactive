#pragma once

#include "TypeProvider.hpp"

#include "entity-system/model/relations/relation-types/RelationType.hpp"
#include "entity-system/managers/relations/relation-type-builder-manager/RelationTypeBuilderManager.hpp"

namespace inexor {
namespace entity_system {

	typedef TypeProvider<RelationType, RelationTypeBuilderManager> RelationTypeProvider;

}
}
