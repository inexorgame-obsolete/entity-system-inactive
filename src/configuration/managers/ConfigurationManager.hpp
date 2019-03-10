#pragma once

#include "type-system/factories/constants/BoolConstantFactory.hpp"
#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "type-system/factories/constants/FloatConstantFactory.hpp"
#include "type-system/factories/constants/StringConstantFactory.hpp"

#include <unordered_map>

namespace inexor {
namespace configuration {

    /// Management of configuration items. Uses the entity system
    /// to store the configuration items as entities of type '*_CONSTANT'.
	class ConfigurationManager
	{
		using BoolConstantFactoryPtr = std::shared_ptr<entity_system::type_system::BoolConstantFactory>;
		using IntConstantFactoryPtr = std::shared_ptr<entity_system::type_system::IntConstantFactory>;
		using FloatConstantFactoryPtr = std::shared_ptr<entity_system::type_system::FloatConstantFactory>;
		using StringConstantFactoryPtr = std::shared_ptr<entity_system::type_system::StringConstantFactory>;
		using string = std::string;
		using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
		using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
		using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
		using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

		public:

			ConfigurationManager(
				BoolConstantFactoryPtr bool_constant_factory,
				IntConstantFactoryPtr int_constant_factory,
				FloatConstantFactoryPtr float_constant_factory,
				StringConstantFactoryPtr string_constant_factory
			);

			~ConfigurationManager();

			/// Initialization of the configuration manager
			void init();

			/// Returns true, if the configuration exists.
			bool exists(std::string config_name);

			/// Sets a configuration (bool).
			void set(string config_name, bool value);

			/// Sets a configuration (int).
			void set(string config_name, int value);

			/// Sets a configuration (float).
			void set(string config_name, float value);

			/// Sets a configuration (string).
			void set(string config_name, string value);

			/// Returns the configuration value (bool).
			bool get_bool(string config_name);

			/// Returns the configuration value (int).
			int get_int(string config_name);

			/// Returns the configuration value (float).
			float get_float(string config_name);

			/// Returns the configuration value (string).
			string get_string(string config_name);

			/// Returns the data type of the configuration item.
			DataType get_type(std::string config_name);

			/// Logs all configuration items.
			void list();

		private:

			/// Factory for BOOL_CONSTANT
			BoolConstantFactoryPtr bool_constant_factory;

			/// Factory for INT_CONSTANT
			IntConstantFactoryPtr int_constant_factory;

			/// Factory for FLOAT_CONSTANT
			FloatConstantFactoryPtr float_constant_factory;

			/// Factory for STRING_CONSTANT
			StringConstantFactoryPtr string_constant_factory;

			/// The names of the configuration items managed by the configuration manager
			std::unordered_map<std::string, EntityAttributeInstancePtr> config_items;

			/// Inserts a new configuration item.
			void insert(std::string config_name, std::string attribute_name, EntityInstancePtrOpt config_item);

			static constexpr char BOOL_CONSTANT_VALUE[] = "bool_constant_value";
			static constexpr char INT_CONSTANT_VALUE[] = "int_constant_value";
			static constexpr char FLOAT_CONSTANT_VALUE[] = "float_constant_value";
			static constexpr char STRING_CONSTANT_VALUE[] = "string_constant_value";

	};

}
}
