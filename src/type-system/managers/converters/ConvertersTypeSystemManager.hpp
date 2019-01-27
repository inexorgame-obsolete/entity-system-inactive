// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "type-system/providers/converters/IntToFloatEntityTypeProvider.hpp"

#include "type-system/factories/converters/IntToFloatFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	/// @class ConvertersTypeSystemManager
    /// @brief Management of the type system.
	class ConvertersTypeSystemManager
	{
		public:

			/// Constructor.
			ConvertersTypeSystemManager(
				shared_ptr<IntToFloatEntityTypeProvider> int_to_float_entity_type_provider,
				shared_ptr<IntToFloatFactory> int_to_float_factory
			);

			/// Destructor.
			~ConvertersTypeSystemManager();

			/// Initialization
			void init();

		private:

			/// Provider for entity type INT_TO_FLOAT.
			shared_ptr<IntToFloatEntityTypeProvider> int_to_float_entity_type_provider;

			/// Factory for entity type INT_TO_FLOAT.
			shared_ptr<IntToFloatFactory> int_to_float_factory;

	};

}
}
}
