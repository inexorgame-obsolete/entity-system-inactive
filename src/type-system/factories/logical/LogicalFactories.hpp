#pragma once

#include "type-system/factories/logical/NotFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using NotFactoryPtr = std::shared_ptr<NotFactory>;

	/// The trigonometric factories.
	class LogicalFactories
	{
		public:

			/// Constructs the factories for logical operations.
			LogicalFactories(
				NotFactoryPtr not_factory
			);

			~LogicalFactories();

			/// Initializes the factories for logical operations.
			void init();

		private:

			/// Factory for creating entity instances of type NOT.
			NotFactoryPtr not_factory;

	};

}
}
}
