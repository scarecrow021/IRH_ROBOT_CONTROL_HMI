#pragma once

#include "rapi_value.h"

namespace rapi
{
    /*! \brief Lua table datastructure
     * 
     * This value represents a lua table. Lua tables consist of a vector and a map.
     */
    class Table : public Value
    {
    public:
        /*! \brief Create empty table.
         */
        static Value::Ptr create();

        /*! \brief Create a new table.
         *
         * In lua tables are a combination of a vector and a map. So we have indexed items and keyed items.
         * The variable arguments can either be of type rapi::Value::Ptr or a std::pair<rapi::Value::Ptr, rapi::Value::Ptr>.
         * Value::Ptr's are added to the vector part of the table, the std::pair's are added to the map (first element is key, second element is value).
         * 
         * \param values Indexed and keyed contents of the table.
         * 
         * \returns A new table.
         */
        template<typename... Ts> static Value::Ptr create(Ts&&... values)
        {
            Value::Ptr table(new Table());

            insert(*table, std::move(values)...);

            return table;
        }

    private:
        // end of insert recursion
        static void insert(Value& table)
        {
        }

        // indexed item recursive insert
        template<typename... Ts> static void insert(Value& table, Value::Ptr&& indexed_value, Ts&&... values)
        {
            table.insert(std::move(indexed_value));

            insert(table, std::move(values)...);
        }

        // key value pair recursive insert
        template<typename... Ts> static void insert(Value& table, Value::KeyValuePair&& key_value, Ts&&... values)
        {
            table.insert(std::move(key_value));

            insert(table, std::move(values)...);
        }

    public:
        Table();
        virtual ~Table();

        virtual void stream_to(Stream& stream) const override;
        virtual void stream_from(Stream& stream) override;

        virtual void insert(Value::Ptr&& value) override;
        virtual void insert(Value::KeyValuePair&& key_value) override;

        virtual bool compare(const Value& other) const override;

        virtual const Value::List&  indexed_values() const override;
        virtual const Value::Table& keyed_values()   const override;

        virtual const Value* find_value(const Value& key) const override;

        virtual void to_string(std::stringstream& stream, int tab_index) const override;

    private:
        Value::List  m_indexed_values;
        Value::Table m_keyed_values;
    };

}
