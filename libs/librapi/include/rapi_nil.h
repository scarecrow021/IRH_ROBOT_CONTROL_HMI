#pragma once

#include "rapi_value.h"

namespace rapi
{

    class Nil : public Value
    {
    public:
        /*! \brief Create nil.
         */
        static Value::Ptr create();

    public:
        Nil();
        virtual ~Nil();

        virtual bool compare(const Value& other) const;

        virtual void to_string(std::stringstream& stream, int tab_index) const override;
    };

}
