#pragma once

#include "TypeProvider.hpp"

#include "entity-system/model/relations/relation-types/RelationType.hpp"
#include "entity-system/factories/relations/relation-type-builder-factory/RelationTypeBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	typedef TypeProvider<RelationType, RelationTypeBuilderFactory> RelationTypeProvider;

}
}
