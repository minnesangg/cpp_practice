#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>

namespace minnesang {

    template <typename T>
    class Vector {
    private:
        T* arr;
        size_t capacity;
        size_t size;

        void resize(size_t new_capacity);

    public:
        Vector();
        ~Vector();

        void push_back(const T& value);
        void pop_back();
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        size_t get_size() const;
        bool is_empty() const;
        void clear();
        void shrink_to_fit();
        void insert(size_t index, const T& value);
        void erase(size_t index);
    };

} 

#include "vector_impl.h"

#endif