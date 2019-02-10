// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "entity-system/util/uuid/GUIDBase.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

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
			
			/// Constructor.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
			Connector(const Guid& output_attribute_GUID, const Guid& input_attribute_GUID);

            /// @brief Constructor.
			/// @param connector_GUID GUID of the connector.
			/// @param output_attribute_GUID GUID of the output attribute.
			/// @param input_attribute_GUID GUID of the input attribute.
			/// @note The GUID of the connector.
			Connector(const Guid& connector_GUID, const Guid& output_attribute_GUID, const Guid& input_attribute_GUID);

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
