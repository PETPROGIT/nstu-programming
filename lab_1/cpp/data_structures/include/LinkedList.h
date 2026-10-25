#pragma once

#include <string>

namespace LinkedList {

struct Node {
    std::string value;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
};

void PushFront(LinkedList& list, const std::string& value);
void PushBack(LinkedList& list, const std::string& value);
void InsertBefore(LinkedList& list, const std::string& before_value, const std::string& value);
void InsertAfter(LinkedList& list, const std::string& after_value, const std::string& value);

std::string PopFront(LinkedList& list);
std::string PopBack(LinkedList& list);
std::string RemoveBefore(LinkedList& list, const std::string& before_value);
std::string RemoveAfter(LinkedList& list, const std::string& after_value);
std::string Remove(LinkedList& list, const std::string& value);

Node* Find(const LinkedList& list, const std::string& value);
void Read(const LinkedList& list);
void ReadReverse(const LinkedList& list);
void Clear(LinkedList& list);

}