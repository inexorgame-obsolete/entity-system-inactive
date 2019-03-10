#pragma once

#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using AddIntEntityTypeProviderPtr = std::shared_ptr<AddIntEntityTypeProvider>;

	/// The arithmetic entity type providers.
	class ArithmeticProviders
	{
		public:

			/// Constructs the arithmetic entity type providers.
			ArithmeticProviders(
				AddIntEntityTypeProviderPtr add_int_entity_type_provider
			);

			~ArithmeticProviders();

			/// Initializes the arithmetic entity type providers.
			void init();

		private:

			/// Provides the entity type ADD_INT.
			AddIntEntityTypeProviderPtr add_int_entity_type_provider;

	};

}
}
}
