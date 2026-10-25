#include "Stack.h"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace Stack {

void Push(Stack& stack, const std::string& value) {
    stack.top = new Node{value, stack.top};
}

std::string Pop(Stack& stack) {
    if (stack.top == nullptr) throw std::out_of_range("Stack is empty");
    Node* to_delete = stack.top;
    std::string value = to_delete->value;
    stack.top = to_delete->next;
    delete to_delete;
    return value;
}

void Read(const Stack& stack) {
    Node* current = stack.top;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}

void Clear(Stack& stack) {
    while (stack.top != nullptr) Pop(stack);
}

}