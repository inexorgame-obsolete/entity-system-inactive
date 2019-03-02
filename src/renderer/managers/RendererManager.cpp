// Inexor entity system
// (C) 2018-2019 Inexor

#include "RendererManager.hpp"

namespace inexor {
    namespace renderer {
        RendererManager::RendererManager(
                shared_ptr<inexor::renderer::RendererFactory> render_factory,
                 shared_ptr<EntityInstanceManager> entity_instance_manager
         )
         {
            this->renderer_factory = render_factory;
            this->entity_instance_manager = entity_instance_manager;
         }

         RendererManager::~RendererManager()
         {

         }
    };
};