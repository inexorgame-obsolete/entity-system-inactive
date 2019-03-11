#pragma once

#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/factories/constants/BoolConstantFactory.hpp"
#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "type-system/factories/constants/FloatConstantFactory.hpp"
#include "type-system/factories/constants/StringConstantFactory.hpp"
#include "logging/managers/LogManager.hpp"

#include <unordered_map>

namespace inexor {
namespace configuration {

	using DataType = entity_system::DataType;

    /// Management of configuration items. Uses the entity system
    /// to store the configuration items as entities of type '*_CONSTANT'.
	class ConfigurationManager
	{
		using BoolConstantFactoryPtr = std::shared_ptr<entity_system::type_system::BoolConstantFactory>;
		using IntConstantFactoryPtr = std::shared_ptr<entity_system::type_system::IntConstantFactory>;
		using FloatConstantFactoryPtr = std::shared_ptr<entity_system::type_system::FloatConstantFactory>;
		using StringConstantFactoryPtr = std::shared_ptr<entity_system::type_system::StringConstantFactory>;
		using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
		using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
		using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
		using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
		using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

		public:

			ConfigurationManager(
				BoolConstantFactoryPtr bool_constant_factory,
				IntConstantFactoryPtr int_constant_factory,
				FloatConstantFactoryPtr float_constant_factory,
				StringConstantFactoryPtr string_constant_factory,
				LogManagerPtr log_manager
			);

			~ConfigurationManager();

			/// Initialization of the configuration manager
			void init();

			/// Returns true, if the configuration exists.
			bool exists(std::string config_name);

			/// Sets a configuration (bool).
			void set(std::string config_name, bool value);

			/// Sets a configuration (int).
			void set(std::string config_name, int value);

			/// Sets a configuration (float).
			void set(std::string config_name, float value);

			/// Sets a configuration (string).
			void set(std::string config_name, std::string value);

			/// Returns the configuration value (bool).
			bool get_bool(std::string config_name);

			/// Returns the configuration value (int).
			int get_int(std::string config_name);

			/// Returns the configuration value (float).
			float get_float(std::string config_name);

			/// Returns the configuration value (string).
			std::string get_string(std::string config_name);

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

			/// The log manager
			LogManagerPtr log_manager;

			/// The names of the configuration items managed by the configuration manager
			std::unordered_map<std::string, EntityAttributeInstancePtr> config_items;

			/// Inserts a new configuration item.
			void insert(std::string config_name, std::string attribute_name, EntityInstancePtrOpt config_item);

			static constexpr char BOOL_CONSTANT_VALUE[] = "bool_constant_value";
			static constexpr char INT_CONSTANT_VALUE[] = "int_constant_value";
			static constexpr char FLOAT_CONSTANT_VALUE[] = "float_constant_value";
			static constexpr char STRING_CONSTANT_VALUE[] = "string_constant_value";

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.config.manager";

	};

}
}
