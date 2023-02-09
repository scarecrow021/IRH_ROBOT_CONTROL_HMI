#pragma once

#include "rapi_value.h"

namespace rapi
{

    class String : public Value
    {
    public:
        /*! \brief Create a new string value.
         *
         * \param str Contents of new string.
         * 
         * \returns String value.
         */
        static Value::Ptr create(const std::string& str);

    public:
        String();
        explicit String(const std::string& str);
        virtual ~String();
    
    protected:
        virtual void stream_to(Stream& stream) const override;
        virtual void stream_from(Stream& stream) override;

        virtual bool compare(const Value& other) const override;

        virtual std::string as_string() const override;

        virtual void to_string(std::stringstream& stream, int tab_index) const override;
    
    private:
        std::string m_value;
    };

}