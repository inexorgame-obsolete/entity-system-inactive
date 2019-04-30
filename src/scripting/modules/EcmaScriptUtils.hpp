#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"

#include "v8/v8.h"

#include <crossguid/guid.hpp>

#include <string>
#include <optional>

namespace inexor {
namespace scripting {

	using DataType = entity_system::DataType;
	using DataValue = entity_system::DataValue;

	/// Extracts a C string from a V8 Utf8Value.
	const char* c_str(const v8::String::Utf8Value& value);

	/// Converts a V8 string to a std::string.
	std::string object_to_string(v8::Isolate* isolate, v8::Local<v8::Value> value);

	/// Converts a V8 string to an GUID.
	std::optional<xg::Guid> get_guid(const v8::String::Utf8Value& value);

	v8::Local<v8::Name> string_to_name(v8::Isolate* isolate, std::string name);

	/// Returns true, if the data type of the given value is compatible to the given entity system data type.
	bool has_data_type(DataType type, v8::Local<v8::Value> value);

	/// Converts the entity system DataValue to a V8 value using the given data type.
	v8::Local<v8::Value> data_value_to_value(v8::Isolate* isolate, DataType type, DataValue value);

	/// Converts the V8 value to an entity system DataValue.
	DataValue value_to_data_value(v8::Isolate* isolate, DataType type, v8::Local<v8::Value> value);

}
}
