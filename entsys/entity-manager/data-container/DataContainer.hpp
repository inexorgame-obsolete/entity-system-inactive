// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
#define INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER

#include <string>
#include <cstdint>
#include "DataTypes.hpp"

namespace inexor {
namespace entsys {
        
    /// A flexible, multiple purpose data container.
    class DataContainer
    {
        private:
            ENTSYS_DATA_TYPE data_container_data_type;

            std::string string_data;
            std::int64_t int_data;

            double double_data;
            float float_data;
            bool boolean_data;

        protected:
            void reset_memory();
            bool data_container_is_numeric();

        public:

            // Overloaded constructors for fast initialization.
            DataContainer(ENTSYS_DATA_TYPE);
            DataContainer(std::int64_t);
            DataContainer(double);
            DataContainer(float);
            DataContainer(bool);
            DataContainer(std::string);

            ~DataContainer();

            // Set methods.
            void set(std::int64_t);
            void set(double);
            void set(float);
            void set(bool);
            void set(std::string);
            
            // TODO: DISCUSS: Do all methods have to be of const type?

            // Math operations.
            const DataContainer add(const DataContainer&);
            const DataContainer sub(const DataContainer&);
            const DataContainer mul(const DataContainer&);
            const DataContainer div(const DataContainer&);

            // Overloaded operators.
            DataContainer operator+(const DataContainer&);
            DataContainer operator-(const DataContainer&);
            DataContainer operator*(const DataContainer&);
            DataContainer operator/(const DataContainer&);

            // Get methods.
            const std::int64_t get_intval() const;
            const double get_doubleval() const;
            const float get_floatval() const;
            const bool get_boolval() const;
            const std::string get_stringval() const;

            const ENTSYS_DATA_TYPE get_data_type() const;

    };

};
};

#endif // INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
