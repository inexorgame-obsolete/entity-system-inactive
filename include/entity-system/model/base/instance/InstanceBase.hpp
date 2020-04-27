#pragma once

#include <memory>
#include <mutex>
#include <string>

namespace inexor::entity_system {

/// @class InstanceBase
/// @brief A template base class for instances.
/// @param T The type of the instance.
template <typename T> class InstanceBase
{
    private:
    /// A shared pointer to the type of this instance.
    std::shared_ptr<T> type_pointer;

    /// The mutex of this class.
    std::mutex instance_base_mutex;

    protected:
    /// @brief Returns a shared pointer to the underlying type of this instance.
    /// @return A shared pointer to the underlying type of this instance.
    std::shared_ptr<T> get_type() const
    {
        // No mutex required as this is a read-only operation.
        return type_pointer;
    }

    public:
    /// @brief Constructor.
    /// @param type_ptr A shared pointer to the underlying type of this instance.
    explicit InstanceBase(const std::shared_ptr<T> &type_ptr)
    {
        // Use lock guard to ensure thread safety during write operations!
        std::lock_guard<std::mutex> lock(instance_base_mutex);

        type_pointer = type_ptr;
    }

    /// @brief Destructor.
    ~InstanceBase() = default;
};

} // namespace inexor::entity_system
