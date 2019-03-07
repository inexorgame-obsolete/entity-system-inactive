#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

namespace inexor {
namespace entity_system {

	using AttributeList = std::unordered_map<string, DataType>;
	using FeatureList = std::unordered_map<string, EnumSet<Feature>>;

	using string = std::string;


	class EntityTypeProvider
	{
		public:

			EntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager,
				string entity_type_name,
				AttributeList entity_type_attributes,
				FeatureList entity_type_attribute_features
			);

			~EntityTypeProvider();

			string get_type_name();

			std::shared_ptr<EntityType> get_type();

		private:

			std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager;

			string entity_type_name;

			AttributeList entity_type_attributes;

			FeatureList entity_type_attribute_features;

			std::shared_ptr<EntityType> entity_type;

			/// True, if the entity type has been created
			bool created;
	};


};
};
