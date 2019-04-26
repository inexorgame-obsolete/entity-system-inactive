#include "ClipboardManager.hpp"

#include "type-system/providers/data/constants/StringConstantEntityTypeProvider.hpp"

#include "react/Signal.h"

#include "spdlog/spdlog.h"

#include <GLFW/glfw3.h>

namespace inexor {
namespace input {

	using StringConstant = entity_system::type_system::StringConstantEntityTypeProvider;

	ClipboardManager::ClipboardManager(
		StringConstantFactoryPtr string_constant_factory,
		LogManagerPtr log_manager
	) {
		this->string_constant_factory = string_constant_factory;
		this->log_manager = log_manager;
		this->set_on_next_update = std::nullopt;
	}

	ClipboardManager::~ClipboardManager()
	{
	}

	void ClipboardManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		this->clipboard = string_constant_factory->create_instance(CONSTANT_NAME).value();
	}

	void ClipboardManager::shutdown()
	{
		// TODO: remove entity instance.
	}

	std::string to_string(const char* s)
	{
	    return s ? std::string(s) : std::string("");
	}

	void ClipboardManager::update()
	{
		if (set_on_next_update.has_value())
		{
			glfwSetClipboardString(nullptr, set_on_next_update.value().c_str());
			clipboard->get_attribute_instance(StringConstant::STRING_CONSTANT_VALUE).value()->own_value.Set(set_on_next_update.value());
			this->set_on_next_update = std::nullopt;
			last_update = std::chrono::system_clock::now();;
		} else {
			std::chrono::duration<double> diff = std::chrono::system_clock::now() - last_update;
			if (diff.count() > 0.2) {
				clipboard->get_attribute_instance(StringConstant::STRING_CONSTANT_VALUE).value()->own_value.Set(to_string(glfwGetClipboardString(nullptr)));
				last_update = std::chrono::system_clock::now();;
			}
		}
	}

	void ClipboardManager::set(std::string text)
	{
		spdlog::info("-> set clipboard '{}'", text);
		set_on_next_update = { text };
	}

	EntityInstancePtr ClipboardManager::get()
	{
		return clipboard;
	}

	std::string ClipboardManager::get_value()
	{
		return clipboard->get<entity_system::DataType::STRING>(StringConstant::STRING_CONSTANT_VALUE);
	}

}
}
