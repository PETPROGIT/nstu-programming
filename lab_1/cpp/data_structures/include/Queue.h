#pragma once

#include <string>

namespace Queue {

struct Node {
    std::string value;
    Node* next = nullptr;
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
};

void Push(Queue& queue, const std::string& value);
std::string Pop(Queue& queue);
void Read(const Queue& queue);
void Clear(Queue& queue);

}