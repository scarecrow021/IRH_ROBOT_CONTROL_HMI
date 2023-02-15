#pragma once

#include "rapi_value.h"

namespace rapi
{
    class UniqueID : public Value
    {
    public:
        /*! \brief Construct an unique id.
         *
         * This function creates an unique id from it's basic components. In order to get the unique id for an object execute the vmxGetObjectHandle() function using the rapi::Client.
         * Unique id are determined while loading a model and can be different each time, hard coding unique id's should be avoided.
         * 
         * \param vmx_id The vmx id.
         * \param basic_id The basic id.
         * \param occurrance_id The occurrance id.
         */
        static Value::Ptr create(uint32_t vmx_id, uint32_t basic_id, uint32_t occurrance_id);

    public:
        UniqueID();
        explicit UniqueID(uint32_t vmx_id, uint32_t basic_id, uint32_t occurrance_id);
        virtual ~UniqueID();

        virtual void stream_to(Stream& stream) const override;
        virtual void stream_from(Stream& stream) override;

        virtual bool compare(const Value& other) const override;

        virtual uint32_t vmx_id()        const override { return m_vmx_id; }
        virtual uint32_t basic_id()      const override { return m_basic_id; }
        virtual uint32_t occurrance_id() const override { return m_occurrance_id; }


        void to_string(std::stringstream& stream, int tab_index) const override;

        virtual std::string as_string() const override;

    private:
        uint32_t m_vmx_id;
        uint32_t m_basic_id;
        uint32_t m_occurrance_id;
    };
}
