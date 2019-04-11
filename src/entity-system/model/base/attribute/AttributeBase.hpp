#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"

#include <optional>

namespace inexor {
namespace entity_system {

	/// @brief A base class for attributes.
	/// @note We can't directly instantiate this class because it is an abstract class.
	/// @note AttributeBase does not have a GUID, because it is an abstract base class.
	/// The GUID is created by the classes which inherit from AttributeBase.
	class AttributeBase
	{
		private:

			/// The data type of the attribute.
			/// The data is exclusively managed in the instance, not in this base class.
			DataType attribute_data_type;

			/// The features of the attribute.
			EnumSet<Feature> features;

			/// The mutex of this class.
			std::mutex attribute_type_base_mutex;

		protected:

			/// Constructor.
			/// @param attr_data_type The data type of the attribute.
			/// @param features A const EnumSet of the features.
			AttributeBase(const DataType&, const EnumSet<Feature>& features);

			/// Destructor.
			~AttributeBase();

		public:

			/// @brief Returns the data type of the attribute.
			/// @return The data type of the attribute.
			DataType get_attribute_data_type() const;

			/// Returns the features of the attribute.
			EnumSet<Feature> get_attribute_features() const;

	};

}
}
