#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"

#include "react/Domain.h"
#include "react/Observer.h"

#include <mutex>
#include <optional>

using namespace react;

namespace inexor {
namespace visual_scripting {

	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

	/// A connector propagates the value of an output-attribute to
	/// an input-attribute.
    class Connector : public entity_system::GUIDBase
    {
		public:

			USING_REACTIVE_DOMAIN(inexor::entity_system::D)

			/// Constructor.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
			Connector(
				const EntityAttributeInstancePtr& output_attr,
				const EntityAttributeInstancePtr & input_attr
			);

            /// @brief Constructor.
			/// @param connector_GUID GUID of the connector.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
			Connector(
				const xg::Guid& connector_GUID,
				const EntityAttributeInstancePtr & output_attr,
				const EntityAttributeInstancePtr & input_attr
			);

			/// Destructor.
			~Connector();

            /// @brief Connects the output with the input.
			void connect();

            /// @brief Disconnects the output from the input and reconnects the input's own value again.
			void disconnect();

            /// @brief Get the GUID of the connector.
            /// @return GUID of the connector.
			xg::Guid connector() const;

            /// @brief Get the GUID of the output attribute.
            /// @return GUID of the output attribute.
			xg::Guid output() const;

            /// @brief Get the GUID of the input attribute.
            /// @return GUID of the input attribute.
			xg::Guid input() const;

			/// @brief Enables the debugging mode.
			void enable_debug();

			/// @brief Disables the debugging mode.
			void disable_debug();

			/// @brief Returns true, if the connector is in debugging mode.
			bool is_debug_enabled();

        private:

			/// GUID of the output attribute.
			xg::Guid output_attribute_GUID;

			/// GUID of the input attribute.
			xg::Guid input_attribute_GUID;

			/// The output attribute instance.
			EntityAttributeInstancePtr output_attr;

			/// The input attribute instance.
			EntityAttributeInstancePtr input_attr;

			/// The observer for debugging the connector.
			ObserverT observer;

			/// If true, the connector is in debugging mode.
			bool debug_enabled;

    };

}
}
