#pragma once

#include "rapi_value.h"

namespace rapi
{

class List : public Value
{
public:
    /*! \brief Create a new list.
     *
     * This create function takes a variable number of rapi::Value::Ptr's as arguments. 
     * These values are used to populate the list.
     * 
     * \param values Values to populate list with.
     * 
     * \returns a new list
     */
    template<typename... Ts> static Value::Ptr create(Ts&&... values)
    {
        Value::Ptr lst(new List());

        insert(*lst, std::move(values)...);

        return lst;
    }

private:
    // end of recursive insert
    static void insert(Value& lst)
    {
    }

    // recursive insert
    template<typename... Ts> static void insert(Value& lst, Value::Ptr&& value, Ts&&... values)
    {
        lst.insert(std::move(value));

        insert(lst, std::move(values)...);
    }

public:
    List();

    virtual void stream_to(Stream& stream) const override;
    virtual void stream_from(Stream& stream) override;

    virtual void insert(Value::Ptr&& value) override;

    virtual bool compare(const Value& other) const override;

    const Value::List& indexed_values() const override;

    const Value* find_value(const Value& key) const override;

    void to_string(std::stringstream& stream, int tab_index) const override;

private:
    Value::List m_values;
};

}
