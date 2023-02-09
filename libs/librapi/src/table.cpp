#include "../include/rapi_table.h"

namespace rapi
{

Value::Ptr Table::create()
{
    return Value::Ptr(new Table());
}

Table::Table()
    : Value(Type::Table)
{
}

Table::~Table()
{
}

void Table::stream_to(Stream& stream) const
{
    Value::stream_to(stream);

    uint16_t indexed_size = (uint16_t)m_indexed_values.size();
    uint16_t keyed_size   = (uint16_t)m_keyed_values.size();

    stream.write<uint16_t>(indexed_size);
    stream.write<uint16_t>(keyed_size);

    for (int i = 0; i < (int)indexed_size; ++i)
        Value::stream_value_to(m_indexed_values[i], stream);

    
    for (int i = 0; i < (int)keyed_size; ++i)
    {
        Value::stream_value_to(m_keyed_values[i].first, stream);
        Value::stream_value_to(m_keyed_values[i].second, stream);
    }
}

void Table::stream_from(Stream& stream)
{
    Value::stream_from(stream);

    uint16_t indexed_size = stream.read<uint16_t>();
    uint16_t keyed_size   = stream.read<uint16_t>();

    m_indexed_values.reserve(indexed_size);
    for (int i = 0; i < (int)indexed_size; ++i)
        m_indexed_values.push_back(Value::stream_value_from(stream));


    m_keyed_values.reserve(keyed_size);
    for (int i = 0; i < (int)keyed_size; ++i)
    {
        // we do not call these inline because std::make_pair(A, B) would evalulate B before A (would swap key/value)
        Value::Ptr key   = Value::stream_value_from(stream);
        Value::Ptr value = Value::stream_value_from(stream);

        m_keyed_values.push_back(std::make_pair(
            std::move(key),
            std::move(value)
        ));
    }
}

void Table::insert(Value::Ptr&& value)
{
    m_indexed_values.push_back(std::move(value));
}

void Table::insert(Value::KeyValuePair&& key_value)
{
    // check if key is already present and remove it if this is the case
    for (Value::Table::iterator it = m_keyed_values.begin(); it != m_keyed_values.end(); ++it)
    {
        if (!it->first && key_value.first)
            continue;

        if (it->first && !it->first->compare(key_value.first))
            continue;

        m_keyed_values.erase(it);
        break;
    }

    m_keyed_values.push_back(std::move(key_value));
}

bool Table::compare(const Value& other) const
{
    if (other.type() != Type::Table && other.type() != Type::List)
        return false;

    // compare lists
    const Value::List& other_lst = other.indexed_values();
    if (m_indexed_values.size() != other_lst.size())
        return false;

    for (int i = 0; i < (int)m_indexed_values.size(); ++i)
    {
        if (!m_indexed_values[i] && other_lst[i])
            return false;

        if (m_indexed_values[i] && !m_indexed_values[i]->compare(other_lst[i]))
            return false;
    }

    // compare tables
    const Value::Table& other_tab = other.keyed_values();
    if (m_keyed_values.size() != other_tab.size())
        return false;

    for (const auto& keyvalue : m_keyed_values)
    {
        bool key_value_found = false;
        for (const auto& other_keyvalue : other_tab)
        {
            // test key
            if (!keyvalue.first && other_keyvalue.first)
                continue;

            if (keyvalue.first && !keyvalue.first->compare(other_keyvalue.first))
                continue;

            // test value
            if (!keyvalue.second && other_keyvalue.second)
                break;

            if (keyvalue.second && !keyvalue.second->compare(other_keyvalue.second))
                break;

            key_value_found = true;
            break;
        }

        if (!key_value_found)
            return false;
    }

    return true;
}

const Value::List& Table::indexed_values() const
{
    return m_indexed_values;
}

const Value::Table& Table::keyed_values() const
{
    return m_keyed_values;
}

static void stream_tabs(std::stringstream& stream, int tab_index)
{
    while (tab_index-- > 0)
        stream << "    ";
}

const Value* Table::find_value(const Value& key) const
{
    if (key.is_number())
    {
        int64_t idx = key.as_int();
        if (idx >= 0 && (size_t)idx < m_indexed_values.size())
            return m_indexed_values[idx].get();
    }

    for (const auto& key_value_pair : m_keyed_values)
    {
        if (key.compare(key_value_pair.first))
            return key_value_pair.second.get();
    }

    return nullptr;
}

void Table::to_string(std::stringstream& stream, int tab_index) const
{
    stream << "{";

    if (!m_indexed_values.empty() || !m_keyed_values.empty())
        stream << std::endl;

    for (const auto& item : m_indexed_values)
    {
        stream_tabs(stream, tab_index + 1);

        if (item)
            item->to_string(stream, tab_index + 1);
        else
            stream << "nil";

        stream << "," << std::endl;
    }

    for (const auto& item : m_keyed_values)
    {
        stream_tabs(stream, tab_index + 1);

        stream << "[";
        if (item.first)
            item.first->to_string(stream, tab_index + 1);
        else
            stream << "nil";
        
        stream << "] = ";

        if (item.second)
            item.second->to_string(stream, tab_index + 1);
        else
            stream << "nil";

        stream << "," << std::endl;
    }

    if (!m_indexed_values.empty() || !m_keyed_values.empty())
        stream_tabs(stream, tab_index);

    stream << "}";
}

}
