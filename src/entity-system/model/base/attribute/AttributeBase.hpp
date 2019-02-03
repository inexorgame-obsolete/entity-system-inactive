// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/validation/DataValidationBase.hpp"


namespace inexor {
namespace entity_system {


	/// @brief A base class for attributes.
	/// @note This base class does not implement
	/// a data validation method. Every class which
	/// inherits from AttributeBase must do this!
	/// @note We can only inherit from AttributeTypeBase
	/// but we can't create instances of the class
	/// directly because it is an abstract class.
	/// @note AttributeBase does not have a GUID,
	/// because it is an abstract base class. The
	/// GUID is created by the classes which inherit
	/// from AttributeBase.
	class AttributeBase : public DataValidationBase
	{
		private:

			/// The data type of the attribute.
			/// @note The data is only managed in
            /// the instance, not in this base class.
			DataType attribute_data_type;

            /// Mutex for this base class.
            std::mutex attribute_type_base_mutex;

		protected:
			
			/// Constructor.
			/// @param attr_data_type The data type
			/// of the attribute.
			AttributeBase(const DataType&);

			/// Destructor.
			~AttributeBase();
			
		public:

            /// @brief Returns the data type of the attribute.
			/// @note Since the data type must be set when
            /// the constructor is called, we do not
            /// implement std::optional here.
			/// @return The data type of the attribute.
			DataType get_attribute_data_type() const;


	};

};
};
