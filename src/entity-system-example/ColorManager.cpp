// Inexor
// (c)2018-2019 Inexor

#include "ColorManager.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace entity_system {
namespace example {

	ColorManager::ColorManager(std::shared_ptr<EntitySystem> entity_system)
	{
		this->entity_system = entity_system;
		entity_type_color = entity_system->create_entity_type("COLOR");
		auto attribute_type_name = entity_system->create_entity_attribute_type("name", ENTSYS_DATA_TYPE_STRING);
		auto attribute_type_r = entity_system->create_entity_attribute_type("r", ENTSYS_DATA_TYPE_FLOAT);
		auto attribute_type_g = entity_system->create_entity_attribute_type("g", ENTSYS_DATA_TYPE_FLOAT);
		auto attribute_type_b = entity_system->create_entity_attribute_type("b", ENTSYS_DATA_TYPE_FLOAT);
		entity_type_color->link_attribute_type(attribute_type_name);
		entity_type_color->link_attribute_type(attribute_type_r);
		entity_type_color->link_attribute_type(attribute_type_g);
		entity_type_color->link_attribute_type(attribute_type_b);
		std::cout << "Created entity type COLOR" << std::endl;
	}

	
	ColorManager::~ColorManager()
	{
		// TODO: delete_entity_type should delete all instances of COLOR also
		entity_system->delete_entity_type(entity_type_color);
		colors.clear();
	}

	/// Creates a new color
	void ColorManager::create_color(string name , float r, float g, float b)
	{
		auto entity_instance = entity_system->create_entity_instance(entity_type_color);
		// TODO: entity_instance->set_attribute();
		this->colors[name] = entity_instance;
	}

	/// Deletes a color
	void ColorManager::delete_color(string name)
	{
		if (color_exists(name)) {
			// TODO: missing in API: entity_system->delete_entity_instance(this->colors[name]);
			colors.erase(name);
		}
	}

	/// Returns true, if the color exists for the given name.
	bool ColorManager::color_exists(string name)
	{
		return !(colors.end() == colors.find(name));
	}

	float ColorManager::r(string name)
	{
		// Long:
		// Detailed access to the attribute of the entity instance
		// auto entity_instance_attribute_r = entity_system->get_entity_attribute("r");
		// Detailed access to the value of the attribute of the entity instance
		// float value = entity_instance_attribute_r->get_value();

		// Short (comfortable access to the value of the entity attribute value):
		// return this->colors[name]["r"];
		return 0.0f;
	}

	float ColorManager::g(string name)
	{
		// return this->colors[name]["g"];
		return 0.0f;
	}

	float ColorManager::b(string name)
	{
		// return this->colors[name]["b"];
		return 0.0f;
	}

};
};
};
