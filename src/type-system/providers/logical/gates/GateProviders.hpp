#pragma once

#include "type-system/providers/logical/gates/NotEntityTypeProvider.hpp"
#include "type-system/providers/logical/gates/OrEntityTypeProvider.hpp"
#include "type-system/providers/logical/gates/AndEntityTypeProvider.hpp"
#include "type-system/providers/logical/gates/XorEntityTypeProvider.hpp"
#include "type-system/providers/logical/gates/NorEntityTypeProvider.hpp"
#include "type-system/providers/logical/gates/NandEntityTypeProvider.hpp"

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

	/// The entity type providers for logical gates.
	class GateProviders
	{
		public:

			/// Constructs the entity type providers for logical gates.
			GateProviders(
				NotEntityTypeProviderPtr not_entity_type_provider,
				OrEntityTypeProviderPtr or_entity_type_provider,
				AndEntityTypeProviderPtr and_entity_type_provider,
				XorEntityTypeProviderPtr xor_entity_type_provider,
				NorEntityTypeProviderPtr nor_entity_type_provider,
				NandEntityTypeProviderPtr nand_entity_type_provider
			);

			~GateProviders();

			/// Initializes the providers for logical gates.
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
