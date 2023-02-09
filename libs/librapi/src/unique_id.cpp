#include "../include/rapi_unique_id.h"

namespace rapi
{

Value::Ptr UniqueID::create(uint32_t vmx_id, uint32_t basic_id, uint32_t occurrance_id)
{
    return Value::Ptr(new UniqueID(vmx_id, basic_id, occurrance_id));
}

UniqueID::UniqueID()
    : Value(Type::UniqueID)
    , m_vmx_id(0)
    , m_basic_id(0)
    , m_occurrance_id(0)
{
}

UniqueID::UniqueID(uint32_t vmx_id, uint32_t basic_id, uint32_t occurrance_id)
    : Value(Type::UniqueID)
    , m_vmx_id(vmx_id)
    , m_basic_id(basic_id)
    , m_occurrance_id(occurrance_id)
{
}

UniqueID::~UniqueID()
{
}

void UniqueID::stream_to(Stream& stream) const
{
    Value::stream_to(stream);

    stream.write<uint32_t>(m_vmx_id);
    stream.write<uint32_t>(m_basic_id);
    stream.write<uint32_t>(m_occurrance_id);
}

void UniqueID::stream_from(Stream& stream)
{
    Value::stream_from(stream);

    m_vmx_id        = stream.read<uint32_t>();
    m_basic_id      = stream.read<uint32_t>();
    m_occurrance_id = stream.read<uint32_t>();
}

bool UniqueID::compare(const Value& other) const
{
    if (!other.is_unique_id())
        return false;

    return vmx_id() == other.vmx_id() && basic_id() == other.basic_id() && occurrance_id() == other.occurrance_id();
}

void UniqueID::to_string(std::stringstream& stream, int tab_index) const
{
    stream << as_string();
}

std::string UniqueID::as_string() const
{
    return "(" + std::to_string(m_vmx_id) + ", " + std::to_string(m_basic_id) + ", " + std::to_string(m_occurrance_id) + ")";
}

}
