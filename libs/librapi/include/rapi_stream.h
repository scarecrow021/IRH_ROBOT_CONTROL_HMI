#pragma once

#include <sstream>

namespace rapi
{

    class Stream
    {
    public:
        Stream(const Stream&) = delete;

        Stream();
        virtual ~Stream();

        size_t size();

        void clear();

        void write(const void* data, size_t size);

        void write_string(const std::string& str);

        template<typename T> void write(T v)
        {
            m_stream.write((const char*)&v, sizeof(T));
        }

        void read(void* data, size_t size);

        std::string read_string();

        template<typename T> T read()
        {
            T v = {};
            m_stream.read((char*)&v, sizeof(T));
            return v;
        }


    private:
        std::stringstream m_stream;
    };

}