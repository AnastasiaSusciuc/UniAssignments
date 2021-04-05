#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
    this->relation = r;
}

void SortedMultiMap::add(TKey c, TValue v)
// best case: theta(1), when the SLL is empty
// worst case: theta(size_list)
// total complexity: O(size_list)
{
    if (this->head == nullptr)    // the SLL is empty
    {
        auto* new_node = new SLLnode;
        new_node->kv_pair = {c, v};
        new_node->next = nullptr;
        this->head = new_node;
        return;
    }

    if (!this->relation(this->head->kv_pair.first, c))  // we need to change the head of the SLL
    {
        auto* new_node = new SLLnode;
        new_node->kv_pair = {c, v};
        new_node->next = this->head;
        this->head = new_node;
        return;
    }

    auto* current_node = this->head;
    SLLnode* prev_node;
    while (current_node != nullptr && this->relation(current_node->kv_pair.first, c))
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    auto* new_node = new SLLnode;
    new_node->kv_pair = {c, v};
    new_node->next = prev_node->next;
    prev_node->next=new_node;
}

vector<TValue> SortedMultiMap::search(TKey c) const
// best case: theta(1) - there is only one element with the key c and is in the first node
// worst case: theta(SLL_size) - the element with key c is on the last position
// total complexity: O(SLL_size)
{

    vector <TValue> values;

    auto* current_node = this->head;
    while (current_node != nullptr)
    {
        if (current_node->kv_pair.first == c)
            values.push_back(current_node->kv_pair.second);
        else if (!this->relation(current_node->kv_pair.first, c))
            break;
        current_node = current_node->next;
    }

    return values;
}

bool SortedMultiMap::remove(TKey c, TValue v)
// best case: theta(1)
// worst case: theta(SLL_size)
// average case: theta(SLL_size)
// total complexity: O(SLL_size)
{
    SLLnode* prev_node = nullptr;
    auto* current_node = this->head;

    while (current_node != nullptr && (current_node->kv_pair.first != c || ( current_node->kv_pair.first == c && current_node->kv_pair.second != v)))
    {
        prev_node = current_node;
        current_node = current_node->next;

    }

    if (current_node != nullptr && prev_node == nullptr)
    {
        this->head = this->head->next;
        delete current_node;
        return true;
    }
    else if (current_node != nullptr)
    {
        prev_node->next = current_node->next;
        current_node->next = nullptr;
        delete current_node;
        return true;
    }

    return false;
}


int SortedMultiMap::size() const
// theta(SLL_size)
{
    if (this->head == nullptr)
        return 0;

    int size = 0;
    auto* current_node = this->head;

    while (current_node != nullptr)
    {
        size++;
        current_node = current_node->next;
    }

    return size;
}

bool SortedMultiMap::isEmpty() const
// theta(1)
{
    return this->head == nullptr;
}

SMMIterator SortedMultiMap::iterator() const {
    return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap()
// theta(SLL_size)
{
    auto* current_node = this->head;
    while (current_node != nullptr)
    {
        auto prev = current_node->next;
        delete current_node;
        current_node = prev;
    }
}


