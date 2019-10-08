#pragma once

#include "entity-system/model/data/DataTypes.hpp"

#include <memory>
#include <string>
#include <unordered_map>
#include <tuple>

namespace inexor {
namespace entity_system {

	/// @brief This is the base class for type providers (e.g. entity type provider and relation type provider).
	/// A provider makes sure that a type is being created and can be used in the code. Other services have to
	/// use the provider in order to get the specialized type. The type is created lazily at runtime, this means
	/// that the first access leads to its construction.
	/// @note This template base class is part of a software design pattern called the <b>provider pattern</b>.
	/// @tparam T The type (e.g. EntityType or RelationType)
	/// @tparam BUILDER_MANAGER The type of the builder manager.
	/// @todo Remove BUILDER_MANAGER because builder manager is not yet templated.
	template<typename T, typename BUILDER_MANAGER>
	class TypeProvider
	{
		/// This using instruction helps to shorten the following code.
		using AttributeList = std::unordered_map<std::string, std::pair<DataType, EnumSet<Feature>>>;

		public:

			/// @brief Constructs the type provider by using a specialized builder manager.
			/// @param type_builder_manager The builder manager.
			/// @param type_name The name of the type.
			/// @param type_attributes The attributes of the type.
			/// @todo Add mutex to ensure thread-safety!
			TypeProvider(
				std::shared_ptr<BUILDER_MANAGER> type_builder_manager,
				std::string type_name,
				AttributeList type_attributes
			)
			{
				this->type_builder_manager = type_builder_manager;
				this->type_name = type_name;
				this->type_attributes = type_attributes;
				this->created = false;
			}

			virtual ~TypeProvider()
			{
			}

			/// @brief Returns the name of the type.
			/// @return The name of the type.
			std::string get_type_name() const
			{
				return type_name;
			}

			/// @brief Returns a shared pointer to the type.
			/// @return A shared pointer to the type.
			/// @todo Add mutex to ensure thread-safety (there is a write operation in here)!
			std::shared_ptr<T> get_type()
			{
				if(created)
				{
					return type;
				}

				auto builder = type_builder_manager->get_builder();
				builder->name(type_name);

				for(auto& type_attribute : type_attributes)
				{
					// The attribute specification contains the datatype as first and the list of features as second argument.
					auto attribute_specification = type_attribute.second;
					builder->attribute(type_attribute.first, attribute_specification.first, attribute_specification.second);
				}

				std::optional<std::shared_ptr<T>> o_type = builder->build();
				if(o_type.has_value())
				{
					type = o_type.value();
					created = true;
				}
				else
				{
					std::cout << "ERR: " << type_name;
				}
				return type;
			}

		private:

			/// The builder manager which is used to create the type.
			std::shared_ptr<BUILDER_MANAGER> type_builder_manager;

			/// The name of the type.
			std::string type_name;

			/// The list of attributes, their datatypes and their attached features.
			AttributeList type_attributes;

			/// The created type.
			std::shared_ptr<T> type;

			/// This is set to true if the type has been created.
			bool created;

		};

}
}
