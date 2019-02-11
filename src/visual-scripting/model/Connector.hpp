// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;
using namespace react;

//REACTIVE_DOMAIN(D, sequential)

namespace inexor {
namespace visual_scripting {


	/// A base class for entity type instances.
    class Connector : public GUIDBase
    {
        private:

			/// GUID of the output attribute.
			Guid output_attribute_GUID;

			/// GUID of the input attribute.
			Guid input_attribute_GUID;

		public:

			USING_REACTIVE_DOMAIN(D)

//			/// The output value.
//			VarSignalT<DataValue&> output_value;
//
			ObserverT observer;

			/// Constructor.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
//			Connector(const Guid& output_attribute_GUID, const Guid& input_attribute_GUID, const DataValue& output_value, const DataValue& input_value)
//				: GUIDBase()
			Connector(
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance>& output_attr,
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance>& input_attr
			) : GUIDBase()
			{
				this->output_attribute_GUID = output_attr->get_GUID();
				this->input_attribute_GUID = input_attr->get_GUID();

				this->observer = Observe(output_attr->value, [output_attr, input_attr] (DataValue value) {
					std::cout << output_attr->get_GUID().str() << "." << output_attr->get_entity_attribute_type()->get_type_name() << " has changed: " << std::get<DataType::INT>(value) << std::endl;
				});

				// THAT SIMPLE ???
				input_attr->value = output_attr->value;

//				this->output_value = MakeVar<D>(std::ref(output_attr->value));
////				this->output_value = MakeVar<D>(output_attr->value);
//				this->observer = Observe(output_value, [&, input_attr] (DataValue& v) {
//					std::cout << "output_value has changed: " << std::get<DataType::INT>(v);
//					input_attr->value = output_value.Value();
//				});
			};

            /// @brief Constructor.
			/// @param connector_GUID GUID of the connector.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
			Connector(
				const Guid& connector_GUID,
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance>& output_attr,
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance>& input_attr
			) : GUIDBase(connector_GUID)
			{
				this->output_attribute_GUID = output_attr->get_GUID();
				this->input_attribute_GUID = input_attr->get_GUID();
//				this->output_value = MakeVar<D>(std::ref(output_attr->value));
////				this->output_value = MakeVar<D>(output_attr->value);
//				this->observer = Observe(output_value, [&, input_attr] (DataValue& v) {
//					std::cout << "output_value has changed: " << std::get<DataType::INT>(v);
//					input_attr->value = output_value.Value();
//				});
			};

			/// Destructor.
			~Connector();

            /// @brief Get the GUID of the connector.
            /// @return GUID of the connector.
			Guid connector() const;

            /// @brief Get the GUID of the output attribute.
            /// @return GUID of the output attribute.
			Guid output() const;

            /// @brief Get the GUID of the input attribute.
            /// @return GUID of the input attribute.
			Guid input() const;

    };


};
};
