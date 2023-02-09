#include "../include/rapi_char.h"

namespace rapi
{

Value::Ptr Char::create(char ch)
{
    return Value::Ptr(new Char(ch));
}

Char::Char()
    : Value(Type::Char)
    , m_value(0)
{
}

Char::Char(char ch)
    : Value(Type::Char)
    , m_value(ch)
{
}

Char::~Char()
{
}

void Char::stream_to(Stream& stream) const
{
    Value::stream_to(stream);

    stream.write<int8_t>(m_value);
}

void Char::stream_from(Stream& stream)
{
    Value::stream_from(stream);

    m_value = stream.read<int8_t>();
}

bool Char::compare(const Value& other) const
{
    if (!other.is_string())
        return false;

    return as_string() == other.as_string();
}

int64_t Char::as_int() const
{
    return m_value;
}

uint64_t Char::as_uint() const
{
    return m_value;
}

double Char::as_double() const
{
    return m_value;
}

std::string Char::as_string() const
{
    std::string str;
    str.push_back(m_value);

    return str;
}

void Char::to_string(std::stringstream& stream, int tab_index) const
{
    stream << "'" << m_value << "'";
}

}
