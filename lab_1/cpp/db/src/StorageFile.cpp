#include "StorageFile.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace Db {

void SaveArray(Array::Array& a, std::ostream& out) {
    for (size_t i = 0; i < a.size; ++i) out << ' ' << a.data[i];
}

void SaveForwardList(ForwardList::ForwardList& l, std::ostream& out) {
    for (auto* n = l.head; n; n = n->next) out << ' ' << n->value;
}

void SaveLinkedList(LinkedList::LinkedList& l, std::ostream& out) {
    for (auto* n = l.head; n; n = n->next) out << ' ' << n->value;
}

void SaveQueue(Queue::Queue& q, std::ostream& out) {
    for (auto* n = q.head; n; n = n->next) out << ' ' << n->value;
}

void SaveStack(Stack::Stack& s, std::ostream& out) {
    for (auto* n = s.top; n; n = n->next) out << ' ' << n->value;
}

void SaveTree(AvlTree::Node* n, std::ostream& out) {
    if (!n) { out << " #"; return; }
    out << ' ' << n->value;
    SaveTree(n->left, out);
    SaveTree(n->right, out);
}

AvlTree::Node* BuildTree(std::istream& in) {
    std::string tok;
    in >> tok;
    if (tok == "#") return nullptr;
    AvlTree::Node* n = new AvlTree::Node{std::stoi(tok)};
    n->left = BuildTree(in);
    n->right = BuildTree(in);
    int hl = n->left ? n->left->height : 0;
    int hr = n->right ? n->right->height : 0;
    n->height = 1 + (hl > hr ? hl : hr);
    return n;
}

void SaveToFile(const std::string& path, Storage& st) {
    std::ofstream f(path);
    for (auto& p : st.arrays) { f << "M " << p.first; SaveArray(p.second, f); f << '\n'; }
    for (auto& p : st.flists) { f << "F " << p.first; SaveForwardList(p.second, f); f << '\n'; }
    for (auto& p : st.llists) { f << "L " << p.first; SaveLinkedList(p.second, f); f << '\n'; }
    for (auto& p : st.queues) { f << "Q " << p.first; SaveQueue(p.second, f); f << '\n'; }
    for (auto& p : st.stacks) { f << "S " << p.first; SaveStack(p.second, f); f << '\n'; }
    for (auto& p : st.trees)  { f << "T " << p.first; SaveTree(p.second.root, f); f << '\n'; }
}

void LoadFromFile(const std::string& path, Storage& st) {
    std::ifstream f(path);
    if (!f.is_open()) return;
    std::string line;
    while (std::getline(f, line)) {
        std::istringstream iss(line);
        std::string type, name;
        if (!(iss >> type >> name)) continue;
        std::vector<std::string> elems;
        std::string e;
        while (iss >> e) elems.push_back(e);

        if (type == "M") {
            Array::Array a;
            Array::Create(a, elems.empty() ? 1 : elems.size() * 2);
            for (auto& x : elems) Array::PushBack(a, x);
            st.arrays[name] = a;
        } else if (type == "F") {
            ForwardList::ForwardList l;
            for (auto& x : elems) ForwardList::PushBack(l, x);
            st.flists[name] = l;
        } else if (type == "L") {
            LinkedList::LinkedList l;
            for (auto& x : elems) LinkedList::PushBack(l, x);
            st.llists[name] = l;
        } else if (type == "Q") {
            Queue::Queue q;
            for (auto& x : elems) Queue::Push(q, x);
            st.queues[name] = q;
        } else if (type == "S") {
            Stack::Stack s;
            for (auto it = elems.rbegin(); it != elems.rend(); ++it) Stack::Push(s, *it);
            st.stacks[name] = s;
        } else if (type == "T") {
            std::string joined;
            for (auto& x : elems) {
                joined += x;
                joined += ' ';
            }
            std::istringstream tree_in(joined);
            AvlTree::AvlTree t;
            t.root = BuildTree(tree_in);
            st.trees[name] = t;
        }
    }
}

}