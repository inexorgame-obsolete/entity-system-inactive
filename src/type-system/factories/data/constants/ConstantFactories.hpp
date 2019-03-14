#pragma once

#include "type-system/factories/data/constants/BoolConstantFactory.hpp"
#include "type-system/factories/data/constants/FloatConstantFactory.hpp"
#include "type-system/factories/data/constants/IntConstantFactory.hpp"
#include "type-system/factories/data/constants/StringConstantFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using BoolConstantFactoryPtr = std::shared_ptr<BoolConstantFactory>;
	using FloatConstantFactoryPtr = std::shared_ptr<FloatConstantFactory>;
	using IntConstantFactoryPtr = std::shared_ptr<IntConstantFactory>;
	using StringConstantFactoryPtr = std::shared_ptr<StringConstantFactory>;

	/// The constant factories.
	class ConstantFactories
	{
		public:

			/// Constructs the constant factories.
			ConstantFactories(
				BoolConstantFactoryPtr bool_constant_factory,
				FloatConstantFactoryPtr float_constant_factory,
				IntConstantFactoryPtr int_constant_factory,
				StringConstantFactoryPtr string_constant_factory
			);

			~ConstantFactories();

			/// Initializes the constant factories.
			void init();

		private:

			/// Factory for creating entity instances of type BOOL_CONSTANT.
			BoolConstantFactoryPtr bool_constant_factory;

			/// Factory for creating entity instances of type FLOAT_CONSTANT.
			FloatConstantFactoryPtr float_constant_factory;

			/// Factory for creating entity instances of type INT_CONSTANT.
			IntConstantFactoryPtr int_constant_factory;

			/// Factory for creating entity instances of type STRING_CONSTANT.
			StringConstantFactoryPtr string_constant_factory;

	};

}
}
}
