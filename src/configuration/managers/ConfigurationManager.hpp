// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "type-system/factories/constants/FloatConstantFactory.hpp"
#include "type-system/factories/constants/StringConstantFactory.hpp"

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using namespace std;

namespace inexor {
namespace configuration {

	/// @class ConfigurationManager
    /// @brief Management of configurations. Uses the entity system to store the configuration items.
	class ConfigurationManager
	{
		public:

			/// Constructor.
			ConfigurationManager(
				shared_ptr<IntConstantFactory> int_constant_factory,
				shared_ptr<FloatConstantFactory> float_constant_factory,
				shared_ptr<StringConstantFactory> string_constant_factory
			);

			/// Destructor.
			~ConfigurationManager();

			/// Initialization
			void init();

		private:

			/// Factory for INT_CONSTANT
			shared_ptr<IntConstantFactory> int_constant_factory;

			/// Factory for FLOAT_CONSTANT
			shared_ptr<FloatConstantFactory> float_constant_factory;

			/// Factory for STRING_CONSTANT
			shared_ptr<StringConstantFactory> string_constant_factory;

	};


};
};
