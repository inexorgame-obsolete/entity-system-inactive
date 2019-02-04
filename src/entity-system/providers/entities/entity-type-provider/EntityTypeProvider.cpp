// Inexor entity system
// (c)2018 Inexor

#include "EntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	EntityTypeProvider::EntityTypeProvider(
		shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager,
		string entity_type_name,
		AttributeList entity_type_attributes,
		FeatureList entity_type_attribute_features
	)
	{
		this->entity_type_builder_manager = entity_type_builder_manager;
		this->entity_type_name = entity_type_name;
		this->entity_type_attributes = entity_type_attributes;
		this->entity_type_attribute_features = entity_type_attribute_features;
		this->created = false;
	}

	EntityTypeProvider::~EntityTypeProvider()
	{
	}

	string EntityTypeProvider::get_type_name()
	{
		return entity_type_name;

	}

	shared_ptr<EntityType> EntityTypeProvider::get_type()
	{
		if (!created) {
			shared_ptr<EntityTypeBuilder> builder = entity_type_builder_manager->get_builder();
			builder->name(entity_type_name);
			for (auto& attr : entity_type_attributes)
			{
				builder->attribute(attr.first, attr.second, entity_type_attribute_features[attr.first]);
			}
			O_ENT_TYPE o_entity_type = builder->build();
			if (o_entity_type.has_value())
			{
				entity_type = o_entity_type.value();
				created = true;
			}
		}
		return entity_type;
	}

}
}
