#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "type-system/factories/data/constants/StringConstantFactory.hpp"

namespace inexor {
namespace input {

	using LogManagerPtr = std::shared_ptr<logging::LogManager>;

	using StringConstantFactoryPtr = std::shared_ptr<entity_system::type_system::StringConstantFactory>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class ClipboardManager
	/// @brief The ClipboardManager provides access to the system clipboard.
	///
	/// The clipboard is available as entity instance of type STRING_CONSTANT.
	///
	class ClipboardManager
		: public std::enable_shared_from_this<ClipboardManager>
	{
		public:

			/// @brief Constructs the manager service for the system clipboard.
			/// @note The dependencies of this class will be injected automatically.
			/// @param string_constant_factory Factory for creating string constants.
			/// @param log_manager The log manager.
			ClipboardManager(
				StringConstantFactoryPtr string_constant_factory,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~ClipboardManager();

			/// Initializes the clipboard manager.
			void init();

			/// Shut down the clipboard manager.
			void shutdown();

			/// Updates the entity instance. This should be done periodically.
			void update();

			/// Sets the contents of the system clipboard.
			void set(std::string text);

			/// Returns the entity instance which represents the system clipboard.
			EntityInstancePtr get();

			/// Returns the contents of the system clipboard.
			std::string get_value();

			/// The name of the string constant.
			static constexpr char CONSTANT_NAME[] = "CLIPBOARD";

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.input.clipboard";

		private:

			/// Factory for creating string constants.
			StringConstantFactoryPtr string_constant_factory;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The entity instance which represents the system clipboard.
			EntityInstancePtr clipboard;

			std::optional<std::string> set_on_next_update;

			std::chrono::time_point<std::chrono::system_clock> last_update;

	};

}
}
