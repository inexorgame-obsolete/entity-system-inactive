#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor {
namespace renderer {

	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// @class ScreenshotManager
	/// @brief Service for making screenshots.
	class ScreenshotManager
	: public std::enable_shared_from_this<ScreenshotManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param log_manager The log manager.
			ScreenshotManager(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~ScreenshotManager();

			/// Initialize the font manager.
			void init();

			/// Shut down the font manager.
			void shutdown();

			/// Creates a screenshot.
			void create_screenshot();

//			/// Creates a screenshot.
//			void create_screenshot(std::string filename);

//			/// Sequence
//			void screenshot_sequence(std::string filename, int sequence_number);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.screenshot";

		private:

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
