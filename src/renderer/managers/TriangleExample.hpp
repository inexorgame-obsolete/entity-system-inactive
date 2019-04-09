#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/factories/generators/counters/CounterFloatFactory.hpp"
#include "type-system/factories/math/trigonometric/SinFactory.hpp"
#include "type-system/factories/math/trigonometric/CosFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "renderer/factories/TriangleFactory.hpp"
#include "renderer/managers/WindowManager.hpp"
#include "logging/managers/LogManager.hpp"

#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Shaders/VertexColor.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Math/Matrix3.h>

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using CounterFloatFactoryPtr = std::shared_ptr<entity_system::type_system::CounterFloatFactory>;
	using SinFactoryPtr = std::shared_ptr<entity_system::type_system::SinFactory>;
	using CosFactoryPtr = std::shared_ptr<entity_system::type_system::CosFactory>;
	using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
	using TriangleFactoryPtr = std::shared_ptr<TriangleFactory>;
	using WindowManagerPtr = std::shared_ptr<WindowManager>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

	struct TriangleVertex {
		Magnum::Vector2 position;
		Magnum::Color3 color;
	};

	/// @class TriangleExample
	/// @brief Management of the rendering.
	class TriangleExample
	: public std::enable_shared_from_this<TriangleExample>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param entity_instance_manager The entity instance manager.
			/// @param connector_manager The connector manager.
			/// @param counter_float_factory The factory for creating entities of type COUNTER_FLOAT.
			/// @param sin_factory The factory for creating entities of type SIN.
			/// @param cos_factory The factory for creating entities of type COS.
			/// @param render_factory The factory for creating entities of type TRIANGLE.
			/// @param log_manager The log manager.
			TriangleExample(
				EntityInstanceManagerPtr entity_instance_manager,
				ConnectorManagerPtr connector_manager,
				CounterFloatFactoryPtr counter_float_factory,
				SinFactoryPtr sin_factory,
				CosFactoryPtr cos_factory,
				TriangleFactoryPtr render_factory,
				WindowManagerPtr window_manager,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~TriangleExample();

			/// Initialize triangle manager.
			void init();

			/// Shut down the triangle manager.
			void shutdown();

//			/// @brief Starts the window thread.
//			/// @param windows The GLFWwindow instance.
//			void start_window_thread(GLFWwindow *windows);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.triangleexample";

		private:

			void create_entity_instances();
			void create_connectors();
			void create_mesh(EntityInstancePtr, GLFWwindow*);

			/// Renders the triangle.
			void render_triangle(EntityInstancePtr, GLFWwindow*);

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

			/// The factory for creating entities of type TRIANGLE.
			TriangleFactoryPtr triangle_factory;

			/// The window manager
			WindowManagerPtr window_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The window entity instance.
			EntityInstancePtr window;

			/// The triangle entity instance.
			EntityInstancePtr triangle;

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

			/// The attribute triangle_x.
			EntityAttributeInstancePtr triangle_attr_x;

			/// The attribute triangle_x.
			EntityAttributeInstancePtr triangle_attr_y;

			std::shared_ptr<Magnum::GL::Buffer> buffer;
			std::shared_ptr<Magnum::GL::Mesh> mesh;
			std::shared_ptr<Magnum::Shaders::VertexColor2D> shader;

			bool initialized;

	};

}
}
