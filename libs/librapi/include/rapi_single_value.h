#pragma once

#include "rapi_value.h"

namespace rapi
{

    template<Type Tid, typename T> class SingleValue : public Value
    {
    public:
        /*! \brief Create a new value.
         *
         * \param value The new rapi::Value's value.
         */
        static Value::Ptr create(T value)
        {
            return Value::Ptr(new SingleValue(value));
        }

    public:
        SingleValue()
            : Value(Tid)
            , m_value(0)
        {
        }

        explicit SingleValue(T v)
            : Value(Tid)
            , m_value(v)
        {
        }

        virtual void stream_to(Stream& stream) const override
        {
            Value::stream_to(stream);

            stream.write<T>(m_value);
        }

        virtual void stream_from(Stream& stream) override
        {
            Value::stream_from(stream);

            m_value = stream.read<T>();
        }

        virtual bool compare(const Value& other) const override
        {
            if (!other.is_number())
                return false;

            return as_double() == other.as_double();
        }

        virtual void to_string(std::stringstream& stream, int tab_index) const override
        {
            stream << (double)m_value;
        }

        virtual int64_t as_int() const override
        {
            return (int64_t)m_value;
        }

        virtual uint64_t as_uint() const override
        {
            return (uint64_t)m_value;
        }

        virtual double as_double() const override
        {
            return (double)m_value;
        }

        virtual std::string as_string() const override
        {
            return std::to_string(as_double());
        }

    private:
        T m_value;
    };

    using Bool   = SingleValue<Type::Bool,   int8_t>;
    using UInt8  = SingleValue<Type::UInt8,  uint8_t>;
    using Int16  = SingleValue<Type::Int16,  int16_t>;
    using UInt16 = SingleValue<Type::UInt16, uint16_t>;
    using Int32  = SingleValue<Type::Int32,  int32_t>;
    using UInt32 = SingleValue<Type::UInt32, uint32_t>;
    using Float  = SingleValue<Type::Float,  float>;
    using Double = SingleValue<Type::Double, double>;
}
