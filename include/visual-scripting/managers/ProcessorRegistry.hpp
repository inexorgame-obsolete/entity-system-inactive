#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "visual-scripting/model/Processor.hpp"

#include <crossguid/guid.hpp>
#include <optional>

namespace inexor::visual_scripting {

using ProcessorPtr = std::shared_ptr<Processor>;
using ProcessorPtrOpt = std::optional<ProcessorPtr>;
using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

/// @class ProcessorRegistry
/// @brief Registry of the visual scripting processors.
class ProcessorRegistry : public LifeCycleComponent
{
    public:
    /// Constructor.
    ProcessorRegistry();

    /// Destructor.
    ~ProcessorRegistry();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// @brief Registers an processor.
    /// @param processor ?
    void register_processor(const ProcessorPtr &processor);

    /// @brief Returns the processor by entity type.
    /// @param entity_type ?
    ProcessorPtrOpt get_processor(const EntityTypePtr &entity_type);

    /// @brief Returns true, if a processor is mapped to the given entity type.
    /// @param entity_type ?
    bool has_processor(const EntityTypePtr &entity_type);

    private:
    /// Stores the processors per entity type.
    std::unordered_map<EntityTypePtr, ProcessorPtr> processors;
};

} // namespace inexor::visual_scripting
