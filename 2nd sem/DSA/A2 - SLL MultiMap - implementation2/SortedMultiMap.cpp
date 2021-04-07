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
    if (this->head == nullptr)                  // the SLL is empty
    {
        auto* new_node = new SLLkeys;
        new_node->key = c;
        new_node->next = nullptr;

        auto* new_value = new SLLvalues;

        new_value->value = v;
        new_value->next = nullptr;

        new_node->head = new_value;
        this->head = new_node;

        return;
    }

    if (!this->relation(this->head->key, c))  // we need to change the head of the SLL
    {
        auto* new_node = new SLLkeys;
        new_node->key = c;
        new_node->next = this->head;
        this->head = new_node;

        auto* new_value = new SLLvalues;

        new_value->value = v;
        new_value->next = nullptr;

        new_node->head = new_value;

        return;
    }

    auto* current_node = this->head;

    while (current_node != nullptr && current_node->key != c)
        current_node = current_node->next;

    if (current_node != nullptr)             // the key is already in the SLLKeys, we insert on the first position the new value
    {
        auto* new_value = new SLLvalues;
        new_value->next = current_node->head;
        new_value->value = v;
        current_node->head = new_value;
    }
    else
    {
        SLLkeys* prev = nullptr;
        current_node = this->head;
        while (current_node != nullptr && this->relation(current_node->key, c))
        {
            prev = current_node;
            current_node = current_node->next;
        }

        auto* new_node = new SLLkeys;
        new_node->key = c;
        new_node->next = prev->next;
        prev->next = new_node;

        auto* new_value = new SLLvalues;
        new_node->head = new_value;
        new_value->value = v;
        new_value->next = nullptr;

    }
}

vector<TValue> SortedMultiMap::search(TKey c) const
// best case: theta(1) - there is only one element with the key c and is in the first node
// worst case: theta(SLL_size) - the element with key c is on the last position
// total complexity: O(SLL_size)
{

    vector <TValue> values;

    auto* current_node = this->head;
    while (current_node != nullptr && current_node->key != c)
    {
       current_node = current_node->next;
    }

    if (current_node == nullptr)
        return values;

    auto current_value = current_node->head;

    while(current_value != nullptr)
    {
        values.push_back(current_value->value);
        current_value = current_value->next;
    }

	return values;
}

bool SortedMultiMap::remove(TKey c, TValue v)
// best case: theta(1)
// worst case: theta(SLL_size)
// average case: theta(SLL_size)
// total complexity: O(SLL_size)
{
    SLLkeys* prev_node = nullptr;
    auto* current_node = this->head;
    while (current_node != nullptr && current_node->key != c)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }
    //std::cout << "AICI!" << current_node << '\n';
    if (current_node == nullptr)
        return false;

    //std::cout << "AICI2!" << current_node << '\n';
    auto current_value = current_node->head;
    auto copy_current_node = current_node;
    SLLvalues* prev_value = nullptr;
    int number_deleted_elements = 0;


    while (current_value != nullptr)
    {
        auto next = current_value->next;
        if (current_value->value == v)
        {
            if (prev_value == nullptr)
            {
                current_node->head = current_value->next;
                delete current_value;
                current_value = nullptr;
                number_deleted_elements++;
                prev_value = current_value;
            }
            else
            {
                prev_value->next=current_value->next;
                delete current_value;
                current_value = prev_value;
                number_deleted_elements++;

            }
        }

        prev_value = current_value;
        current_value = next;
    }

    if (copy_current_node->head == nullptr)
    {
        if (prev_node == nullptr)
        {
            this->head = copy_current_node->next;
            delete copy_current_node;
        }
        else
        {
            prev_node->next = copy_current_node->next;
            delete copy_current_node;
        }
    }

    return number_deleted_elements != 0;
}


int SortedMultiMap::size() const
// theta(SLL_size)
{
    int size = 0;

    auto* current_node = this->head;

    while (current_node != nullptr)
    {
        auto* current_value = current_node->head;
        while (current_value != nullptr)
        {
            current_value = current_value->next;
            size++;
        }
        current_node = current_node->next;
    }

	return size;
}

bool SortedMultiMap::isEmpty() const
// theta(1)
{
    int size = 0;

    auto* current_node = this->head;

    while (current_node != nullptr && size == 0)
    {
        auto* current_value = current_node->head;
        while (current_value != nullptr && size == 0)
        {
            current_value = current_value->next;
            size++;
        }
        current_node = current_node->next;
    }
    return size == 0;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap()
// theta(SLL_size)
{
    auto* current_key = this->head;
    SLLvalues* current_value;
    if (current_key != nullptr)
        current_value = current_key->head;

    while(current_key != nullptr) {

        if (current_value != nullptr)
        {
            auto next = current_value->next;
            delete current_value;
            current_value = next;
        }
        else {
            auto next = current_key->next;
            delete current_key;
            current_key = next;

            if (current_key != nullptr)
                current_value = current_key->head;
        }
    }
}

std::vector<TValue> SortedMultiMap::removeKey(TKey key)
//  best case: key is the head and has only one element: theta(1)
//  worst case: key is the last node of SLL: theta(pairs)
//  total case: O(pairs)
{

    std::vector <TValue> removed_values;
    auto* current_node = this->head;
    SLLkeys* prev_node;

    while(current_node != nullptr && current_node->key != key)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == nullptr)
        return removed_values;

    if (prev_node == nullptr)
    {
        SLLvalues* current_value = current_node->head;
        while (current_value != nullptr)
        {
            auto next = current_value->next;
            removed_values.push_back(current_value->value);
            delete current_value;
            current_value = next;
        }
        this->head = current_node->next;
        delete current_node;
    }
    else
    {
        SLLvalues* current_value = current_node->head;
        while (current_value != nullptr)
        {
            auto next = current_value->next;
            removed_values.push_back(current_value->value);
            delete current_value;
            current_value = next;
        }
        prev_node->next = current_node->next;
        delete current_node;
    }

    return removed_values;
}