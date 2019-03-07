#pragma once

#include "type-system/factories/constants/BoolConstantFactory.hpp"
#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "type-system/factories/constants/FloatConstantFactory.hpp"
#include "type-system/factories/constants/StringConstantFactory.hpp"


namespace inexor {
namespace configuration {

    /// Management of configurations. Uses the entity system to store the configuration items.
	class ConfigurationManager
	{
		using BoolConstantFactoryPtr = std::shared_ptr<entity_system::type_system::BoolConstantFactory>;
		using IntConstantFactoryPtr = std::shared_ptr<entity_system::type_system::IntConstantFactory>;
		using FloatConstantFactoryPtr = std::shared_ptr<entity_system::type_system::FloatConstantFactory>;
		using StringConstantFactoryPtr = std::shared_ptr<entity_system::type_system::StringConstantFactory>;
		using string = std::string;

		public:

			ConfigurationManager(
				BoolConstantFactoryPtr bool_constant_factory,
				IntConstantFactoryPtr int_constant_factory,
				FloatConstantFactoryPtr float_constant_factory,
				StringConstantFactoryPtr string_constant_factory
			);

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
			BoolConstantFactoryPtr bool_constant_factory;

			/// Factory for INT_CONSTANT
			IntConstantFactoryPtr int_constant_factory;

			/// Factory for FLOAT_CONSTANT
			FloatConstantFactoryPtr float_constant_factory;

			/// Factory for STRING_CONSTANT
			StringConstantFactoryPtr string_constant_factory;

	};

} } // inexor::configuration
