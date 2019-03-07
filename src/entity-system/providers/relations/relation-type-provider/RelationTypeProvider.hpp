#pragma once

#include "entity-system/managers/relations/relation-type-builder-manager/RelationTypeBuilderManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {

	using AttributeList = std::unordered_map<std::string, DataType>;
	using FeatureList = std::unordered_map<std::string, EnumSet<Feature>>;

	using string = std::string;

	class RelationTypeProvider
	{
		public:
			RelationTypeProvider(
				shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager,
				string relation_type_name,
				AttributeList relation_type_attributes,
				FeatureList relation_type_attribute_features
			);

			~RelationTypeProvider();

			string get_type_name();

			std::shared_ptr<RelationType> get_type();

		private:

			std::shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager;

			string relation_type_name;

			AttributeList relation_type_attributes;

			FeatureList relation_type_attribute_features;

			std::shared_ptr<RelationType> relation_type;

			/// True, if the relation type has been created
			bool created;
	};


};
};
