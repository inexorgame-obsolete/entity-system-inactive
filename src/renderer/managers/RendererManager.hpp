#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/factories/trigonometric/SinFactory.hpp"
#include "type-system/factories/trigonometric/CosFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "renderer/factories/RendererFactory.hpp"

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using SinFactoryPtr = std::shared_ptr<entity_system::type_system::SinFactory>;
	using CosFactoryPtr = std::shared_ptr<entity_system::type_system::CosFactory>;
	using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
	using RendererFactoryPtr = std::shared_ptr<RendererFactory>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

	/// @class RendererManager
    /// @brief Management of the rendering.
    class RendererManager
    	: public std::enable_shared_from_this<RendererManager>
    {
		public:

			/// Constructor.
			RendererManager(
				EntityInstanceManagerPtr entity_instance_manager,
				SinFactoryPtr sin_factory,
				CosFactoryPtr cos_factory,
				ConnectorManagerPtr connector_manager,
				RendererFactoryPtr render_factory
			);

			/// Destructor.
			~RendererManager();

			/// Initialize renderer.
			void init();

			/// Starts the window thread.
			void start_window_thread(GLFWwindow *windows);

		private:

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The sin factory
			SinFactoryPtr sin_factory;

			/// The sin factory
			CosFactoryPtr cos_factory;

			/// The entity type provider
			RendererFactoryPtr renderer_factory;

			/// The connector manager
			ConnectorManagerPtr connector_manager;

			/// The renderer entity instance.
			EntityInstancePtr renderer;

			/// The sinus generator.
			EntityInstancePtr sin_x;

			/// The sinus generator.
			EntityInstancePtr cos_y;

			/// The attribute sin_value
			EntityAttributeInstancePtr sin_x_attr_value;

			/// The attribute cos_value
			EntityAttributeInstancePtr cos_y_attr_value;

			/// The attribute renderer_x
			EntityAttributeInstancePtr renderer_x_attr_value;

			/// The attribute renderer_x
			EntityAttributeInstancePtr renderer_y_attr_value;

    };

}
}
