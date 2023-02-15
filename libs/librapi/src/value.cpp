#include "../include/rapi_value.h"
#include "../include/rapi_nil.h"
#include "../include/rapi_single_value.h"
#include "../include/rapi_char.h"
#include "../include/rapi_unique_id.h"
#include "../include/rapi_string.h"
#include "../include/rapi_list.h"
#include "../include/rapi_table.h"

#include <iostream>

namespace rapi
{

Value::Ptr Value::create(Type type)
{
	switch (type)
	{
    case Type::Bool:
        return Value::Ptr(new Bool());
    case Type::Char:
        return Value::Ptr(new Char());
    case Type::UInt8:
        return Value::Ptr(new UInt8());
    case Type::Int16:
        return Value::Ptr(new Int16());
    case Type::UInt16:
        return Value::Ptr(new UInt16());
	case Type::Int32:
		return Value::Ptr(new Int32());
    case Type::UInt32:
        return Value::Ptr(new UInt32());
    case Type::Float:
        return Value::Ptr(new Float());
    case Type::Double:
        return Value::Ptr(new Double());
    case Type::UniqueID:
        return Value::Ptr(new UniqueID());
	case Type::String:
		return Value::Ptr(new String());
    case Type::List:
        return Value::Ptr(new rapi::List());
    case Type::Table:
        return Value::Ptr(new rapi::Table());
    case Type::Nil:
        return Value::Ptr(new Nil());
	default:
		std::cerr << "RAPIValue::create(type = " << (int)type << "): invalid type." << std::endl;
	}

	return nullptr;
}

void Value::stream_value_to(const Value& value, Stream& stream)
{
	value.stream_to(stream);
}

void Value::stream_value_to(const Value::Ptr& value, Stream& stream)
{
	if (value)
		value->stream_to(stream);
}

Value::Ptr Value::stream_value_from(Stream& stream)
{
	Type type = stream.read<Type>();

	std::unique_ptr<Value> value = Value::create(type);
	if (!value)
		return nullptr;

	value->stream_from(stream);

	return value;
}

void Value::stream_to(Stream& stream) const
{
	stream.write(m_type);
}

void Value::stream_from(Stream& stream)
{
	// empty because type should already be read by the static version of this function!!!!
}

bool Value::is_nil() const
{
    return type() == Type::Nil;
}

bool Value::is_unique_id() const
{
    return type() == Type::UniqueID;
}

bool Value::is_number() const
{
    return type_is_signed_int(type())
        || type_is_unsigned_int(type())
        || type_is_floating_point(type());
}

bool Value::is_string() const
{
    // we treat char as a string with length 1
    return type() == Type::String || type() == Type::Char;
}

bool Value::is_list() const
{
    return type() == Type::List;
}

bool Value::is_table() const
{
    return type() == Type::Table;
}

const Value* Value::find_value(const std::string& key) const
{
    return find_value(String::create(key));
}

const Value* Value::find_value(size_t idx) const
{
    return find_value(UInt32::create(idx));
}

}
