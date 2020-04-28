#include <type-system/factories/logical/comparison/ComparisonFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

ComparisonFactories::ComparisonFactories(EqualsBoolPtr equals_bool_factory, EqualsIntPtr equals_int_factory, EqualsStringPtr equals_string_factory, GreaterThanIntPtr greater_than_int_factory, GreaterThanFloatPtr greater_than_float_factory,
                                         LowerThanIntPtr lower_than_int_factory, LowerThanFloatPtr lower_than_float_factory, InRangeIntPtr in_range_int_factory, InRangeFloatPtr in_range_float_factory)
    : LifeCycleComponent(equals_bool_factory, equals_int_factory, equals_string_factory,
                         greater_than_int_factory, greater_than_float_factory,
                         lower_than_int_factory, lower_than_float_factory,
                         in_range_int_factory, in_range_float_factory)
{
    this->equals_bool_factory = std::move(equals_bool_factory);
    this->equals_int_factory = std::move(equals_int_factory);
    this->equals_string_factory = std::move(equals_string_factory);
    this->greater_than_int_factory = std::move(greater_than_int_factory);
    this->greater_than_float_factory = std::move(greater_than_float_factory);
    this->lower_than_int_factory = std::move(lower_than_int_factory);
    this->lower_than_float_factory = std::move(lower_than_float_factory);
    this->in_range_int_factory = std::move(in_range_int_factory);
    this->in_range_float_factory = std::move(in_range_float_factory);
}

ComparisonFactories::~ComparisonFactories() = default;

std::string ComparisonFactories::get_component_name()
{
    return "ComparisonFactories";
}

} // namespace inexor::entity_system::type_system
