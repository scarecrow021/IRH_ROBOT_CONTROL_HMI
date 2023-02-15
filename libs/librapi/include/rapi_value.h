#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "rapi_type.h"
#include "rapi_stream.h"

namespace rapi
{
    /*! \brief Base class for rapi values.
     *
     * Base interface for all rapi value types.
     */
    class Value
    {
    public:
        //! \brief Value pointer.
        using Ptr          = std::unique_ptr<Value>;
        //! \brief Key value pair type used by tables.
        using KeyValuePair = std::pair<Ptr, Ptr>;
        //! \brief Value list type.
        using List         = std::vector<Ptr>;
        //! \brief Value table type.
        using Table        = std::vector<KeyValuePair>;

    public:
        /*! \brief Create value of specific type.
         *
         * This function will construct a zero initialized value of a specific type.
         *
         * \param type Value type
         *
         * \returns value
         */
        static Value::Ptr create(Type type);

        /*! \brief Write value to stream.
         *
         * This function will write a value to a binary stream. This is used to construct network packets.
         *
         * \param value The value to write.
         * \param stream Stream to write to.
         */
        static void stream_value_to(const Value& value, Stream& stream);

        /*! \brief Write value to stream.
        *
        * This function will write a value to a binary stream. This is used to construct network packets.
        *
        * \param value The value to write.
        * \param stream Stream to write to.
        */
        static void stream_value_to(const Value::Ptr& value, Stream& stream);

        /*! \brief Read value from stream.
         *
         * This function will extract a value from a stream. This is used to decode network packets.
         *
         * \param stream Stream to read value from.
         *
         * \returns Value extracted from stream.
         */
        static Value::Ptr stream_value_from(Stream& stream);
    
    protected:
        virtual void stream_to(Stream& stream) const;
        virtual void stream_from(Stream& stream);
    
    protected:
        Value(Type t)
            : m_type(t)
        {
        }

    public:
        virtual ~Value() {}
        
        //! \brief Get value type.
        Type type() const { return m_type; }

        //virtual void set(int64_t i)              = 0;
        //virtual void set(double d)               = 0;
        //virtual void set(const std::string& str) = 0;

        /*! \brief Insert value into list.
         *
         * This function will add a value to a list or table. All other value types will print an error when insert() is used.
         *
         * \param value Value to append to end of the list.
         */
        virtual void insert(Ptr&& value)                { std::cerr << "RAPIValue::insert(): operation not supported by value type!" << std::endl; }

        /*! \brief Insert key value pair into table.
         *
         * This function will insert a value into a table. You can only use this on values with Type::Table type.
         *
         * \param key_value The key value pair to add.
         */
        virtual void insert(KeyValuePair&& key_value)   { std::cerr << "RAPIValue::insert(): operation not supported by value type!" << std::endl; }

        /*! \brief Compare two values.
         *
         * This function will compare two values. 
         * The values do not have to have the exact same type, numbers can be compared to other numbers and tables which only contain a list can be compared to another list.
         * Char is a special case since it can't be compared to a number and is treated as a string with length 1.
         *
         * \param other Value to compare to.
         *
         * \returns true if both values are the same, false otherwise.
         */
        bool compare(const Ptr& other) const
        {
            if (other)
                return compare(*other);

            return false;
        }

        /*! \brief Check if value is Nil (not to be confused with null).
         * \returns true if this Nil.
         */
        virtual bool is_nil() const;

        /*! \brief Check if value type is Type::UniqueID.
         * \returns true if this is a unique id.
         */
        virtual bool is_unique_id() const;

        /*! \brief Check if value type is a number.
         *
         * This function will return true if the value type is a number. The following types are treated as numbers.
         * 
         * Type::Bool, Type::Int16, Type::Int32,, Type::UInt8, Type::UInt16, Type::UInt32, Type::Float, Type::Double.
         *
         *  \returns true if this is a number.
         */
        virtual bool is_number()    const;

        /*! \brief Check if value has string type.
        *
        * This function will return true if the value is of a string type. Note that a Type::Char is also treated as a string with length 1.
        *
        * \returns True if type is Type::String or Type::Char.
        */
        virtual bool is_string()    const;

        /*! \brief Check if value is a list.
         *
         * \returns true if type is Type::List
         */
        virtual bool is_list()      const;

        /*! \brief Check if value is a table.
         *
         * \returns true if type is Type::List
         */
        virtual bool is_table()     const;

        /*! \brief Compare two values.
        *
        * This function will compare two values.
        * The values do not have to have the exact same type, numbers can be compared to other numbers and tables which only contain a list can be compared to another list.
        * Char is a special case since it can't be compared to a number and is treated as a string with length 1.
        *
        * \param other Value to compare to.
        *
        * \returns true if both values are the same, false otherwise.
        */
        virtual bool compare(const Value& other) const = 0;

        /*! \brief Get value as signed integer.
         *
         * This function will return the value as a signed integer. This will work for all numeric types.
         * If this is a foating point type (Type::Float, Type::Double) it is cast to a integer (same effect as floor(value)).
         *
         * \returns Signed integer value.
         */
        virtual int64_t     as_int()          const { return 0; }

        /*! \brief Get value as unsigned integer.
         *
         * This function will return the value as a unsigned integer. If the value is a signed integer the unsigned version is returned using a C style cast.
         *
         * \returns Unsigned integer value.
         */
        virtual uint64_t    as_uint()         const { return 0; }

        /*! \brief Get value as floating point number.
         * 
         * This function returns the value as a floating point number. This works for all numeric types.
         *
         * \returns Floating point value.
         */
        virtual double      as_double()       const { return 0; }

        /*! \brief Get value as string.
         *
         * This function returns the string representation of the value. 
         * For String this is the actual string, for Char this is a string with length 1 and all numertic types will be converted using std::to_string().
         *
         * \returns String representation of value.
         */
        virtual std::string as_string()       const { return std::string(); }

        /*! \brief Get vmx_id component of UniqueID.
         *
         * A UniqueID consists of three components, the vmx_id, the basic_id and a occurance_id.
         *
         * \returns vmx_id if this value is a UniqueID, zero otherwise.
         */
        virtual uint32_t vmx_id()        const { return 0; }

        /*! \brief Get basic_id component of UniqueID.
         *
         * A UniqueID consists of three components, the vmx_id, the basic_id and a occurance_id.
         *
         * \returns basic_id if this value is a UniqueID, zero otherwise.
         */
        virtual uint32_t basic_id()      const { return 0; }

        /*! \brief Get occurrance_id component of UniqueID.
         *
         * A UniqueID consists of three components, the vmx_id, the basic_id and a occurance_id.
         *
         * \returns occurance_id if this value is a UniqueID, zero otherwise.
         */
        virtual uint32_t occurrance_id() const { return 0; }

        /*! \brief Get list of values.
         *
         * For List this function will return all the elements, for Table we return the List part of a table.
         * The returned list is non-mutable.
         *
         * \returns List of values contained by this value.
         */
        virtual const Value::List&  indexed_values() const { static List lst;  return lst; }

        /*! \brief Get table of values.
         *
         * This function returns all key-value pairs in a Table. The Table is non-mutable and one should never modify the Key value!
         * If the key of a key value pair is modified there is a possibility that the Table will contain duplicate keys.
         *
         * \returns List of key-value pairs in Table.
         */
        virtual const Value::Table& keyed_values()   const { static Table tab; return tab; }

        /*! \brief Get item in table.
         *
         * Warning: rapi value comparison is not finished yet! not all tables can be used as a key, basic values work fine!
         * 
         * This function can be used to find items in lists and tables.
         * 
         * \param key Find value for this key
         * 
         * \returns Value for key or nullptr if key can't be found
         * 
         */
        virtual const Value* find_value(const Value& key) const { return nullptr; }


        /*! \brief Get item in table.
         *
         * Warning: rapi value comparison is not finished yet! not all tables can be used as a key, basic values work fine!
         *
         * This function can be used to find items in lists and tables.
         *
         * \param key Find value for this key
         *
         * \returns Value for key or nullptr if key can't be found
         *
         */
        virtual const Value* find_value(const Value::Ptr& key) const { if (!key) return nullptr; return find_value(*key); }


        /*! \brief Get item in table.
         *
         * Warning: rapi value comparison is not finished yet! not all tables can be used as a key, basic values work fine!
         *
         * This function can be used to find items in lists and tables.
         *
         * \param key Find value for this key
         *
         * \returns Value for key or nullptr if key can't be found
         *
         */
        virtual const Value* find_value(const std::string& key) const;


        /*! \brief Get item in table.
         *
         * Warning: rapi value comparison is not finished yet! not all tables can be used as a key, basic values work fine!
         *
         * This function can be used to find items in lists and tables.
         *
         * \param idx Find value for this key (index in list)
         *
         * \returns Value for key or nullptr if key can't be found
         *
         */
        virtual const Value* find_value(size_t idx) const;

        /*! \brief Convert value to a human readable string.
         *
         * This function can be used to write a human readable version of the value to a std::stringstream.
         * The resulting string can be used to display the value in a human readable form.
         *
         * \param stream Stream to write value to.
         * \param tab_index Number of tab indentations used to print nested values in lists and tables.
         */
        virtual void to_string(std::stringstream& stream, int tab_index) const = 0;

    protected:
        const Type m_type;
    };

}



