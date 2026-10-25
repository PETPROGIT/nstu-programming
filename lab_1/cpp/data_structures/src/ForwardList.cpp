#include "ForwardList.h"

#include <iostream>

namespace ForwardList {

void PushFront(ForwardList& forward_list, const std::string& value) {
    Node* new_node = new Node{value, forward_list.head};
    forward_list.head = new_node;
}

void PushBack(ForwardList& forward_list, const std::string& value) {
    Node* new_node = new Node{value, nullptr};
    if (forward_list.head == nullptr) {
        forward_list.head = new_node;
        return;
    }

    Node* current = forward_list.head;
    while (current->next != nullptr) current = current->next;
    current->next = new_node;
}

void InsertBefore(ForwardList& forward_list, const std::string& before_value, const std::string& value) {
    if (forward_list.head == nullptr) return;

    if (forward_list.head->value == before_value) {
        PushFront(forward_list, value);
        return;
    }

    Node* current = forward_list.head;
    while (current->next != nullptr) {
        if (current->next->value == before_value) {
            current->next = new Node{value, current->next};
            return;
        }
        current = current->next;
    }
}

void InsertAfter(ForwardList& forward_list, const std::string& after_value, const std::string& value) {
    Node* current = forward_list.head;
    while (current != nullptr) {
        if (current->value == after_value) {
            current->next = new Node{value, current->next};
            return;
        }
        current = current->next;
    }
}

std::string PopFront(ForwardList& forward_list) {
    if (forward_list.head == nullptr) return "";
    Node* to_delete = forward_list.head;
    std::string value = to_delete->value;
    forward_list.head = forward_list.head->next;
    delete to_delete;
    return value;
}

std::string PopBack(ForwardList& forward_list) {
    if (forward_list.head == nullptr) return "";

    if (forward_list.head->next == nullptr) {
        std::string value = forward_list.head->value;
        delete forward_list.head;
        forward_list.head = nullptr;
        return value;
    }

    Node* current = forward_list.head;
    while (current->next->next != nullptr) current = current->next;
    std::string value = current->next->value;
    delete current->next;
    current->next = nullptr;
    return value;
}

std::string RemoveBefore(ForwardList& forward_list, const std::string& before_value) {
    if (forward_list.head == nullptr || forward_list.head->next == nullptr) return "";

    if (forward_list.head->next->value == before_value) {
        return PopFront(forward_list);
    }

    Node* current = forward_list.head;
    while (current->next != nullptr && current->next->next != nullptr) {
        if (current->next->next->value == before_value) {
            Node* to_delete = current->next;
            std::string value = to_delete->value;
            current->next = current->next->next;
            delete to_delete;
            return value;
        }
        current = current->next;
    }
    return "";
}

std::string RemoveAfter(ForwardList& forward_list, const std::string& after_value) {
    Node* current = forward_list.head;
    while (current != nullptr) {
        if (current->value == after_value) {
            if (current->next != nullptr) {
                Node* to_delete = current->next;
                std::string value = to_delete->value;
                current->next = to_delete->next;
                delete to_delete;
                return value;
            }
            return "";
        }
        current = current->next;
    }
    return "";
}

std::string Remove(ForwardList& forward_list, const std::string& value) {
    if (forward_list.head == nullptr) return "";

    if (forward_list.head->value == value) {
        return PopFront(forward_list);
    }

    Node* current = forward_list.head;
    while (current->next != nullptr) {
        if (current->next->value == value) {
            Node* to_delete = current->next;
            std::string removed = to_delete->value;
            current->next = to_delete->next;
            delete to_delete;
            return removed;
        }
        current = current->next;
    }
    return "";
}

Node* Find(const ForwardList& forward_list, const std::string& value) {
    Node* current = forward_list.head;
    while (current != nullptr) {
        if (current->value == value) return current;
        current = current->next;
    }
    return nullptr;
}

void Read(const ForwardList& forward_list) {
    Node* current = forward_list.head;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}

void Clear(ForwardList& forward_list) {
    while (forward_list.head != nullptr) PopFront(forward_list);
}

}