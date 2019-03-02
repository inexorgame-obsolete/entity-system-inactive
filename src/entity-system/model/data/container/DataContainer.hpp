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

namespace inexor {
namespace entity_system {

	REACTIVE_DOMAIN(D, sequential)

	USING_REACTIVE_DOMAIN(D)

    /// A data value can hold any value allowed by enum DataType.
//    using DataValue = std::variant<bool, int, std::int64_t, double, float, std::string, glm::vec3, glm::vec4>;
    using DataValue = std::variant<bool, int, std::int64_t, double, float, std::string>;

//	int int_f(int v) {
//		return v;
//    }
//
//	int int_s_t(int s, int t) {
//		return s + t;
//    }
//
//	VarSignalT<int> s = MakeVar<D>(0);
//	VarSignalT<int> t = MakeVar<D>(0);
//
//	SignalT<int> v1 = MakeSignal(With(s, t), int_s_t);

    /// A data container which can hold data of various types.
    struct DataContainer {

    	/// The data type.
		DataType type;

    	/// The own value.
    	VarSignalT<DataValue> own_value;

    	/// The outer value.
    	VarSignal<D, SignalT<DataValue>> signal_wrapper;

    	/// The flatted (output) value.
    	SignalT<DataValue> value;


//    	DataContainer() {};

		DataContainer(const DataType& type)
			: type(type)
		{
    		switch (type)
    		{
    			case DataType::BOOL:
    			{
    				DataValue bool_value = false;
    				this->own_value = MakeVar<D>(bool_value);
    				this->signal_wrapper = MakeVar<D>(this->own_value);
    				this->value = Flatten(signal_wrapper);
    				break;
    			}
    			// TODO: Add other data types!
    			default:
    			case DataType::INT:
    			{
    				DataValue int_value = 0;
    				this->own_value = MakeVar<D>(int_value);
    				this->signal_wrapper = MakeVar<D>(this->own_value);
    				this->value = Flatten(signal_wrapper);
    				break;
    			}
    		}
		};

		DataContainer(const DataValue& data_value)
		{
//			// TODO: shorter version:
//			// DataType::_from_integral(value.index());
//    		switch (value.index())
//    		{
//    			case DataType::BOOL:
//    				this->type = DataType::BOOL;
//    				break;
//    			default:
//    			case DataType::INT:
//    				this->type = DataType::INT;
//    				break;
//    		}
			/// Detect type by std::variant index()
			this->type = DataType::_from_integral(data_value.index());
			this->own_value = MakeVar<D>(data_value);
			this->signal_wrapper = MakeVar<D>(this->own_value);
			this->value = Flatten(signal_wrapper);
		};

		DataContainer(const DataType& type, const DataValue& data_value)
    		: type(type)
    	{
			this->own_value = MakeVar<D>(data_value);
			this->signal_wrapper = MakeVar<D>(this->own_value);
			this->value = Flatten(signal_wrapper);
    	};

    };

    struct DataContainerInitializer {
   		DataType type;
   		DataValue value;
    };

};
};
