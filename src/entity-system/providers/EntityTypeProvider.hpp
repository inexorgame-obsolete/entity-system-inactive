#pragma once

#include "TypeProvider.hpp"

#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	typedef TypeProvider<EntityType, EntityTypeBuilderFactory> EntityTypeProvider;

}
}
