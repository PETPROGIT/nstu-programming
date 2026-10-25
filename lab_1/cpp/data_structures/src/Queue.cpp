#include "Queue.h"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace Queue {

void Push(Queue& queue, const std::string& value) {
    Node* new_node = new Node{value, nullptr};
    if (queue.tail == nullptr) {
        queue.head = new_node;
        queue.tail = new_node;
    } else {
        queue.tail->next = new_node;
        queue.tail = new_node;
    }
}

std::string Pop(Queue& queue) {
    if (queue.head == nullptr) throw std::out_of_range("Queue is empty");
    Node* to_delete = queue.head;
    std::string value = to_delete->value;
    queue.head = queue.head->next;
    if (queue.head == nullptr) queue.tail = nullptr;
    delete to_delete;
    return value;
}

void Read(const Queue& queue) {
    Node* current = queue.head;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}

void Clear(Queue& queue) {
    while (queue.head != nullptr) Pop(queue);
}

}