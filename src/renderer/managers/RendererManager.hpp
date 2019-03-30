#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/factories/generators/counters/CounterFloatFactory.hpp"
#include "type-system/factories/math/trigonometric/SinFactory.hpp"
#include "type-system/factories/math/trigonometric/CosFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "renderer/factories/RendererFactory.hpp"
#include "logging/managers/LogManager.hpp"
#include "keyboard/managers/KeyboardInputManager.hpp"
#include "mouse/managers/MouseInputManager.hpp"

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using CounterFloatFactoryPtr = std::shared_ptr<entity_system::type_system::CounterFloatFactory>;
	using SinFactoryPtr = std::shared_ptr<entity_system::type_system::SinFactory>;
	using CosFactoryPtr = std::shared_ptr<entity_system::type_system::CosFactory>;
	using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
	using RendererFactoryPtr = std::shared_ptr<RendererFactory>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using KeyboardInputManagerPtr = std::shared_ptr<inexor::input::keyboard::KeyboardInputManager>;
	using MouseInputManagerPtr = std::shared_ptr<inexor::input::mouse::MouseInputManager>;

	/// @class RendererManager
	/// @brief Management of the rendering.
	class RendererManager
	: public std::enable_shared_from_this<RendererManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param entity_instance_manager The entity instance manager.
			/// @param connector_manager The connector manager.
			/// @param counter_float_factory The factory for creating entities of type COUNTER_FLOAT.
			/// @param sin_factory The factory for creating entities of type SIN.
			/// @param cos_factory The factory for creating entities of type COS.
			/// @param render_factory The factory for creating entities of type RENDERER.
			/// @param log_manager The log manager.
			/// @param keyboard_input_manager The keyboard input manager.
			/// @param mouse_input_manager The mouse input manager.
			RendererManager(
				EntityInstanceManagerPtr entity_instance_manager,
				ConnectorManagerPtr connector_manager,
				CounterFloatFactoryPtr counter_float_factory,
				SinFactoryPtr sin_factory,
				CosFactoryPtr cos_factory,
				RendererFactoryPtr render_factory,
				LogManagerPtr log_manager,
				KeyboardInputManagerPtr keyboard_input_manager,
				MouseInputManagerPtr mouse_input_manager
			);

			/// Destructor.
			~RendererManager();

			/// Initialize renderer.
			void init();

			/// @brief Starts the window thread.
			/// @param windows The GLFWwindow instance.
			void start_window_thread(GLFWwindow *windows);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.r.manager";

		private:

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The connector manager.
			ConnectorManagerPtr connector_manager;

			/// The factory for creating entities of type COUNTER_FLOAT.
			CounterFloatFactoryPtr counter_float_factory;

			/// The factory for creating entities of type SIN.
			SinFactoryPtr sin_factory;

			/// The factory for creating entities of type COS.
			CosFactoryPtr cos_factory;

			/// The factory for creating entities of type RENDERER.
			RendererFactoryPtr renderer_factory;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The keyboard input manager.
			KeyboardInputManagerPtr keyboard_input_manager;

			/// The mouse input manager.
			MouseInputManagerPtr mouse_input_manager;

			/// The renderer entity instance.
			EntityInstancePtr renderer;

			/// The counter.
			EntityInstancePtr counter;

			/// The sin operator.
			EntityInstancePtr sin;

			/// The cos operator.
			EntityInstancePtr cos;

			/// The attribute sin_input.
			EntityAttributeInstancePtr counter_attr_count;

			/// The attribute sin_input.
			EntityAttributeInstancePtr sin_attr_input;

			/// The attribute sin_value.
			EntityAttributeInstancePtr sin_attr_value;

			/// The attribute cos_input.
			EntityAttributeInstancePtr cos_attr_input;

			/// The attribute cos_value.
			EntityAttributeInstancePtr cos_attr_value;

			/// The attribute renderer_x.
			EntityAttributeInstancePtr renderer_attr_x;

			/// The attribute renderer_x.
			EntityAttributeInstancePtr renderer_attr_y;

	};

}
}
