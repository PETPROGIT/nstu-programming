#pragma once

namespace AvlTree {

struct Node {
    int value;
    int height = 1;
    Node* left = nullptr;
    Node* right = nullptr;
};

struct AvlTree {
    Node* root = nullptr;
};

void Insert(AvlTree& tree, int value);
Node* Find(const AvlTree& tree, int value);
int Remove(AvlTree& tree, int value);
void Read(const AvlTree& tree);
void Clear(AvlTree& tree);


}