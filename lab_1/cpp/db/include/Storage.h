#pragma once

#include "Array.h"
#include "AvlTree.h"
#include "ForwardList.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

#include <map>
#include <string>

namespace Db {

struct Storage {
    std::map<std::string, Array::Array> arrays;
    std::map<std::string, ForwardList::ForwardList> flists;
    std::map<std::string, LinkedList::LinkedList> llists;
    std::map<std::string, Queue::Queue> queues;
    std::map<std::string, Stack::Stack> stacks;
    std::map<std::string, AvlTree::AvlTree> trees;
};

void ClearStorage(Storage& st);

}