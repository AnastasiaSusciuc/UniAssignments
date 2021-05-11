#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(SortedSet& m) : multime(m)
// theta(MOD)
{
    current = new Node* [m.MOD];
    for (int i = 0; i < multime.MOD; i++)
        current[i] = multime.hashTable[i];
    first();
}

void SortedSetIterator::first()
// theta(MOD)
{
    for (int i = 0; i < multime.MOD; i++)
        current[i] = multime.hashTable[i];

    Node* first = nullptr;
    int position;
    for (int i = 0; i < multime.MOD; i++)
    {
        if (current[i] == nullptr) continue;

        if (first == nullptr || multime.relation(current[i]->value, first->value))
        {
            first = current[i];
            position = i;
        }
    }

    if (first != nullptr)
    {
        current_element = first->value;
        current[position] = current[position]->next;
    }
    else
        current_element = NULL_TELEM;
}


void SortedSetIterator::next()
// theta(MOD)
{
    if (!valid())
        throw std::exception();

    Node* next = nullptr;
    int position;
    for (int i = 0; i < multime.MOD; i++)
    {
        if (current[i] == nullptr) continue;

        if (next == nullptr || multime.relation(current[i]->value, next->value))
        {
            next = current[i];
            position = i;
        }
    }
    if (next != nullptr)
    {
        current_element = next->value;
        current[position] = current[position]->next;
    }
    else
        current_element = NULL_TELEM;
}


TElem SortedSetIterator::getCurrent() const
// theta(1)
{
    if (!valid())
        throw std::exception();
    return current_element;
}

bool SortedSetIterator::valid() const
// theta(1)
{
    return (current_element != NULL_TELEM);
}

TComp SortedSetIterator::remove()
// best case: theta(1) - the element to be removed is on the first position in its SLL
// worst case: theta(number_elements) - all elements are on the same branch and we want to erase the last one
// average: theta(1) amortized
// total complexity: O(number_elements)
{
    int to_erase = current_element;
    multime.remove(to_erase);
    next();
    return to_erase;
}

