// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "type-system/providers/constants/IntConstantEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	/// @class ConstantsTypeSystemManager
    /// @brief Management of the type system.
	class ConstantsTypeSystemManager
	{
		public:

			/// Constructor.
			ConstantsTypeSystemManager(
				shared_ptr<IntConstantEntityTypeProvider> int_constant_entity_type_provider
			);

			/// Destructor.
			~ConstantsTypeSystemManager();

			/// Initialization of the loggers
			void init();

		private:

			/// Provider for entity type INT_CONSTANT.
			shared_ptr<IntConstantEntityTypeProvider> int_constant_entity_type_provider;

	};

}
}
}
