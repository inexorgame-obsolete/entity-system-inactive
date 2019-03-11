#pragma once

#include "type-system/providers/logical/NotEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using NotEntityTypeProviderPtr = std::shared_ptr<NotEntityTypeProvider>;

	/// The entity type providers for logical operations.
	class LogicalProviders
	{
		public:

			/// Constructs the entity type providers for logical operations.
			LogicalProviders(
				NotEntityTypeProviderPtr not_entity_type_provider
			);

			~LogicalProviders();

			/// Initializes the providers for logical operations.
			void init();

		private:

			/// Provides the entity type NOT.
			NotEntityTypeProviderPtr not_entity_type_provider;

	};

}
}
}
