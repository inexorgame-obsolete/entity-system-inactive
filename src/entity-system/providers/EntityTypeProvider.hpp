#pragma once

#include "TypeProvider.hpp"

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor::entity_system {

typedef TypeProvider<EntityType, EntityTypeBuilderFactory> EntityTypeProvider;

}
