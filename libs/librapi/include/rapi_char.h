#pragma once

#include "rapi_value.h"

namespace rapi
{
    /*! \brief Single character value container.
     *
     * This Value instance can hold a single character. Since lua doesn't have the Char concept we treat Char as a string with length 1.
     */
    class Char : public Value
    {
    public:
        /*! \brief Create a new Char value.
         *
         * \param ch The character value.
         */
        static Value::Ptr create(char ch);

    public:
        Char();
        explicit Char(char ch);
        virtual ~Char();

    protected:
        virtual void stream_to(Stream& stream) const override;
        virtual void stream_from(Stream& stream) override;

        virtual bool compare(const Value& other) const override;

        virtual int64_t     as_int()    const override;
        virtual uint64_t    as_uint()   const override;
        virtual double      as_double() const override;
        virtual std::string as_string() const override;

        virtual void to_string(std::stringstream& stream, int tab_index) const override;

    private:
        char m_value;
    };
}
