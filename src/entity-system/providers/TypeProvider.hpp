#pragma once

#include "entity-system/model/data/DataTypes.hpp"

#include <memory>
#include <string>
#include <unordered_map>
#include <tuple>

namespace inexor {
namespace entity_system {

/// This is the base class for type providers (e.g. entity type and
/// relation type provider). The creation of the type is done by the
/// provider. Other services have to use the provider in order to
/// get the specialized type.
///
/// The type is created lazily at runtime, this means the first
/// access leads to its construction.
///
/// @tparam T The type (EntityType or RelationType)
/// @tparam BUILDER_MANAGER The type of the builder manager. TODO: remove because builder manager not yet templated.
template<typename T, typename BUILDER_MANAGER>
class TypeProvider
{
	using string = std::string;
	using AttributeList = std::unordered_map<string, std::pair<DataType, EnumSet<Feature>>>;

	public:

		/// Constructs the type provider using a specialized builder manager
		/// which is used to construct the type.
		TypeProvider(
			std::shared_ptr<BUILDER_MANAGER> type_builder_manager,
			string type_name,
			AttributeList type_attributes
		) {
			this->type_builder_manager = type_builder_manager;
			this->type_name = type_name;
			this->type_attributes = type_attributes;
			this->created = false;
		}

		virtual ~TypeProvider() {}

		/// Returns the name of the type.
		string get_type_name()
		{
			return type_name;
		}

		/// Returns the type itself.
		std::shared_ptr<T> get_type()
		{
			if(created) return type;
			auto builder = type_builder_manager->get_builder();
			builder->name(type_name);

			for(auto& type_attribute : type_attributes)
			{
				// The attribute specification contains the datatype as first and the list of features as second argument
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

		/// The builder manager to use to create the type
		std::shared_ptr<BUILDER_MANAGER> type_builder_manager;

		/// The name of the type
		string type_name;

		/// The list of attributes, their datatypes and their attached features
		AttributeList type_attributes;

		/// The created type
		std::shared_ptr<T> type;

		/// True, if the type has been created
		bool created;

	};

}
}
