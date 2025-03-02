#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

namespace minnesang {

    template <typename T>
    Vector<T>::Vector() : size(0), capacity(10) {
        arr = new T[capacity];
    }

    template <typename T>
    Vector<T>::~Vector() {
        delete[] arr;
    }

    template <typename T>
    void Vector<T>::resize(size_t new_capacity) {
        T* new_arr = new T[new_capacity];

        for (size_t i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

    template <typename T>
    void Vector<T>::push_back(const T& value) {
        if (size == capacity) {
            resize(2 * capacity);
        }
        arr[size++] = value;
    }

    template <typename T>
    void Vector<T>::pop_back() {
        if (size == 0) {
            throw std::runtime_error("Cannot pop from an empty vector");
        }
        size--;
    }

    template <typename T>
    T& Vector<T>::operator[](size_t index) {
        if (index >= size) {
            throw std::runtime_error("Index out of bounds");
        }
        return arr[index];
    }

    template <typename T>
    const T& Vector<T>::operator[](size_t index) const {
        if (index >= size) {
            throw std::runtime_error("Index out of bounds");
        }
        return arr[index];
    }

    template <typename T>
    size_t Vector<T>::get_size() const {
        return size;
    }

    template <typename T>
    bool Vector<T>::is_empty() const {
        return size == 0;
    }

    template <typename T>
    void Vector<T>::clear() {
        size = 0;
    }

    template <typename T>
    void Vector<T>::shrink_to_fit() {
        if (capacity > size) {
            resize(size);
        }
    }

    template <typename T>
    void Vector<T>::insert(size_t index, const T& value) {
        if (index > size) {
            throw std::runtime_error("Index out of bounds");
        }
        if (size == capacity) {
            resize(2 * capacity);
        }

        for (size_t i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    template <typename T>
    void Vector<T>::erase(size_t index) {
        if (index >= size) {
            throw std::runtime_error("Index out of bounds");
        }

        for (size_t i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

} 

#endif
