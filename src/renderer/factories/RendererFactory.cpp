// Inexor entity system
// (c)2018-2019 Inexor

#include "RendererFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
    namespace renderer {
        RendererFactory::RendererFactory(
			shared_ptr<RendererEntityTypeProvider> renderer_entity_type_provider,
			shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
			shared_ptr<EntityInstanceManager> entity_instance_manager
        )
        {
            this->renderer_entity_type_provider = renderer_entity_type_provider;
            this->entity_instance_builder_manager = entity_instance_builder_manager;
            this->entity_instance_manager = entity_instance_manager;
        }

        RendererFactory::~RendererFactory() {

        }

        O_ENT_INST RendererFactory::create_instance(float x, float y) {
            return this->entity_instance_builder_manager->get_builder()
				->type(this->renderer_entity_type_provider->get_type())
            	->attribute("renderer_x", x)
				->attribute("renderer_y", y)
                ->build();
        }

    };
};
