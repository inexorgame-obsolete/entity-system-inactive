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

namespace inexor {
namespace visual_scripting {


	/// A base class for entity type instances.
    class Connector : public GUIDBase
    {
		public:

			USING_REACTIVE_DOMAIN(D)

			/// Constructor.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
			Connector(
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & output_attr,
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & input_attr
			);

            /// @brief Constructor.
			/// @param connector_GUID GUID of the connector.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
			Connector(
				const Guid& connector_GUID,
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & output_attr,
				const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & input_attr
			);

			/// Destructor.
			~Connector();

            /// @brief Connects the output with the input.
			void connect();

            /// @brief Disconnects the output from the input and reconnects the input's own value again.
			void disconnect();

            /// @brief Get the GUID of the connector.
            /// @return GUID of the connector.
			Guid connector() const;

            /// @brief Get the GUID of the output attribute.
            /// @return GUID of the output attribute.
			Guid output() const;

            /// @brief Get the GUID of the input attribute.
            /// @return GUID of the input attribute.
			Guid input() const;

			/// @brief Enables the connector debugging.
			void enable_debug();

			/// @brief Disables the connector debugging.
			void disable_debug();

			/// @brief Returns true, if the connector debugging is enabled.
			bool is_debug_enabled();

        private:

			/// GUID of the output attribute.
			Guid output_attribute_GUID;

			/// GUID of the input attribute.
			Guid input_attribute_GUID;

			/// The output attribute instance.
			std::shared_ptr<inexor::entity_system::EntityAttributeInstance> output_attr;

			/// The input attribute instance.
			std::shared_ptr<inexor::entity_system::EntityAttributeInstance> input_attr;

			/// The connector observer.
			ObserverT observer;

			/// The signal.
			bool debug_enabled;

    };


};
};
