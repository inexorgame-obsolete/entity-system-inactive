#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

#include <Magnum/Timeline.h>

#include <memory>

namespace inexor {
namespace renderer {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using TimelinePtr = std::shared_ptr<Magnum::Timeline>;

	/// @class FpsLimiter
	/// @brief Limits the frames per second of a specific window.
	/// @todo This is no manager, so move it to another src dir
	class FpsLimiter {

		public:

			/// Constructs a fps limiter for the given window.
			/// @param window The entity instance of type 'WINDOW'.
			FpsLimiter(const EntityInstancePtr& window);

			/// Destructs the fps limiter.
			~FpsLimiter();

			/// Starts the time line.
			void start();

			/// Stops the time line.
			void stop();

			/// Returns the time line.
			TimelinePtr get_timeline();

			/// Limits the frame.
			void limit();

			/// Returns the last frames per second.
			float get_last_fps();

			/// Returns the last deviation in frames per seconds.
			float get_last_deviation();

			/// Returns the mean frames per second.
			float get_mean_fps();

			/// Returns the mean deviation in frames per seconds.
			float get_mean_deviation();

			/// Sets the minimum frames per second.
			/// @param min_fps The minimum fps.
			void set_min_fps(float min_fps);

			/// Returns the minimum frames per second.
			float get_min_fps();

			/// Sets the maximum frames per second.
			/// @param max_fps The maximum fps.
			void set_max_fps(float max_fps);

			/// Returns the maximum frames per second.
			float get_max_fps();

			/// Sets the target frames per second.
			/// @param target_fps The target fps.
			void set_target_fps(float target_fps);

			/// Returns the target frames per second.
			float get_target_fps();

		private:

			/// Returns true, if the current frame is a lazy update frame.
			bool is_lazy_update_frame();

			/// Updates the vsync state by the vsync attribute of the entity instance.
			void update_vsync();

			/// Updates the frames per second by the fps attribute of the entity instance.
			void update_fps();


			/// The entity instance of type 'WINDOW'.
			EntityInstancePtr window;

			/// The time line.
			TimelinePtr timeline;


			// Settings


			/// The minimum frames per second.
			float min_fps;

			/// The maximum frames per second.
			float max_fps;

			/// The target frames per second.
			float target_fps;

			/// The target frame duration.
			float target_fps_duration;

			/// If true, vertical synchronization is enabled.
			bool vsync;

			/// The frame time of the last lazy update frame.
			float last_lazy_update_frame;


			// History data


			/// The history size.
			static const int history_size = 10;

			/// The frame id.
			int frame_id;

			/// The current round robin index.
			int frame_rr;

			/// The FPS history.
			float fps[history_size];

			/// The deviation history.
			float deviation[history_size];

			/// The limit duration history.
			float limit_duration[history_size];

	};

}
}
