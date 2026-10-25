#include "LinkedList.h"

#include <iostream>

namespace LinkedList {

void PushFront(LinkedList& list, const std::string& value) {
    Node* new_node = new Node{value, list.head, nullptr};
    if (list.head != nullptr) list.head->prev = new_node;
    else list.tail = new_node;
    list.head = new_node;
}

void PushBack(LinkedList& list, const std::string& value) {
    Node* new_node = new Node{value, nullptr, list.tail};
    if (list.tail != nullptr) list.tail->next = new_node;
    else list.head = new_node;
    list.tail = new_node;
}

Node* Find(const LinkedList& list, const std::string& value) {
    Node* current = list.head;
    while (current != nullptr) {
        if (current->value == value) return current;
        current = current->next;
    }
    return nullptr;
}

void InsertBefore(LinkedList& list, const std::string& before_value, const std::string& value) {
    Node* current = Find(list, before_value);
    if (current == nullptr) return;
    if (current == list.head) {
        PushFront(list, value);
        return;
    }

    Node* new_node = new Node{value, current, current->prev};
    current->prev->next = new_node;
    current->prev = new_node;
}

void InsertAfter(LinkedList& list, const std::string& after_value, const std::string& value) {
    Node* current = Find(list, after_value);
    if (current == nullptr) return;
    if (current == list.tail) {
        PushBack(list, value);
        return;
    }

    Node* new_node = new Node{value, current->next, current};
    current->next->prev = new_node;
    current->next = new_node;
}

std::string PopFront(LinkedList& list) {
    if (list.head == nullptr) return "";
    Node* to_delete = list.head;
    std::string value = to_delete->value;
    list.head = list.head->next;
    if (list.head != nullptr) list.head->prev = nullptr;
    else list.tail = nullptr;
    delete to_delete;
    return value;
}

std::string PopBack(LinkedList& list) {
    if (list.tail == nullptr) return "";
    Node* to_delete = list.tail;
    std::string value = to_delete->value;
    list.tail = list.tail->prev;
    if (list.tail != nullptr) list.tail->next = nullptr;
    else list.head = nullptr;
    delete to_delete;
    return value;
}

std::string RemoveBefore(LinkedList& list, const std::string& before_value) {
    Node* current = Find(list, before_value);
    if (current == nullptr || current->prev == nullptr) return "";
    if (current->prev == list.head) {
        return PopFront(list);
    }
    Node* to_delete = current->prev;
    std::string value = to_delete->value;
    to_delete->prev->next = current;
    current->prev = to_delete->prev;
    delete to_delete;
    return value;
}

std::string RemoveAfter(LinkedList& list, const std::string& after_value) {
    Node* current = Find(list, after_value);
    if (current == nullptr || current->next == nullptr) return "";
    if (current->next == list.tail) {
        return PopBack(list);
    }
    Node* to_delete = current->next;
    std::string value = to_delete->value;
    current->next = to_delete->next;
    to_delete->next->prev = current;
    delete to_delete;
    return value;
}

std::string Remove(LinkedList& list, const std::string& value) {
    Node* current = Find(list, value);
    if (current == nullptr) return "";
    if (current == list.head) {
        return PopFront(list);
    }
    if (current == list.tail) {
        return PopBack(list);
    }
    std::string removed = current->value;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return removed;
}

void Read(const LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}

void ReadReverse(const LinkedList& list) {
    Node* current = list.tail;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->prev;
    }
    std::cout << std::endl;
}

void Clear(LinkedList& list) {
    while (list.head != nullptr) PopFront(list);
}

}