// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/relations/relation-type-builder-manager/RelationTypeBuilderManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace entity_system {

	using AttributeList = unordered_map<string, DataType>;

	using FeatureList = unordered_map<string, EnumSet<Feature>>;

	/// @class RelationTypeProvider
    /// @brief Provides the entity type.
	class RelationTypeProvider
	{
		public:

			/// Constructor.
			RelationTypeProvider(
				shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager,
				string relation_type_name,
				AttributeList relation_type_attributes,
				FeatureList relation_type_attribute_features
			);

			/// Destructor.
			~RelationTypeProvider();

			/// Returns the relation type
			string get_type_name();

			/// Returns the relation type
			shared_ptr<RelationType> get_type();

		private:

			/// The relation type builder manager
			shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager;

			/// The relation type name
			string relation_type_name;

			/// The list of attributes of the relation type
			AttributeList relation_type_attributes;

			/// The list of attributes of the relation type
			FeatureList relation_type_attribute_features;

			/// The relation type
			shared_ptr<RelationType> relation_type;

			/// True, if the relation type has been created
			bool created;
	};


};
};
