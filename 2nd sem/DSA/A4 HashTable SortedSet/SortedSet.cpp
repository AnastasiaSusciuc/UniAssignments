#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

SortedSet::SortedSet(Relation r): relation{r} {

}

int SortedSet::hashFunction(TElem elem) const
// theta(1)
{
    if (elem < 0) elem*=-1;
    return elem % MOD;
}

double SortedSet::get_loaded_factor() const
// theta(1)
{
    return (double(no_elements)/MOD);
}

void SortedSet::resize()
{
//    int* all_values = new int[this->MOD];
//    int counter = 0;
//
//    SortedSetIterator it(*this);
//    it.first();
//    while (it.valid())
//    {
//        all_values[++counter] = it.getCurrent();
//        it.next();
//    }
//
//    delete hashTable[this->MOD];
//    this->MOD *= 2;
//    this->MOD += 1;
//    hashTable = new Node* [MOD];
//
//    for (int i = 1; i <= counter; i++)
//        add(all_values[i]);

}

bool SortedSet::add(TComp elem)
// best case: theta(1) - the element is found on the first position in its SLL
// worst case: theta(n) - all the elements are in collision and we look for the greatest element or for a nonexistent
//                                                                  elem, where n is the number of elements in the set
// total complexity: O(n)
{

	if (!search(elem)) // the elem is not in the set therefore we add it and return true
    {
	    int position = hashFunction(elem);
	    this->no_elements++;

	    Node* new_node = new Node;
	    new_node->value = elem;

	    if(hashTable[position] == nullptr || !relation(hashTable[position]->value, elem))
        {
            new_node->next = hashTable[position];
	        hashTable[position] = new_node;
        }
	    else
        {
            Node* current = hashTable[position];
            Node* previous;
            while (current != nullptr && relation(current->value, elem))
            {
                previous = current;
                current = current->next;
            }
            new_node->next = previous->next;
            previous->next = new_node;
        }

//	    if (get_loaded_factor() > this->load_factor)
//	        resize();

        return true;
    }
	return false;
}


bool SortedSet::remove(TComp elem)
// best case: theta(1) - there is no element in the SLL of the result of the hash of the element elem
// worst case: theta(n) - there is no element equal to elem to be removed, where n is the total number of elements and all are in collision
// total complexity: O(n)
{
    int position = hashFunction(elem);
    Node* current = hashTable[position];
    Node* previous = nullptr;

    if (hashTable[position] == nullptr)
        return false;

    if (hashTable[position]->value == elem)
    {
        Node* old_node = hashTable[position];
        hashTable[position] = hashTable[position]->next;
        delete old_node;
        this->no_elements--;
        return true;
    }

    while (current != nullptr && relation(current->value, elem))
    {
        if (current->value == elem)
        {
            Node* next_node = current->next;
            delete next_node;
            previous->next = next_node;
            this->no_elements--;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}


bool SortedSet::search(TComp elem) const
// best case: theta(1)
// worst case: theta(n) - there is no element equal to elem, where n is the total number of elements and all elements are in collision
// total complexity: O(n)
{
    int position = hashFunction(elem);
    Node* node = hashTable[position];
    while (node != nullptr && relation(node->value, elem))
    {
        if (node->value == elem) return true;
        node = node->next;
    }
    return false;
}


int SortedSet::size() const
// theta(1)
{
	return this->no_elements;
}

bool SortedSet::isEmpty() const
// theta(1)
{
	return (this->no_elements == 0);
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet()
// theta(MOD + n)
{
	for (int i = 0; i < MOD; i++)
    {
	    Node* node = hashTable[i];
	    while (node != nullptr)
        {
	        Node* next = node->next;
	        delete node;
	        node = next;
        }
    }
}



