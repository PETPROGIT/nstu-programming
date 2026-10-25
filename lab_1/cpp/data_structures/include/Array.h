#pragma once

#include <cstddef>
#include <string>

namespace Array {

struct Array {
    std::string* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};

void Create(Array& array, size_t capacity);
void PushBack(Array& array, const std::string& value);
void Insert(Array& array, size_t index, const std::string& value);
const std::string& Get(const Array& array, size_t index);
void Set(Array& array, size_t index, const std::string& value);
std::string RemoveAt(Array& array, size_t index);
size_t Length(const Array& array);
void Read(const Array& array);
void Clear(Array& array);

}