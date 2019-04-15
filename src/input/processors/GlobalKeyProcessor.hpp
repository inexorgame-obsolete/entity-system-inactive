#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "input/managers/KeyboardInputManager.hpp"
#include "type-system/providers/inout/keyboard/GlobalKeyEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"
#include "logging/managers/LogManager.hpp"

#include <list>

namespace inexor {
namespace input {

	using namespace react;

    ///
	USING_REACTIVE_DOMAIN(entity_system::D)

	/// Bundles the source signals of a specific key code.
	struct GlobalKeySignals {

		GlobalKeySignals(
			int key,
			VarSignalT<entity_system::DataValue> action,
			VarSignalT<entity_system::DataValue> mods
		) : key(key), action(action), mods(mods) {};

		int key;
		VarSignalT<entity_system::DataValue> action;
		VarSignalT<entity_system::DataValue> mods;

	};

	using GlobalKeySignalsPtr = std::shared_ptr<GlobalKeySignals>;

    /// @class GlobalKeyProcessor
	/// @brief Processor for entity instances of type GLOBAL_KEY.
    class GlobalKeyProcessor
    	: public visual_scripting::Processor,
		  public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public KeyChangedListener,
		  public std::enable_shared_from_this<GlobalKeyProcessor>
    {

    	using GlobalKeyEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::GlobalKeyEntityTypeProvider>;
    	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    	using KeyboardInputManagerPtr = std::shared_ptr<KeyboardInputManager>;
    	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
    	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

		public:

    		/// @brief Constructs a new entity instance of type GLOBAL_KEY.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type GLOBAL_KEY.
            /// @param entity_instance_manager The entity instance manager.
            /// @param logger_manager The log manager.
			GlobalKeyProcessor(
				GlobalKeyEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager,
				KeyboardInputManagerPtr keyboard_input_manager,
				LogManagerPtr log_manager
			);

            /// Destructor.
			~GlobalKeyProcessor();

			/// Initialization of the processor.
			void init();

			/// @brief Called when an entity instance of type GLOBAL_KEY has been created.
            /// @param entity_instance ?
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// @brief Called when an entity instance of type GLOBAL_KEY has been deleted.
            /// @param type_GUID ?
            /// @param inst_GUID ?
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// @brief Called when the state of a key has been changed.
            /// @param window ?
            /// @param key ?
            /// @param scancode ?
            /// @param action ?
            /// @param mods ?
			void on_key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods);

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.input.processor.globalkey";

		private:

			/// @brief Creates a signal for the given key code.
            /// @param key The key code.
			GlobalKeySignalsPtr get_or_create_global_key_signals(int key);

			/// @brief Creates the processor signals for the given entity instance.
            /// @param entity_instance The entity instance of type GLOBAL_KEY.
			void make_signals(const EntityInstancePtr& entity_instance);

			/// Provides the entity type GLOBAL_KEY.
			GlobalKeyEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The keyboard input manager.
			KeyboardInputManagerPtr keyboard_input_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, ObserverT> observers;

			/// Each key code has a base signal.
			std::unordered_map<int, GlobalKeySignalsPtr> global_key_signals;

    };

}
}
