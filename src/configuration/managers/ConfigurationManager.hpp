// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/factories/constants/BoolConstantFactory.hpp"
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
				shared_ptr<BoolConstantFactory> bool_constant_factory,
				shared_ptr<IntConstantFactory> int_constant_factory,
				shared_ptr<FloatConstantFactory> float_constant_factory,
				shared_ptr<StringConstantFactory> string_constant_factory
			);

			/// Destructor.
			~ConfigurationManager();

			/// Initialization
			void init();

			/// Sets a configuration (bool).
			void set(string name, bool value);

			/// Sets a configuration (int).
			void set(string name, int value);

			/// Sets a configuration (float).
			void set(string name, float value);

			/// Sets a configuration (string).
			void set(string name, string value);

			/// Returns the configuration value (bool).
			bool get_bool(string config_name);

			/// Returns the configuration value (int).
			int get_int(string config_name);

			/// Returns the configuration value (float).
			float get_float(string config_name);

			/// Returns the configuration value (string).
			string get_string(string config_name);

		private:

			/// Factory for BOOL_CONSTANT
			shared_ptr<BoolConstantFactory> bool_constant_factory;

			/// Factory for INT_CONSTANT
			shared_ptr<IntConstantFactory> int_constant_factory;

			/// Factory for FLOAT_CONSTANT
			shared_ptr<FloatConstantFactory> float_constant_factory;

			/// Factory for STRING_CONSTANT
			shared_ptr<StringConstantFactory> string_constant_factory;

	};


};
};
