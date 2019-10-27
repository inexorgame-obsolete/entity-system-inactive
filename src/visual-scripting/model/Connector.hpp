#pragma once

#include "entity-system/model/base/guid/GUIDBase.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"

#include "react/Domain.h"
#include "react/Observer.h"

using namespace react;

namespace inexor {
namespace visual_scripting {

	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

    /// @class Connector
	/// @brief A connector propagates the value of an output-attribute to an input-attribute.
    class Connector : public entity_system::GUIDBase
    {
		public:

            /// 
			USING_REACTIVE_DOMAIN(entity_system::D)

			/// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
			/// @param output_attr GUID of the output attribute.
			/// @param input_attr GUID of the input attribute.
			Connector(
				const EntityAttributeInstancePtr& output_attr,
				const EntityAttributeInstancePtr & input_attr
			);

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
			/// @param connector_GUID GUID of the connector.
			/// @param output_attr GUID of the output attribute.
			/// @param input_attr GUID of the input attribute.
			Connector(
				const xg::Guid& connector_GUID,
				const EntityAttributeInstancePtr & output_attr,
				const EntityAttributeInstancePtr & input_attr
			);

			/// Destructor.
			~Connector();

            /// Connects the output with the input.
			void connect();

            /// Disconnects the output from the input and reconnects the input's own value again.
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

			/// Enables the debugging mode.
			void enable_debug();

			/// Disables the debugging mode.
			void disable_debug();

			/// Returns true, if the connector is in debugging mode.
			bool is_debug_enabled();

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.vs.connector";

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
