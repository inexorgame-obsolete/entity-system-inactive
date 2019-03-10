#pragma once

#include "type-system/providers/constants/BoolConstantEntityTypeProvider.hpp"
#include "type-system/providers/constants/FloatConstantEntityTypeProvider.hpp"
#include "type-system/providers/constants/IntConstantEntityTypeProvider.hpp"
#include "type-system/providers/constants/StringConstantEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using BoolConstantEntityTypeProviderPtr = std::shared_ptr<BoolConstantEntityTypeProvider>;
//	using FloatConstantEntityTypeProviderPtr = std::shared_ptr<FloatConstantEntityTypeProvider>;
//	using IntConstantEntityTypeProviderPtr = std::shared_ptr<IntConstantEntityTypeProvider>;
//	using StringConstantEntityTypeProviderPtr = std::shared_ptr<StringConstantEntityTypeProvider>;

	/// The constant entity type providers.
	class ConstantProviders
	{
		public:

			/// Constructs the constant entity type providers.
			ConstantProviders(
				BoolConstantEntityTypeProviderPtr bool_constant_entity_type_provider
//				FloatConstantEntityTypeProvider float_constant_entity_type_provider,
//				IntConstantEntityTypeProvider int_constant_entity_type_provider,
//				StringConstantEntityTypeProvider string_constant_entity_type_provider
			);

			~ConstantProviders();

			/// Initializes the constant entity type providers.
			void init();

		private:

			/// Provides the entity type BOOL_CONSTANT.
			BoolConstantEntityTypeProviderPtr bool_constant_entity_type_provider;

//			/// Provides the entity type FLOAT_CONSTANT.
//			FloatConstantEntityTypeProvider float_constant_entity_type_provider;
//
//			/// Provides the entity type INT_CONSTANT.
//			IntConstantEntityTypeProvider int_constant_entity_type_provider;
//
//			/// Provides the entity type STRING_CONSTANT.
//			StringConstantEntityTypeProvider string_constant_entity_type_provider;

	};

}
}
}
