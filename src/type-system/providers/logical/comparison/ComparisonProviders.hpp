#pragma once

#include "type-system/providers/logical/comparison/EqualsBoolEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/EqualsIntEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/EqualsStringEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/GreaterThanIntEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/GreaterThanFloatEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/LowerThanIntEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/LowerThanFloatEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/InRangeIntEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/InRangeFloatEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using EqualsBoolEntityTypeProviderPtr = std::shared_ptr<EqualsBoolEntityTypeProvider>;
	using EqualsIntEntityTypeProviderPtr = std::shared_ptr<EqualsIntEntityTypeProvider>;
	using EqualsStringEntityTypeProviderPtr = std::shared_ptr<EqualsStringEntityTypeProvider>;
	using GreaterThanIntEntityTypeProviderPtr = std::shared_ptr<GreaterThanIntEntityTypeProvider>;
	using GreaterThanFloatEntityTypeProviderPtr = std::shared_ptr<GreaterThanFloatEntityTypeProvider>;
	using LowerThanIntEntityTypeProviderPtr = std::shared_ptr<LowerThanIntEntityTypeProvider>;
	using LowerThanFloatEntityTypeProviderPtr = std::shared_ptr<LowerThanFloatEntityTypeProvider>;
	using InRangeIntEntityTypeProviderPtr = std::shared_ptr<InRangeIntEntityTypeProvider>;
	using InRangeFloatEntityTypeProviderPtr = std::shared_ptr<InRangeFloatEntityTypeProvider>;

	/// The entity type providers for comparison operations.
	class ComparisonProviders
	{
		public:

			/// Constructs the entity type providers for comparison operations.
			ComparisonProviders(
				EqualsBoolEntityTypeProviderPtr equals_bool_entity_type_provider,
				EqualsIntEntityTypeProviderPtr equals_int_entity_type_provider,
				EqualsStringEntityTypeProviderPtr equals_string_entity_type_provider,
				GreaterThanIntEntityTypeProviderPtr greater_than_int_entity_type_provider,
				GreaterThanFloatEntityTypeProviderPtr greater_than_float_entity_type_provider,
				LowerThanIntEntityTypeProviderPtr lower_than_int_entity_type_provider,
				LowerThanFloatEntityTypeProviderPtr lower_than_float_entity_type_provider,
				InRangeIntEntityTypeProviderPtr in_range_int_entity_type_provider,
				InRangeFloatEntityTypeProviderPtr in_range_float_entity_type_provider
			);

			~ComparisonProviders();

			/// Initializes the entity type providers for comparison operations.
			void init();

		private:

			/// Provides the entity type EQUALS_BOOL.
			EqualsBoolEntityTypeProviderPtr equals_bool_entity_type_provider;

			/// Provides the entity type EQUALS_INT.
			EqualsIntEntityTypeProviderPtr equals_int_entity_type_provider;

			/// Provides the entity type EQUALS_STRING.
			EqualsStringEntityTypeProviderPtr equals_string_entity_type_provider;

			/// Provides the entity type GREATER_THAN_INT.
			GreaterThanIntEntityTypeProviderPtr greater_than_int_entity_type_provider;

			/// Provides the entity type GREATER_THAN_FLOAT.
			GreaterThanFloatEntityTypeProviderPtr greater_than_float_entity_type_provider;

			/// Provides the entity type LOWER_THAN_INT.
			LowerThanIntEntityTypeProviderPtr lower_than_int_entity_type_provider;

			/// Provides the entity type LOWER_THAN_FLOAT.
			LowerThanFloatEntityTypeProviderPtr lower_than_float_entity_type_provider;

			/// Provides the entity type IN_RANGE_INT.
			InRangeIntEntityTypeProviderPtr in_range_int_entity_type_provider;

			/// Provides the entity type IN_RANGE_FLOAT.
			InRangeFloatEntityTypeProviderPtr in_range_float_entity_type_provider;

	};

}
}
}
