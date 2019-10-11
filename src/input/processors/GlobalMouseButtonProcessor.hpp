#pragma once

#include "Reactive.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "input/managers/MouseInputManager.hpp"
#include "type-system/providers/inout/mouse/GlobalMouseButtonEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"
#include "logging/managers/LogManager.hpp"

#include <list>

namespace inexor {
namespace input {

	/// Bundles the source signals of a specific mouse button.
	struct GlobalMouseButtonSignals {

		GlobalMouseButtonSignals(
			int mouse_button,
			VarSignalT<entity_system::DataValue> action,
			VarSignalT<entity_system::DataValue> mods
		) : button(button), action(action), mods(mods) {};

		int button;
		VarSignalT<entity_system::DataValue> action;
		VarSignalT<entity_system::DataValue> mods;

	};

	using GlobalMouseButtonSignalsPtr = std::shared_ptr<GlobalMouseButtonSignals>;

    /// @class GlobalMouseButtonProcessor
	/// @brief Processor for entity instances of type GLOBAL_MOUSE_BUTTON.
    class GlobalMouseButtonProcessor
    	: public visual_scripting::Processor,
		  public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public MouseButtonChangedListener,
		  public std::enable_shared_from_this<GlobalMouseButtonProcessor>
    {

    	using GlobalMouseButtonEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::GlobalMouseButtonEntityTypeProvider>;
    	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    	using MouseInputManagerPtr = std::shared_ptr<MouseInputManager>;
    	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
    	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

		public:

    		/// @brief Constructs a new entity instance of type GLOBAL_MOUSE_BUTTON.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type GLOBAL_MOUSE_BUTTON.
            /// @param entity_instance_manager The entity instance manager.
            /// @param logger_manager The log manager.
			GlobalMouseButtonProcessor(
				GlobalMouseButtonEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager,
				MouseInputManagerPtr mouse_input_manager,
				LogManagerPtr log_manager
			);

            /// Destructor.
			~GlobalMouseButtonProcessor();

			/// Initialization of the processor.
			void init();

			/// @brief Called when an entity instance of type GLOBAL_MOUSE_BUTTON has been created.
            /// @param entity_instance An entity instance of type 'GLOBAL_MOUSE_BUTTON'.
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// @brief Called when an entity instance of type GLOBAL_MOUSE_BUTTON has been deleted.
            /// @param type_GUID ?
            /// @param inst_GUID ?
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// @brief Called when the state of a mouse button has been changed.
            /// @param window An entity instance of type 'WINDOW'.
            /// @param button The button number.
            /// @param action The button action (pressed, released).
            /// @param mods The modifier keys (shift, ctrl).
			void on_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods);

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.input.processor.globalmousebutton";

		private:

			/// @brief Creates a signal for the given button number.
            /// @param button The button number.
			GlobalMouseButtonSignalsPtr get_or_create_global_mouse_button_signals(int button);

			/// @brief Creates the processor signals for the given entity instance.
            /// @param entity_instance The entity instance of type GLOBAL_MOUSE_BUTTON.
			void make_signals(const EntityInstancePtr& entity_instance);

			/// Provides the entity type GLOBAL_MOUSE_BUTTON.
			GlobalMouseButtonEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The mouse input manager.
			MouseInputManagerPtr mouse_input_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, ObserverT> observers;

			/// Each button number has a base signal.
			std::unordered_map<int, GlobalMouseButtonSignalsPtr> global_mouse_button_signals;

    };

}
}
