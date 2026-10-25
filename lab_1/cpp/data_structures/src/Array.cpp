#include "Array.h"

#include <iostream>
#include <stdexcept>

namespace Array {

void Create(Array& array, size_t capacity) {
    Clear(array);
    array.data = new std::string[capacity];
    array.size = 0;
    array.capacity = capacity;
}

void Resize(Array& array, size_t new_capacity) {
    std::string* new_data = new std::string[new_capacity];
    for (size_t i = 0; i < array.size; ++i) {
        new_data[i] = array.data[i];
    }
    delete[] array.data;
    array.data = new_data;
    array.capacity = new_capacity;
}

void PushBack(Array& array, const std::string& value) {
    if (array.capacity == 0) Create(array, 1);
    if (array.size == array.capacity) Resize(array, array.capacity * 2);
    array.data[array.size++] = value;
}

void Insert(Array& array, size_t index, const std::string& value) {
    if (index > array.size) throw std::out_of_range("Invalid array index");
    if (array.capacity == 0) Create(array, 1);
    if (array.size == array.capacity) Resize(array, array.capacity * 2);

    for (size_t i = array.size; i > index; --i) {
        array.data[i] = array.data[i - 1];
    }
    array.data[index] = value;
    ++array.size;
}

const std::string& Get(const Array& array, size_t index) {
    if (index >= array.size) throw std::out_of_range("Invalid array index");
    return array.data[index];
}

void Set(Array& array, size_t index, const std::string& value) {
    if (index >= array.size) throw std::out_of_range("Invalid array index");
    array.data[index] = value;
}

std::string RemoveAt(Array& array, size_t index) {
    if (index >= array.size) throw std::out_of_range("Invalid array index");
    std::string removed = array.data[index];
    for (size_t i = index; i < array.size - 1; ++i) {
        array.data[i] = array.data[i + 1];
    }
    --array.size;
    return removed;
}

size_t Length(const Array& array) {
    return array.size;
}

void Read(const Array& array) {
    for (size_t i = 0; i < array.size; ++i) {
        std::cout << array.data[i] << ' ';
    }
    std::cout << std::endl;
}

void Clear(Array& array) {
    delete[] array.data;
    array.data = nullptr;
    array.size = 0;
    array.capacity = 0;
}

}