#include "../include/rapi_string.h"

namespace rapi
{

Value::Ptr String::create(const std::string& str)
{
    return Value::Ptr(new String(str));
}

String::String()
    : Value(Type::String)
{
}

String::String(const std::string& str)
    : Value(Type::String)
    , m_value(str)
{
}

String::~String()
{
}

void String::stream_to(Stream& stream) const
{
    Value::stream_to(stream);

    stream.write_string(m_value);
}

void String::stream_from(Stream& stream)
{
    Value::stream_from(stream);

    m_value = stream.read_string();
}

bool String::compare(const Value& other) const
{
    if (!other.is_string())
        return false;

    return m_value == other.as_string();
}

std::string String::as_string() const
{
    return m_value;
}

void String::to_string(std::stringstream& stream, int tab_index) const
{
    stream << "\"" << m_value << "\"";
}

}
