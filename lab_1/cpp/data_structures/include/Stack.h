#pragma once

#include <string>

namespace Stack {

struct Node {
    std::string value;
    Node* next = nullptr;
};

struct Stack {
    Node* top = nullptr;
};

void Push(Stack& stack, const std::string& value);
std::string Pop(Stack& stack);
void Read(const Stack& stack);
void Clear(Stack& stack);

}