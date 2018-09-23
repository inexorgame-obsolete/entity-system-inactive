// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

#include "../../entity-manager/entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
using namespace inexor::entity_system;


TEST(Tests_EntityAttributeTypeInstance, get_entity_attribute_data_type)
{
	std::string ent_attr_name = "weight";
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_FLOAT;
	ENT_ATTR_TYPE vehicle_weight = CREATE_ENT_ATTR_TYPE(ent_attr_name, ent_attr_data_type);
	ASSERT_EQ(vehicle_weight->get_entity_attribute_data_type(), ent_attr_data_type);

	ENT_ATTR_TYPE_INSTANCE car_weight = CREATE_ENT_ATTR_TYPE_INSTANCE(vehicle_weight);
	ENT_ATTR_TYPE_INSTANCE bike_weight = CREATE_ENT_ATTR_TYPE_INSTANCE(vehicle_weight);
	ENT_ATTR_TYPE_INSTANCE boat_weight = CREATE_ENT_ATTR_TYPE_INSTANCE(vehicle_weight);
	ENT_ATTR_TYPE_INSTANCE airplane_weight = CREATE_ENT_ATTR_TYPE_INSTANCE(vehicle_weight);

	ASSERT_EQ(car_weight->get_entity_attribute_data_type(), ent_attr_data_type);
	ASSERT_EQ(bike_weight->get_entity_attribute_data_type(), ent_attr_data_type);
	ASSERT_EQ(boat_weight->get_entity_attribute_data_type(), ent_attr_data_type);
	ASSERT_EQ(airplane_weight->get_entity_attribute_data_type(), ent_attr_data_type);
}


TEST(Tests_EntityAttributeTypeInstance, get_entity_attribute_type_name)
{
	std::string ent_attr_name = "weight";
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_FLOAT;
	ENT_ATTR_TYPE new_ent_attr1 = CREATE_ENT_ATTR_TYPE(ent_attr_name, ent_attr_data_type);
	ASSERT_EQ(new_ent_attr1->get_entity_attribute_type_name(), ent_attr_name);

	ENT_ATTR_TYPE_INSTANCE new_ent_attr1_inst = CREATE_ENT_ATTR_TYPE_INSTANCE(new_ent_attr1);
	ASSERT_EQ(new_ent_attr1_inst->get_entity_attribute_data_type(), ent_attr_data_type);
	ASSERT_EQ(new_ent_attr1_inst->get_entity_attribute_type_name(), ent_attr_name);
}
