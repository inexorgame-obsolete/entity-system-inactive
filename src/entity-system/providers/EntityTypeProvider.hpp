#pragma once

#include "TypeProvider.hpp"

#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"

namespace inexor {
namespace entity_system {

	typedef TypeProvider<EntityType, EntityTypeBuilderManager> EntityTypeProvider;

}
}
