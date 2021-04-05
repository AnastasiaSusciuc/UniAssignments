//
// Created by susci on 3/19/2021.
//
/*
#include "Set.h"
#include "SetITerator.h"

Set::Set()
// theta(1);
{
    this->size_set = 0;
    this->capacity_set = INITIAL_CAPACITY;
    this->elements = new TElem [this->capacity_set];
    if (this->elements == nullptr)
    {
        fprintf(stderr, "Not enough memory!");
        abort();
    }
}

void Set::resizeDynamicVector()
// theta(capacity);
{
    int new_capacity = 2*this->capacity_set;
    auto* new_elements = new TElem [new_capacity];
    for (int i = 0; i < this->size_set; i++)
    {
        new_elements[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = new_elements;
    this->capacity_set = new_capacity;
}

bool Set::add(TElem elem)
// theta(size_set)
{
    if (this->size_set == this->capacity_set)
        resizeDynamicVector();

    if (!search(elem))
    {
        this->elements[this->size_set++]=elem;
        return true;
    }
    return false;
}

bool Set::remove(TElem elem)
// theta(size_set)
{

    int positionFound = -1;
    for (int i = 0; i < this->size_set && positionFound == -1; i++)
        if (elem == this->elements[i])
            positionFound = i;

    if (positionFound != -1)   // elem is in the set and we can remove it
    {
        for (int i = positionFound; i < this->size_set; i++)
            this->elements[i] = this->elements[i+1];

        this->size_set--;
        return true;
    }

    return false;
}

bool Set::search(TElem elem) const
// Best Case: theta(1), Worst Case: theta(size_set), Average Complexity: theta(size_set), Total Complexity: O(size_set)
{
    for (int i = 0; i < this->size_set; i++)
        if (elem == this->elements[i])
            return true;

    return false;
}

int Set::size() const
// theta(1)
{
    return this->size_set;
}

bool Set::isEmpty() const
// theta(1)
{
    return this->size_set == 0;
}

Set::~Set()
// theta(1)
{
    delete[] this->elements;
}

SetIterator Set::iterator() const
{
    return SetIterator(*this);
}
*/