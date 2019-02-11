// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <variant>
#include <cstdint>
#include <glm/glm.hpp>

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/return-codes/ReturnCodes.hpp"

using namespace react;

REACTIVE_DOMAIN(D, sequential)

namespace inexor {
namespace entity_system {

    /// A data value can hold any value allowed by enum DataType.
    using DataValue = std::variant<bool, int, std::int64_t, double, float, std::string, glm::vec3, glm::vec4>;

    /// A data container which can hold data of various types.
    struct DataContainer {

    	USING_REACTIVE_DOMAIN(D)

    	/// The data type.
		DataType type;

    	/// The data value (signal).
    	VarSignalT<DataValue> value;

//    	DataContainer() {};
		DataContainer(const DataType& type)
			: type(type)
		{
    		switch (type)
    		{
    			case DataType::BOOL:
    			{
    				DataValue bool_value = false;
    	    		this->value = MakeVar<D>(bool_value);
    				break;
    			}
    			default:
    			case DataType::INT:
    			{
    				DataValue int_value = 0;
    				this->value = MakeVar<D>(int_value);
    				break;
    			}
    		}
		};
		DataContainer(const DataValue& value)
		{
    		switch (value.index())
    		{
    			case DataType::BOOL:
    				this->type = DataType::BOOL;
    				break;
    			default:
    			case DataType::INT:
    				this->type = DataType::INT;
    				break;
    		}
    		this->value = MakeVar<D>(value);
		};
		DataContainer(const DataType& type, const DataValue& value)
    		: type(type)
    	{
			this->value = MakeVar<D>(value);
    	};

    };

    struct DataContainerInitializer {
   		DataType type;
   		DataValue value;
    };

};
};
