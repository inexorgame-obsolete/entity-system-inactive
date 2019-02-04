// Inexor entity system
// (c)2018 Inexor

#include "RelationTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	RelationTypeProvider::RelationTypeProvider(
		shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager,
		string relation_type_name,
		AttributeList relation_type_attributes,
		FeatureList relation_type_attribute_features
	)
	{
		this->relation_type_builder_manager = relation_type_builder_manager;
		this->relation_type_name = relation_type_name;
		this->relation_type_attributes = relation_type_attributes;
		this->relation_type_attribute_features = relation_type_attribute_features;
		this->created = false;
	}

	RelationTypeProvider::~RelationTypeProvider()
	{
	}

	string RelationTypeProvider::get_type_name()
	{
		return relation_type_name;

	}

	shared_ptr<RelationType> RelationTypeProvider::get_type()
	{
		if (!created) {
			shared_ptr<RelationTypeBuilder> builder = relation_type_builder_manager->get_builder();
			builder->name(relation_type_name);
			for (auto& attr : relation_type_attributes)
			{
				builder->attribute(attr.first, attr.second, relation_type_attribute_features[attr.first]);
			}
			O_REL_TYPE o_relation_type = builder->build();
			if (o_relation_type.has_value())
			{
				relation_type = o_relation_type.value();
				created = true;
			}
		}
		return relation_type;
	}

}
}
