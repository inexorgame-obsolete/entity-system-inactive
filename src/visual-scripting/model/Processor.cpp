#include <visual-scripting/processors/Processors.hpp>

#include <utility>

namespace inexor::visual_scripting {

Processor::Processor() = default;

Processor::Processor(EntityTypePtr entity_type) : entity_type(std::move(entity_type))
{
}

Processor::~Processor() = default;

EntityTypePtr Processor::get_entity_type()
{
    return entity_type;
}

} // namespace inexor::visual_scripting
