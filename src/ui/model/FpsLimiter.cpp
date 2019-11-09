#include "FpsLimiter.hpp"

#include <cmath>
#include <thread>

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/types/ui/Window.hpp"

namespace inexor::ui {

using Window = entity_system::type_system::Window;
using DataType = entity_system::DataType;

FpsLimiter::FpsLimiter(const EntityInstancePtr &window)
{
    this->window = window;
    this->timeline = std::make_shared<Magnum::Timeline>();
    this->vsync = window->get<DataType::BOOL>(Window::VSYNC);
    this->set_min_fps(50.0f);
    this->set_max_fps(70.0f);
    this->set_target_fps(window->get<DataType::FLOAT>(Window::FPS));
    this->last_lazy_update_frame = 0.0f;
    this->frame_id = 0;
    this->frame_rr = 0;
    // Initialize the fps history
    for (int i = 0; i < history_size; i++)
    {
        fps[i] = target_fps;
        deviation[i] = 0.0f;
        limit_duration[i] = 0.0f;
    }
}

FpsLimiter::~FpsLimiter() = default;

void FpsLimiter::start()
{
    timeline->start();
}

void FpsLimiter::stop()
{
    timeline->stop();
}

TimelinePtr FpsLimiter::get_timeline()
{
    return timeline;
}

void FpsLimiter::limit()
{
    timeline->nextFrame();

    frame_id++;

    // Collect FPS stats
    float previous_duration = timeline->previousFrameDuration();
    frame_rr = frame_id % history_size;
    fps[frame_rr] = 1.0f / previous_duration;
    deviation[frame_rr] = fps[frame_rr] - target_fps;

    if (!vsync)
    {
        // TODO: Calculate duration
        // Currently just set to 60fps
        limit_duration[frame_rr] = 1.0f / 60.0f;

        // Sleep for calculated duration (in seconds)
        std::this_thread::sleep_for(std::chrono::duration<float>(limit_duration[frame_rr]));
    } else
    {
        limit_duration[frame_rr] = 0.0f;
        // Don't sleep, it's vsync!
    }

    // Lazy update vsync and target_fps every second
    if (is_lazy_update_frame())
    {
        last_lazy_update_frame = timeline->previousFrameTime();

        update_vsync();
        update_fps();

        spdlog::debug("FPS {:03.2f} {:03.2f} TARGET {:03.2f} DEVIATION {:03.2f} {:03.2f} | DURATION {:.5f} TARGET {:.5f} NEXT {:.5f}", fps[frame_rr], get_mean_fps(), target_fps, deviation[frame_rr], get_mean_deviation(),
                      timeline->previousFrameDuration(), target_fps_duration, limit_duration[frame_rr]);
    }
}

bool FpsLimiter::is_lazy_update_frame()
{
    return timeline->previousFrameTime() - this->last_lazy_update_frame > 1.0f;
}

void FpsLimiter::update_vsync()
{
    bool vsync = window->get<DataType::BOOL>(Window::VSYNC);
    if (vsync != this->vsync)
    {
        spdlog::debug("window vsync is now {}", vsync ? "enabled" : "disabled");
        glfwSwapInterval(vsync ? 1 : 0);
        this->vsync = vsync;
    }
}

void FpsLimiter::update_fps()
{
    target_fps = window->get<DataType::FLOAT>(Window::FPS);
}

float FpsLimiter::get_last_fps()
{
    return fps[frame_rr];
}

float FpsLimiter::get_last_deviation()
{
    return deviation[frame_rr];
}

float FpsLimiter::get_mean_fps()
{
    float mean_fps = 0.0f;
    for (int i = 0; i < history_size; i++)
    {
        mean_fps += fps[i];
    }
    mean_fps /= (float)history_size;
    return mean_fps;
}

float FpsLimiter::get_mean_deviation()
{
    float mean_deviation = 0.0f;
    for (int i = 0; i < history_size; i++)
    {
        mean_deviation += deviation[i];
    }
    mean_deviation /= (float)history_size;
    return mean_deviation;
}

void FpsLimiter::set_min_fps(float min_fps)
{
    this->min_fps = min_fps;
}

float FpsLimiter::get_min_fps()
{
    return min_fps;
}

void FpsLimiter::set_max_fps(float max_fps)
{
    this->max_fps = max_fps;
}

float FpsLimiter::get_max_fps()
{
    return max_fps;
}

void FpsLimiter::set_target_fps(float target_fps)
{
    this->target_fps = target_fps;
    this->target_fps_duration = 1.0f / target_fps;
}

float FpsLimiter::get_target_fps()
{
    return target_fps;
}

} // namespace inexor::renderer
