#pragma once

#include "visual-scripting/processors/inout/logger/LoggerProcessor.hpp"

namespace inexor::visual_scripting {

using LoggerProcessorPtr = std::shared_ptr<LoggerProcessor>;

/// @class LoggerProcessors
/// @brief Management of the logger processors.
class LoggerProcessors : public LifeCycleComponent
{
    public:
    /// @brief Constructs the logger processors.
    /// @note The dependencies of this class will be injected automatically.
    /// @param logger_processor Processor for the entity type LOGGER.
    explicit LoggerProcessors(LoggerProcessorPtr logger_processor);

    /// Destructor.
    ~LoggerProcessors();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Processor for the entity type LOGGER.
    LoggerProcessorPtr logger_processor;
};

} // namespace inexor::visual_scripting
