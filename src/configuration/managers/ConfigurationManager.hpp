#pragma once

#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/factories/data/constants/BoolConstantFactory.hpp"
#include "type-system/factories/data/constants/IntConstantFactory.hpp"
#include "type-system/factories/data/constants/FloatConstantFactory.hpp"
#include "type-system/factories/data/constants/StringConstantFactory.hpp"
#include "logging/managers/LogManager.hpp"

#include <unordered_map>

namespace inexor {
namespace configuration {

	using DataType = entity_system::DataType;

    /// @class ConfigurationManager
    /// @brief Management of configuration items. Uses the entity system
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

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param bool_constant_factory Factory for BOOL_CONSTANT.
            /// @param int_constant_factory Factory for INT_CONSTANT.
            /// @param float_constant_factory Factory for FLOAT_CONSTANT.
            /// @param string_constant_factory Factory for STRING_CONSTANT.
            /// @param log_manager The log manager.
			ConfigurationManager(
				BoolConstantFactoryPtr bool_constant_factory,
				IntConstantFactoryPtr int_constant_factory,
				FloatConstantFactoryPtr float_constant_factory,
				StringConstantFactoryPtr string_constant_factory,
				LogManagerPtr log_manager
			);

            /// Destructor.
			~ConfigurationManager();

			/// Initialization of the configuration manager.
			void init();

            /// @brief Checks if a configuration exists.
            /// @param config_name The name of the configuration.
			/// @return <b>true</b> if the configuration exists, <b>false</b> otherwise.
			bool exists(std::string config_name);

			/// Sets a configuration (bool).
            /// @param config_name The name of the configuration.
            /// @param value The boolean value to which the configuration will be set.
			void set(std::string config_name, bool value);

			/// Sets a configuration (int).
            /// @param config_name The name of the configuration.
            /// @param value The int value to which the configuration will be set.
			void set(std::string config_name, int value);

			/// Sets a configuration (float).
            /// @param config_name The name of the configuration.
            /// @param value The float value to which the configuration will be set.
			void set(std::string config_name, float value);

			/// Sets a configuration (string).
            /// @param config_name The name of the configuration.
            /// @param value The std::string value to which the configuration will be set.
			void set(std::string config_name, std::string value);

			/// Returns the configuration value (bool).
            /// @note Since in C++ there can be no class methods with the same name
            /// who only differ in return type, we have to include the type in the method name.
            /// @param config_name The name of the configuration.
			bool get_bool(std::string config_name);

			/// Returns the configuration value (int).
            /// @note Since in C++ there can be no class methods with the same name
            /// who only differ in return type, we have to include the type in the method name.
            /// @param config_name The name of the configuration.
			int get_int(std::string config_name);

			/// Returns the configuration value (float).
            /// @note Since in C++ there can be no class methods with the same name
            /// who only differ in return type, we have to include the type in the method name.
            /// @param config_name The name of the configuration.
			float get_float(std::string config_name);

			/// Returns the configuration value (string).
            /// @note Since in C++ there can be no class methods with the same name
            /// who only differ in return type, we have to include the type in the method name.
            /// @param config_name The name of the configuration.
			std::string get_string(std::string config_name);

			/// Returns the data type of the configuration item.
            /// @param config_name The name of the configuration.
			DataType get_type(std::string config_name);

			/// Logs all configuration items.
			void list();

		private:

			/// Factory for BOOL_CONSTANT.
			BoolConstantFactoryPtr bool_constant_factory;

			/// Factory for INT_CONSTANT.
			IntConstantFactoryPtr int_constant_factory;

			/// Factory for FLOAT_CONSTANT.
			FloatConstantFactoryPtr float_constant_factory;

			/// Factory for STRING_CONSTANT.
			StringConstantFactoryPtr string_constant_factory;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The names of the configuration items managed by the configuration manager.
			std::unordered_map<std::string, EntityAttributeInstancePtr> config_items;

			/// Inserts a new configuration item.
            /// @param config_name The name of the configuration.
            /// @param attribute_name The name of the attribute.
            /// @param config_item The name of the configuration item.
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
