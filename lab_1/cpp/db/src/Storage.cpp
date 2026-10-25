#include "Storage.h"

namespace Db {

void ClearStorage(Storage& st) {
    for (auto& p : st.arrays) Array::Clear(p.second);
    for (auto& p : st.flists) ForwardList::Clear(p.second);
    for (auto& p : st.llists) LinkedList::Clear(p.second);
    for (auto& p : st.queues) Queue::Clear(p.second);
    for (auto& p : st.stacks) Stack::Clear(p.second);
    for (auto& p : st.trees)  AvlTree::Clear(p.second);
}

}