#include <iostream>
#include "Set.h"
#include "src/SetIterator/SetIterator.h"

//Set::Set()
//// theta(1);
//{
//	this->size_set = 0;
//	this->capacity_set = INITIAL_CAPACITY;
//	this->elements = new TElem [this->capacity_set];
//	if (this->elements == nullptr)
//    {
//	    fprintf(stderr, "Not enough memory!");
//	    abort();
//    }
//}
//
//Set::Set(const Set &set)
//// theta(set.size_set)
//{
//    this->size_set = set.size_set;
//    this->capacity_set = set.capacity_set;
//    this->elements = new TElem [this->capacity_set];
//    if (this->elements == nullptr)
//    {
//        fprintf(stderr, "Not enough memory!");
//        abort();
//    }
//    for (int i = 0; i < this->size_set; i++)
//        this->elements[i] = set.elements[i];
//}
//
//void Set::resizeDynamicVector()
//// theta(capacity);
//{
//    int new_capacity = 2*this->capacity_set;
//    auto* new_elements = new TElem [new_capacity];
//    for (int i = 0; i < this->size_set; i++)
//    {
//        new_elements[i] = this->elements[i];
//    }
//    delete[] this->elements;
//    this->elements = new_elements;
//    this->capacity_set = new_capacity;
//}
//
//bool Set::add(TElem elem)
//// Best Case: Theta(1) - when the elem we want to add is already in the set, on the first position
//// Worst Case: Theta(size_set) - when we look for the position to insert the element, we insert it and we move all the
//// elements that are greater than 'elem' with a position to the right
//// Average Complexity: Theta(size_set)
//// Total Complexity: O(size_set)
//{
//
//	if (this->size_set == this->capacity_set)
//        resizeDynamicVector();
//
//	int position_found = -1;
//	for (int i = 0; i < this->size_set && position_found == -1; i++)
//    {
//	    if (elem == this->elements[i])
//            return false;
//
//	    if (elem > this->elements[i])
//	        position_found = i;
//    }
//
//	if (position_found == -1)
//        this->elements[this->size_set++] = elem;
//	else
//	{
//        for (int i = this->size_set; i > position_found; i--)
//            this->elements[i] = this->elements[i-1];
//
//        this->elements[position_found] = elem;
//        this->size_set++;
//    }
//    return true;
//}
//
//bool Set::remove(TElem elem)
//// Complexity of remove operation: Theta(n)
//{
//
//    int position = -1;
//    for (int i = 0; i < this->size_set && position == -1; i++)
//        if (elem == this->elements[i])
//            position = i;
//
//    if (position == -1)
//        return false;
//
//    for (int i = position; i < this->size_set; i++)
//        this->elements[i] = this->elements[i+1];
//    this->size_set--;
//
//    return true;
//}
//
//bool Set::search(TElem elem) const
//// Best Case: Theta(1) - 'elem' is in the middle of the array
//// Worst Case: Theta(log size_set)
//// Average Complexity: Theta(log size_set)
//// Total Complexity: O(log size_set)
//{
//    int left = 0, right = this->size_set-1;
//    int middle;
//
//    while (left <= right)
//    {
//        middle = (left+right)/2;
//
//        if (elem == this->elements[middle])
//            return true;
//        if (elem > this->elements[middle])
//            right = middle-1;
//        else
//            left = middle+1;
//    }
//    return false;
//}
//
//int Set::size() const
//// Complexity of 'size' operation: Theta(1)
//{
//    return this->size_set;
//}
//
//bool Set::isEmpty() const
//// Complexity of 'isEmpty' operation: Theta(1)
//{
//	return this->size_set == 0;
//}
//
//Set::~Set()
//// Complexity of destructor: Theta(1)
//{
//    delete[] this->elements;
//}
//
//SetIterator Set::iterator() const
//{
//	return SetIterator(*this);
//}
//
////Set& Set::operator=(const Set &set) {
////    this->size_set = set.size_set;
////    this->capacity_set = set.capacity_set;
////    this->elements = new TElem [this->capacity_set];
////    if (this->elements == nullptr)
////    {
////        fprintf(stderr, "Not enough memory!");
////        abort();
////    }
////    for (int i = 0; i < this->size_set; i++)
////        this->elements[i] = set.elements[i];
////}


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
// O(size_set)
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