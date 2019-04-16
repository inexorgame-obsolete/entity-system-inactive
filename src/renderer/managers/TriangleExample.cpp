#include "TriangleExample.hpp"

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

#include <iomanip>

using namespace Magnum::Math::Literals;

namespace inexor {
namespace renderer {

	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityAttributeInstanceOpt = std::optional<EntityAttributeInstancePtr>;

	TriangleExample::TriangleExample(
		EntityInstanceManagerPtr entity_instance_manager,
		ConnectorManagerPtr connector_manager,
		CounterFloatFactoryPtr counter_float_factory,
		SinFactoryPtr sin_factory,
		CosFactoryPtr cos_factory,
		TriangleFactoryPtr triangle_factory,
		WindowManagerPtr window_manager,
		LogManagerPtr log_manager
	) {
		this->entity_instance_manager = entity_instance_manager;
		this->connector_manager = connector_manager;
		this->counter_float_factory = counter_float_factory;
		this->sin_factory = sin_factory;
		this->cos_factory = cos_factory;
		this->triangle_factory = triangle_factory;
		this->window_manager = window_manager;
		this->log_manager = log_manager;
		this->initialized = false;
	}

	TriangleExample::~TriangleExample()
	{
	}

	void TriangleExample::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		create_entity_instances();

		create_connectors();

		// Creates the window
		window = window_manager->create_window("Triangle Example", 0, 0, 800, 600, 1.0f, true, false, false, false, false);
		// The first render function is the initialization function which is executed only once
		window_manager->register_render_function(window, std::bind(&TriangleExample::create_mesh, this, std::placeholders::_1, std::placeholders::_2));
		// The second render function is for rendering the triangle
		window_manager->register_render_function(window, std::bind(&TriangleExample::render_triangle, this, std::placeholders::_1, std::placeholders::_2));
	}

	void TriangleExample::shutdown()
	{
		window_manager->destroy_window(window);
	}

	void TriangleExample::create_entity_instances()
	{
		spdlog::info("create_entity_instances");
		EntityInstancePtrOpt o_counter = counter_float_factory->create_instance(50, 0.1f);
		EntityInstancePtrOpt o_sin = sin_factory->create_instance();
		EntityInstancePtrOpt o_cos = cos_factory->create_instance();
		EntityInstancePtrOpt o_triangle = triangle_factory->create_instance(0.5f, -0.5f);

		if(o_counter.has_value() && o_sin.has_value() && o_cos.has_value() && o_triangle.has_value())
		{
			counter = o_counter.value();
			sin = o_sin.value();
			cos = o_cos.value();
			triangle = o_triangle.value();

			EntityAttributeInstanceOpt o_counter_attr_count = counter->get_attribute_instance(entity_system::type_system::CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT);
			EntityAttributeInstanceOpt o_sin_attr_input = sin->get_attribute_instance(entity_system::type_system::SinEntityTypeProvider::SIN_INPUT);
			EntityAttributeInstanceOpt o_sin_attr_value = sin->get_attribute_instance(entity_system::type_system::SinEntityTypeProvider::SIN_VALUE);
			EntityAttributeInstanceOpt o_cos_attr_input = cos->get_attribute_instance(entity_system::type_system::CosEntityTypeProvider::COS_INPUT);
			EntityAttributeInstanceOpt o_cos_attr_value = cos->get_attribute_instance(entity_system::type_system::CosEntityTypeProvider::COS_VALUE);
			EntityAttributeInstanceOpt o_triangle_attr_x = triangle->get_attribute_instance(TriangleEntityTypeProvider::TRIANGLE_X);
			EntityAttributeInstanceOpt o_triangle_attr_y = triangle->get_attribute_instance(TriangleEntityTypeProvider::TRIANGLE_Y);

			if(o_counter_attr_count.has_value() && o_sin_attr_value.has_value() && o_cos_attr_value.has_value() && o_triangle_attr_x.has_value() && o_triangle_attr_y.has_value())
			{
				counter_attr_count = o_counter_attr_count.value();
				sin_attr_input = o_sin_attr_input.value();
				sin_attr_value = o_sin_attr_value.value();
				cos_attr_input = o_cos_attr_input.value();
				cos_attr_value = o_cos_attr_value.value();
				triangle_attr_x = o_triangle_attr_x.value();
				triangle_attr_y = o_triangle_attr_y.value();
			}
			else
			{
				spdlog::get(LOGGER_NAME)->error("Failed to get attributes");
			}
		}
		else
		{
			spdlog::get(LOGGER_NAME)->error("Failed to create entity instances: SIN, COS, TRIANGLE");
		}

	}

	void TriangleExample::create_connectors()
	{
		spdlog::info("create_connectors");
		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_c_sin = connector_manager->create_connector(counter_attr_count, sin_attr_input);
		if(!connector_c_sin.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_c_sin");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_c_sin");
			connector_c_sin.value()->enable_debug();
		}

		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_c_cos = connector_manager->create_connector(counter_attr_count, cos_attr_input);
		if(!connector_c_cos.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_c_cos");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_c_cos");
			connector_c_cos.value()->enable_debug();
		}

		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_x = connector_manager->create_connector(sin_attr_value, triangle_attr_x);
		if(!connector_x.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_x");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_x");
			connector_x.value()->enable_debug();
		}

		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_y = connector_manager->create_connector(cos_attr_value, triangle_attr_y);
		if(!connector_y.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_y");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_y");
			connector_y.value()->enable_debug();
		}
	}

	void TriangleExample::create_mesh(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		if (!initialized)
		{
			spdlog::info("create_mesh");
			const TriangleVertex data[] {
				{{-0.5f, -0.5f}, 0xff0000_rgbf}, // Left vertex, red color
				{{ 0.5f, -0.5f}, 0x00ff00_rgbf}, // Right vertex, green color
				{{ 0.0f,  0.5f}, 0x0000ff_rgbf}  // Top vertex, blue color
			};
			// window_manager->make_current(window);
			buffer = std::make_shared<Magnum::GL::Buffer>();
			buffer->setData(data);
			mesh = std::make_shared<Magnum::GL::Mesh>();
			mesh->setPrimitive(Magnum::GL::MeshPrimitive::Triangles)
				.setCount(3)
				.addVertexBuffer(
					(*buffer),
					0,
					Magnum::Shaders::VertexColor2D::Position{},
					Magnum::Shaders::VertexColor2D::Color3{}
				);

			shader = std::make_shared<Magnum::Shaders::VertexColor2D>();

			initialized = true;
			spdlog::info("mesh initialized");
		}
	}

	void TriangleExample::render_triangle(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		// Get position from the entity instance
		// The entity instance is modified by the visual scripting system (see above!)
		float x = std::get<DataType::FLOAT>(triangle_attr_x->value.Value());
		float y = 0.0f - std::get<DataType::FLOAT>(triangle_attr_x->value.Value());

		// Create two transformation matrices
		Magnum::Matrix3 transformation_matrix_x = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(x));
		Magnum::Matrix3 transformation_matrix_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(y));

		// Apply both transformation matrices
		shader->setTransformationProjectionMatrix(transformation_matrix_x * transformation_matrix_y);

		// Set viewport
		Magnum::Vector2i framebufferSize;
		glfwGetFramebufferSize(glfw_window, &framebufferSize.x(), &framebufferSize.y());
		Magnum::GL::defaultFramebuffer.setViewport({ {}, framebufferSize });

		// Reset
		Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);

		// Render triangle
		mesh->draw((*shader));
	}

}
}
