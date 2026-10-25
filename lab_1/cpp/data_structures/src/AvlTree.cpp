#include "AvlTree.h"

#include <algorithm>
#include <iostream>

namespace AvlTree {

int Height(Node* node) {
    return node == nullptr ? 0 : node->height;
}

int BalanceFactor(Node* node) {
    return node == nullptr ? 0 : Height(node->left) - Height(node->right);
}

void UpdateHeight(Node* node) {
    node->height = 1 + std::max(Height(node->left), Height(node->right));
}

Node* RotateRight(Node* y) {
    Node* x = y->left;
    Node* subtree = x->right;
    x->right = y;
    y->left = subtree;
    UpdateHeight(y);
    UpdateHeight(x);
    return x;
}

Node* RotateLeft(Node* x) {
    Node* y = x->right;
    Node* subtree = y->left;
    y->left = x;
    x->right = subtree;
    UpdateHeight(x);
    UpdateHeight(y);
    return y;
}

Node* Balance(Node* node) {
    if (node == nullptr) return nullptr;
    UpdateHeight(node);
    int factor = BalanceFactor(node);

    if (factor > 1) {
        if (BalanceFactor(node->left) < 0) node->left = RotateLeft(node->left);
        return RotateRight(node);
    }
    if (factor < -1) {
        if (BalanceFactor(node->right) > 0) node->right = RotateRight(node->right);
        return RotateLeft(node);
    }
    return node;
}

Node* InsertNode(Node* node, int value) {
    if (node == nullptr) return new Node{value, 1, nullptr, nullptr};
    if (value < node->value) node->left = InsertNode(node->left, value);
    else if (value > node->value) node->right = InsertNode(node->right, value);
    else return node;
    return Balance(node);
}

Node* Minimum(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

Node* RemoveNode(Node* node, int value) {
    if (node == nullptr) return nullptr;

    if (value < node->value) {
        node->left = RemoveNode(node->left, value);
    } else if (value > node->value) {
        node->right = RemoveNode(node->right, value);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* child = node->left != nullptr ? node->left : node->right;
            delete node;
            return child;
        }

        Node* successor = Minimum(node->right);
        node->value = successor->value;
        node->right = RemoveNode(node->right, successor->value);
    }
    return Balance(node);
}

void ReadPreOrder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->value << ' ';
    ReadPreOrder(node->left);
    ReadPreOrder(node->right);
}

void ClearNode(Node* node) {
    if (node == nullptr) return;
    ClearNode(node->left);
    ClearNode(node->right);
    delete node;
}

void Insert(AvlTree& tree, int value) {
    tree.root = InsertNode(tree.root, value);
}

Node* Find(const AvlTree& tree, int value) {
    Node* current = tree.root;
    while (current != nullptr) {
        if (current->value == value) return current;
        current = value < current->value ? current->left : current->right;
    }
    return nullptr;
}

int Remove(AvlTree& tree, int value) {
    tree.root = RemoveNode(tree.root, value);
    return value;
}

void Read(const AvlTree& tree) {
    ReadPreOrder(tree.root);
    std::cout << std::endl;
}

void Clear(AvlTree& tree) {
    ClearNode(tree.root);
    tree.root = nullptr;
}

}