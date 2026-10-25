#pragma once

#include <string>

namespace ForwardList {

struct Node {
    std::string value;
    Node* next = nullptr;
};

struct ForwardList {
    Node* head = nullptr;
};

void PushFront(ForwardList& forward_list, const std::string& value);
void PushBack(ForwardList& forward_list, const std::string& value);
void InsertBefore(ForwardList& forward_list, const std::string& before_value, const std::string& value);
void InsertAfter(ForwardList& forward_list, const std::string& after_value, const std::string& value);

std::string PopFront(ForwardList& forward_list);
std::string PopBack(ForwardList& forward_list);
std::string RemoveBefore(ForwardList& forward_list, const std::string& before_value);
std::string RemoveAfter(ForwardList& forward_list, const std::string& after_value);
std::string Remove(ForwardList& forward_list, const std::string& value);

Node* Find(const ForwardList& forward_list, const std::string& value);

void Read(const ForwardList& forward_list);
void Clear(ForwardList& forward_list);

}