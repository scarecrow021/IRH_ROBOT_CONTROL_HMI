#include "../include/rapi_stream.h"

#include <limits>

namespace rapi
{

Stream::Stream()
{
}

Stream::~Stream()
{
}

size_t Stream::size()
{
	std::streampos cur_pos = m_stream.tellg();

	m_stream.seekg(0, std::ios::end);

	size_t size = m_stream.tellg();

	m_stream.seekg(cur_pos);

	return size;
}

void Stream::clear()
{
    m_stream = std::stringstream();
}

void Stream::write(const void* data, size_t size)
{
	m_stream.write((const char*)data, size);
}

void Stream::write_string(const std::string& str)
{
    // string length
    uint16_t size = (uint16_t)str.length();
    if (std::numeric_limits<uint16_t>::max() < str.length())
        size = std::numeric_limits<uint16_t>::max();

    write<uint16_t>(size);

    // string characters
    write(str.data(), size);
}

void Stream::read(void* data, size_t size)
{
	m_stream.read((char*)data, size);
}

std::string Stream::read_string()
{
    std::string str;

    uint16_t size = read<uint16_t>();

    str.reserve(size);

    for (int i = 0; i < (int)size; ++i)
        str.push_back(read<char>());

    return str;
}

}
