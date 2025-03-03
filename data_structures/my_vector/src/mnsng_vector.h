#ifndef MINNESANG_VECTOR_H
#define MINNESANG_VECTOR_H

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
        Vector(const Vector<T>& other);
        Vector(Vector<T>&& other) noexcept;
        ~Vector();

        T* begin();
        T* end();
        const T* begin() const;
        const T* end() const;
        
        T* rbegin();
        T* rend();
        const T* rbegin() const;
        const T* rend() const;

        void push_back(const T& value);
        void pop_back();
        size_t get_size() const;
        size_t get_capacity() const;
        int index_of(const T& value) const;
        void clear();

        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        Vector<T>& operator=(const Vector<T>& other);
        Vector<T>& operator=(Vector<T>&& other) noexcept;
        Vector<T> operator+(const Vector<T>& other) const;
        Vector<T>& operator +=(const Vector<T>& other);

        void shrink_to_fit();

        void insert(size_t index, const T& value);
        void erase(size_t index);
        void remove(const T& value);
        void assign(size_t count, const T& value);

        const T& front();
        const T& back();

        bool is_empty() const;
        bool is_sorted() const;
        bool is_sorted_increasly() const;
        bool is_sorted_decreasly() const;
        bool contains(const T& value) const;

        int binary_search(const T& value);
        void quickSort(size_t left, size_t right);
        void reverse();
    };

}

#include "mnsng_vector_impl.h"

#endif