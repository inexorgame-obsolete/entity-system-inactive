// Inexor entity system
// (c)2018-2019 Inexor

#include "BuilderManager.hpp"


namespace inexor {
namespace entity_system {


	BuilderManager::BuilderManager(
		shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager /*,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
		shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager,
		shared_ptr<RelationInstanceBuilderManager> relation_instance_builder_manager */
    )
    {
		this->entity_type_builder_manager = entity_type_builder_manager;
//		this->entity_instance_builder_manager = entity_instance_builder_manager;
//		this->relation_type_builder_manager = relation_type_builder_manager;
//		this->relation_instance_builder_manager = relation_instance_builder_manager;
    }


    BuilderManager::~BuilderManager()
    {
    }


};
};
