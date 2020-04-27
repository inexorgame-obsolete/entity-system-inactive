#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/logical/comparison/EqualsBoolFactory.hpp"
#include "type-system/factories/logical/comparison/EqualsIntFactory.hpp"
#include "type-system/factories/logical/comparison/EqualsStringFactory.hpp"
#include "type-system/factories/logical/comparison/GreaterThanFloatFactory.hpp"
#include "type-system/factories/logical/comparison/GreaterThanIntFactory.hpp"
#include "type-system/factories/logical/comparison/InRangeFloatFactory.hpp"
#include "type-system/factories/logical/comparison/InRangeIntFactory.hpp"
#include "type-system/factories/logical/comparison/LowerThanFloatFactory.hpp"
#include "type-system/factories/logical/comparison/LowerThanIntFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using EqualsBoolPtr = std::shared_ptr<EqualsBoolFactory>;
using EqualsIntPtr = std::shared_ptr<EqualsIntFactory>;
using EqualsStringPtr = std::shared_ptr<EqualsStringFactory>;
using GreaterThanIntPtr = std::shared_ptr<GreaterThanIntFactory>;
using GreaterThanFloatPtr = std::shared_ptr<GreaterThanFloatFactory>;
using LowerThanIntPtr = std::shared_ptr<LowerThanIntFactory>;
using LowerThanFloatPtr = std::shared_ptr<LowerThanFloatFactory>;
using InRangeIntPtr = std::shared_ptr<InRangeIntFactory>;
using InRangeFloatPtr = std::shared_ptr<InRangeFloatFactory>;

/// @class ComparisonFactories
/// @brief The factories for comparison operations.
class ComparisonFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories for comparison operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param equals_bool_factory Factory for creating entity instances of type EQUALS_BOOL.
    /// @param equals_int_factory Factory for creating entity instances of type EQUALS_INT.
    /// @param equals_string_factory Factory for creating entity instances of type EQUALS_STRING.
    /// @param greater_than_int_factory Factory for creating entity instances of type GREATER_THAN_INT.
    /// @param greater_than_float_factory Factory for creating entity instances of type GREATER_THAN_FLOAT.
    /// @param lower_than_int_factory Factory for creating entity instances of type LOWER_THAN_INT.
    /// @param lower_than_float_factory Factory for creating entity instances of type LOWER_THAN_FLOAT.
    /// @param in_range_int_factory Factory for creating entity instances of type IN_RANGE_INT.
    /// @param in_range_float_factory Factory for creating entity instances of type IN_RANGE_FLOAT.
    ComparisonFactories(EqualsBoolPtr equals_bool_factory, EqualsIntPtr equals_int_factory, EqualsStringPtr equals_string_factory, GreaterThanIntPtr greater_than_int_factory, GreaterThanFloatPtr greater_than_float_factory,
                        LowerThanIntPtr lower_than_int_factory, LowerThanFloatPtr lower_than_float_factory, InRangeIntPtr in_range_int_factory, InRangeFloatPtr in_range_float_factory);

    /// Destructor.
    ~ComparisonFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity instances of type EQUALS_BOOL.
    EqualsBoolPtr equals_bool_factory;

    /// Factory for creating entity instances of type EQUALS_INT.
    EqualsIntPtr equals_int_factory;

    /// Factory for creating entity instances of type EQUALS_STRING.
    EqualsStringPtr equals_string_factory;

    /// Factory for creating entity instances of type GREATER_THAN_INT.
    GreaterThanIntPtr greater_than_int_factory;

    /// Factory for creating entity instances of type GREATER_THAN_FLOAT.
    GreaterThanFloatPtr greater_than_float_factory;

    /// Factory for creating entity instances of type LOWER_THAN_INT.
    LowerThanIntPtr lower_than_int_factory;

    /// Factory for creating entity instances of type LOWER_THAN_FLOAT.
    LowerThanFloatPtr lower_than_float_factory;

    /// Factory for creating entity instances of type IN_RANGE_INT.
    InRangeIntPtr in_range_int_factory;

    /// Factory for creating entity instances of type IN_RANGE_FLOAT.
    InRangeFloatPtr in_range_float_factory;
};

} // namespace inexor::entity_system::type_system
