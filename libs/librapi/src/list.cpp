#include "../include/rapi_list.h"

namespace rapi
{

List::List()
    : Value(Type::List)
{
}

void List::stream_to(Stream& stream) const
{
    Value::stream_to(stream);

    uint16_t size = (uint16_t)m_values.size();

    stream.write<uint16_t>(size);

    for (int i = 0; i < (int)size; ++i)
        Value::stream_value_to(m_values[i], stream);
}

void List::stream_from(Stream& stream)
{
    Value::stream_from(stream);

    uint16_t size = stream.read<uint16_t>();

    m_values.reserve(size);
    for (int i = 0; i < (int)size; ++i)
        m_values.push_back(Value::stream_value_from(stream));
}

void List::insert(Value::Ptr&& value)
{
    m_values.push_back(std::move(value));
}

bool List::compare(const Value& other) const
{
    if (other.type() != Type::List && (other.type() != Type::Table || !other.keyed_values().empty()))
        return false;

    const Value::List& other_lst = other.indexed_values();
    if (m_values.size() != other_lst.size())
        return false;

    for (int i = 0; i < (int)m_values.size(); ++i)
    {
        if (!m_values[i] && other_lst[i])
            return false;

        if (m_values[i] && !m_values[i]->compare(other_lst[i]))
            return false;
    }
        
    return true;
}

const Value::List& List::indexed_values() const
{
    return m_values;
}

static void stream_tabs(std::stringstream& stream, int tab_index)
{
    while (tab_index-- > 0)
        stream << "    ";
}

const Value* List::find_value(const Value& key) const
{
    if (!key.is_number())
        return nullptr;

    int64_t idx = key.as_int();
    if (idx < 0 || (size_t)idx >= m_values.size())
        return nullptr;

    return m_values[idx].get();
}

void List::to_string(std::stringstream& stream, int tab_index) const
{
    if (m_values.empty())
    {
        stream << "{}";
    }
    else
    {
        stream << "{" << std::endl;
        
        for (const auto& item : m_values)
        {
            stream_tabs(stream, tab_index + 1);
            if (item)
                item->to_string(stream, tab_index + 1);
            else
                stream << "nil";

            stream << "," << std::endl;
        }

        stream_tabs(stream, tab_index);
        stream << "}";
    }
}

}
