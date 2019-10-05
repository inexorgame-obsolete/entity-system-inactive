#include "EcmaScriptUtils.hpp"

namespace inexor {
namespace scripting {

	const char* c_str(const v8::String::Utf8Value& value)
	{
		return *value ? *value : "<string conversion failed>";
	}

	std::string object_to_string(v8::Isolate* isolate, v8::Local<v8::Value> value)
	{
		v8::String::Utf8Value utf8_value(isolate, value);
		return std::string(*utf8_value);
	}

	std::optional<xg::Guid> get_guid(const v8::String::Utf8Value& value)
	{
		if (*value)
		{
			return xg::Guid(std::string(*value));
		} else {
			return std::nullopt;
		}
	}

	v8::Local<v8::Name> string_to_name(v8::Isolate* isolate, std::string name)
	{
		return v8::String::NewFromUtf8(isolate, name.c_str()).As<v8::Name>();
	}

	bool has_data_type(DataType type, v8::Local<v8::Value> value)
	{
		return (type._value == DataType::BOOL && value->IsBoolean())
			|| (type._value == DataType::INT && value->IsInt32())
			|| (type._value== DataType::BIG_INT && value->IsBigInt())
			|| (type._value == DataType::DOUBLE && value->IsNumber())
			|| (type._value == DataType::FLOAT && value->IsNumber())
			|| (type._value == DataType::STRING && value->IsString());
	}

	v8::Local<v8::Value> data_value_to_value(v8::Isolate* isolate, DataType type, DataValue value)
	{
		switch (type)
		{
			case DataType::BOOL:
				return v8::Boolean::New(isolate, std::get<DataType::BOOL>(value));
			case DataType::INT:
				return v8::Integer::New(isolate, std::get<DataType::INT>(value));
			case DataType::BIG_INT:
				return v8::BigInt::New(isolate, std::get<DataType::BIG_INT>(value));
			case DataType::DOUBLE:
				return v8::Number::New(isolate, std::get<DataType::DOUBLE>(value));
			case DataType::FLOAT:
				return v8::Number::New(isolate, (double) std::get<DataType::FLOAT>(value));
			case DataType::STRING:
				return v8::String::NewFromUtf8(isolate, std::get<DataType::STRING>(value).c_str());
			default:
				return v8::Null(isolate);
		}
	}

	DataValue value_to_data_value(v8::Isolate* isolate, DataType type, v8::Local<v8::Value> value)
	{
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		if (type._value == DataType::BOOL && value->IsBoolean()) {
			return DataValue(value->BooleanValue(isolate));
		} else if (type._value == DataType::INT && value->IsInt32()) {
			return DataValue(value->Int32Value(context).ToChecked());
		} else if (type._value == DataType::BIG_INT && value->IsBigInt()) {
			return DataValue(value->IntegerValue(context).ToChecked());
		} else if (type._value == DataType::DOUBLE && value->IsNumber()) {
			return DataValue(value->NumberValue(context).ToChecked());
		} else if (type._value == DataType::FLOAT && value->IsNumber()) {
			return DataValue((float) value->NumberValue(context).ToChecked());
		} else if (type._value == DataType::STRING && value->IsString()) {
			return DataValue(object_to_string(isolate, value));
		} else {
			return DataValue();
		}
	}

}
}
