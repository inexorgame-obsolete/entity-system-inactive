// Inexor entity system
// (c)2018-2019 Inexor

#include "RendererFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
    namespace renderer {
        RendererFactory::RendererFactory(
                shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
                shared_ptr<EntityInstanceManager> entity_instance_manager
        )
        {
            this->entity_instance_builder_manager = entity_instance_builder_manager;
            this->entity_instance_manager = entity_instance_manager;
        }

        RendererFactory::~RendererFactory() {

        }

        O_ENT_INST RendererFactory::create_instance() {
            return this->entity_instance_builder_manager->get_builder()
                ->build();
        }
    };
};
