#include "GlobalKeyProcessor.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor {
namespace input {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtr = std::shared_ptr<EntityAttributeInstance>;
	using EntityAttributeInstancePtrOptional = std::optional<EntityAttributeInstancePtr>;
	using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

	GlobalKeyProcessor::GlobalKeyProcessor(
		GlobalKeyEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		KeyboardInputManagerPtr keyboard_input_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  keyboard_input_manager(keyboard_input_manager),
		  log_manager(log_manager)
	{
	}

	GlobalKeyProcessor::~GlobalKeyProcessor()
	{
	}

	void GlobalKeyProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		keyboard_input_manager->register_on_key_changed(shared_from_this());
	}

	void GlobalKeyProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void GlobalKeyProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
	}

	void GlobalKeyProcessor::on_key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods)
	{
		if (global_key_signals.find(key) != global_key_signals.end())
		{
			spdlog::get(LOGGER_NAME)->debug("Signal GLOBAL_KEY {}", key);
			// Change both signals at the same time!
			DoTransaction<D>([this, key, action, mods] {
				global_key_signals[key]->action.Set(action);
				global_key_signals[key]->mods.Set(mods);
			});
		} else {
			spdlog::get(LOGGER_NAME)->trace("No signal for key code {}", key);
		}
	}

	void GlobalKeyProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor GLOBAL_KEY for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

        auto o_keycode = entity_instance->get_attribute_instance(GlobalKeyEntityTypeProvider::GLOBAL_KEY_KEYCODE);
		auto o_action = entity_instance->get_attribute_instance(GlobalKeyEntityTypeProvider::GLOBAL_KEY_ACTION);
		auto o_mods = entity_instance->get_attribute_instance(GlobalKeyEntityTypeProvider::GLOBAL_KEY_MODS);
		
        if(o_keycode.has_value() && o_action.has_value() && o_mods.has_value())
		{
        	EntityAttributeInstancePtr keycode = o_keycode.value();
			int key = std::get<DataType::INT>(o_keycode.value()->value.Value());
			spdlog::get(LOGGER_NAME)->debug("Reactively connect source signals for key code {} with entity attributes", key);
			GlobalKeySignalsPtr global_key_signals = get_or_create_global_key_signals(key);
			o_action.value()->signal_wrapper <<= global_key_signals->action;
			o_mods.value()->signal_wrapper <<= global_key_signals->mods;
		} else {
        	spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), GlobalKeyEntityTypeProvider::GLOBAL_KEY_KEYCODE, GlobalKeyEntityTypeProvider::GLOBAL_KEY_ACTION, GlobalKeyEntityTypeProvider::GLOBAL_KEY_MODS);
		}
	}

	GlobalKeySignalsPtr GlobalKeyProcessor::get_or_create_global_key_signals(int key)
	{
		if (global_key_signals.find(key) == global_key_signals.end())
		{
			spdlog::get(LOGGER_NAME)->debug("Create source signals for key code {}", key);
			global_key_signals[key] = std::make_shared<GlobalKeySignals>(key, MakeVar<D>(DataValue(0)), MakeVar<D>(DataValue(0)));
		}
		return global_key_signals[key];
	}

}
}
