#pragma once

#include "type-system/providers/logical/NotEntityTypeProvider.hpp"
#include "type-system/providers/logical/OrEntityTypeProvider.hpp"
#include "type-system/providers/logical/AndEntityTypeProvider.hpp"
#include "type-system/providers/logical/XorEntityTypeProvider.hpp"
#include "type-system/providers/logical/NorEntityTypeProvider.hpp"
#include "type-system/providers/logical/NandEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using NotEntityTypeProviderPtr = std::shared_ptr<NotEntityTypeProvider>;
	using OrEntityTypeProviderPtr = std::shared_ptr<OrEntityTypeProvider>;
	using AndEntityTypeProviderPtr = std::shared_ptr<AndEntityTypeProvider>;
	using XorEntityTypeProviderPtr = std::shared_ptr<XorEntityTypeProvider>;
	using NorEntityTypeProviderPtr = std::shared_ptr<NorEntityTypeProvider>;
	using NandEntityTypeProviderPtr = std::shared_ptr<NandEntityTypeProvider>;

	/// The entity type providers for logical operations.
	class LogicalProviders
	{
		public:

			/// Constructs the entity type providers for logical operations.
			LogicalProviders(
				NotEntityTypeProviderPtr not_entity_type_provider,
				OrEntityTypeProviderPtr or_entity_type_provider,
				AndEntityTypeProviderPtr and_entity_type_provider,
				XorEntityTypeProviderPtr xor_entity_type_provider,
				NorEntityTypeProviderPtr nor_entity_type_provider,
				NandEntityTypeProviderPtr nand_entity_type_provider
			);

			~LogicalProviders();

			/// Initializes the providers for logical operations.
			void init();

		private:

			/// Provides the entity type NOT.
			NotEntityTypeProviderPtr not_entity_type_provider;

			/// Provides the entity type OR.
			OrEntityTypeProviderPtr or_entity_type_provider;

			/// Provides the entity type AND.
			AndEntityTypeProviderPtr and_entity_type_provider;

			/// Provides the entity type XOR.
			XorEntityTypeProviderPtr xor_entity_type_provider;

			/// Provides the entity type NOR.
			NorEntityTypeProviderPtr nor_entity_type_provider;

			/// Provides the entity type NAND.
			NandEntityTypeProviderPtr nand_entity_type_provider;

	};

}
}
}
