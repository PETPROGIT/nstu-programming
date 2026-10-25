#include "Executor.h"

#include <iostream>
#include <string>

namespace Db {

void Execute(Storage& st, Command cmd, const std::string& name, const std::vector<std::string>& args) {
    switch (cmd) {
    case Command::MCREATE: if (!st.arrays.count(name)) Array::Create(st.arrays[name], 1); std::cout << "-> CREATED M " << name << std::endl; break;
    case Command::MPUSHBACK: Array::PushBack(st.arrays[name], args[0]); std::cout << "-> " << args[0] << std::endl; break;
    case Command::MINSERT: Array::Insert(st.arrays[name], std::stoul(args[0]), args[1]); std::cout << "-> " << args[1] << std::endl; break;
    case Command::MGET: std::cout << "-> " << Array::Get(st.arrays[name], std::stoul(args[0])) << std::endl; break;
    case Command::MSET: Array::Set(st.arrays[name], std::stoul(args[0]), args[1]); std::cout << "-> " << args[1] << std::endl; break;
    case Command::MREMOVEAT: std::cout << "-> " << Array::RemoveAt(st.arrays[name], std::stoul(args[0])) << std::endl; break;
    case Command::MLENGTH: std::cout << "-> " << Array::Length(st.arrays[name]) << std::endl; break;
    case Command::MREAD: Array::Read(st.arrays[name]); break;

    case Command::FCREATE: st.flists[name]; std::cout << "-> CREATED F " << name << std::endl; break;
    case Command::FPUSHFRONT: ForwardList::PushFront(st.flists[name], args[0]); std::cout << "-> " << args[0] << std::endl; break;
    case Command::FPUSHBACK: ForwardList::PushBack(st.flists[name], args[0]); std::cout << "-> " << args[0] << std::endl; break;
    case Command::FINSERTBEFORE: ForwardList::InsertBefore(st.flists[name], args[0], args[1]); std::cout << "-> " << args[1] << std::endl; break;
    case Command::FINSERTAFTER: ForwardList::InsertAfter(st.flists[name], args[0], args[1]); std::cout << "-> " << args[1] << std::endl; break;
    case Command::FPOPFRONT: std::cout << "-> " << ForwardList::PopFront(st.flists[name]) << std::endl; break;
    case Command::FPOPBACK: std::cout << "-> " << ForwardList::PopBack(st.flists[name]) << std::endl; break;
    case Command::FREMOVEBEFORE: std::cout << "-> " << ForwardList::RemoveBefore(st.flists[name], args[0]) << std::endl; break;
    case Command::FREMOVEAFTER: std::cout << "-> " << ForwardList::RemoveAfter(st.flists[name], args[0]) << std::endl; break;
    case Command::FREMOVE: std::cout << "-> " << ForwardList::Remove(st.flists[name], args[0]) << std::endl; break;
    case Command::FFIND: std::cout << "-> " << (ForwardList::Find(st.flists[name], args[0]) ? "TRUE" : "FALSE") << std::endl; break;
    case Command::FREAD: ForwardList::Read(st.flists[name]); break;

    case Command::LCREATE: st.llists[name]; std::cout << "-> CREATED L " << name << std::endl; break;
    case Command::LPUSHFRONT: LinkedList::PushFront(st.llists[name], args[0]); std::cout << "-> " << args[0] << std::endl; break;
    case Command::LPUSHBACK: LinkedList::PushBack(st.llists[name], args[0]); std::cout << "-> " << args[0] << std::endl; break;
    case Command::LINSERTBEFORE: LinkedList::InsertBefore(st.llists[name], args[0], args[1]); std::cout << "-> " << args[1] << std::endl; break;
    case Command::LINSERTAFTER: LinkedList::InsertAfter(st.llists[name], args[0], args[1]); std::cout << "-> " << args[1] << std::endl; break;
    case Command::LPOPFRONT: std::cout << "-> " << LinkedList::PopFront(st.llists[name]) << std::endl; break;
    case Command::LPOPBACK: std::cout << "-> " << LinkedList::PopBack(st.llists[name]) << std::endl; break;
    case Command::LREMOVEBEFORE: std::cout << "-> " << LinkedList::RemoveBefore(st.llists[name], args[0]) << std::endl; break;
    case Command::LREMOVEAFTER: std::cout << "-> " << LinkedList::RemoveAfter(st.llists[name], args[0]) << std::endl; break;
    case Command::LREMOVE: std::cout << "-> " << LinkedList::Remove(st.llists[name], args[0]) << std::endl; break;
    case Command::LFIND: std::cout << "-> " << (LinkedList::Find(st.llists[name], args[0]) ? "TRUE" : "FALSE") << std::endl; break;
    case Command::LREAD: LinkedList::Read(st.llists[name]); break;
    case Command::LREADREVERSE: LinkedList::ReadReverse(st.llists[name]); break;

    case Command::QCREATE: st.queues[name]; std::cout << "-> CREATED Q " << name << std::endl; break;
    case Command::QPUSH: Queue::Push(st.queues[name], args[0]); std::cout << "-> " << args[0] << std::endl; break;
    case Command::QPOP: std::cout << "-> " << Queue::Pop(st.queues[name]) << std::endl; break;
    case Command::QREAD: Queue::Read(st.queues[name]); break;

    case Command::SCREATE: st.stacks[name]; std::cout << "-> CREATED S " << name << std::endl; break;
    case Command::SPUSH: Stack::Push(st.stacks[name], args[0]); std::cout << "-> " << args[0] << std::endl; break;
    case Command::SPOP: std::cout << "-> " << Stack::Pop(st.stacks[name]) << std::endl; break;
    case Command::SREAD: Stack::Read(st.stacks[name]); break;

    case Command::TCREATE: st.trees[name]; std::cout << "-> CREATED T " << name << std::endl; break;
    case Command::TINSERT: AvlTree::Insert(st.trees[name], std::stoi(args[0])); std::cout << "-> " << args[0] << std::endl; break;
    case Command::TREMOVE: std::cout << "-> " << AvlTree::Remove(st.trees[name], std::stoi(args[0])) << std::endl; break;
    case Command::TFIND: std::cout << "-> " << (AvlTree::Find(st.trees[name], std::stoi(args[0])) ? "TRUE" : "FALSE") << std::endl; break;
    case Command::TREAD: AvlTree::Read(st.trees[name]); break;
    }
}

}