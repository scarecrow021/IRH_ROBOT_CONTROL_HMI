#include "../include/rapi_nil.h"

namespace rapi
{

Value::Ptr Nil::create()
{
    return Value::Ptr(new Nil());
}

Nil::Nil()
    : Value(Type::Nil)
{
}

Nil::~Nil()
{
}

bool Nil::compare(const Value& other) const
{
    return other.type() == Type::Nil;
}

void Nil::to_string(std::stringstream& stream, int tab_index) const
{
    stream << "nil";
}

}
