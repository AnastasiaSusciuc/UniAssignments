#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

SortedSet::SortedSet(Relation r): relation{r}
// theta(MOD)
{
    for (int i = 0; i < MOD; i++)
        hashTable[i] = nullptr;
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
// theta(number_elements*MOD + (2*MOD+1)) - because of the iterator, next operation taking theta(MOD) time
{
    int* all_values = new int[this->MOD];
    int counter = 0;

    SortedSetIterator it(*this);
    it.first();
    while (it.valid())
    {
        all_values[++counter] = it.getCurrent();
        it.next();
    }

    Node** old_table = hashTable;

    int old_mod = this->MOD;
    this->MOD *= 2;
    this->MOD += 1;

    hashTable = new Node* [MOD];
    for (int i = 0; i < MOD; i++)
        hashTable[i] = nullptr;

    this->no_elements=0;

    for (int i = 1; i <= counter; i++)
        add(all_values[i]);

    for (int i = 0; i < old_mod; i++)
    {
        Node* node = old_table[i];
        while (node != nullptr)
        {
            Node* next = node->next;
            delete node;
            node = next;
        }
    }

    delete[] old_table;
}

bool SortedSet::add(TComp elem)
// best case: theta(1) - the element is found on the first position in its SLL
// worst case: theta(1+load_factor) + theta(number_elements*MOD + (2*MOD+1)) - the element is not found on its branch that
//          has load_factor elements (or it is on the last position) and we also need to resize
// total complexity: O(1+load_factor) amortized
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

	    if (get_loaded_factor() > this->load_factor) {
            // std::cout << "RESIZE\n";
            resize();
	    }
        return true;
    }
	return false;
}

bool SortedSet::remove(TComp elem)
// best case: theta(1) - there is no element in the SLL with the result of the hash of the element elem
// worst case: theta(1+load_factor) - there is no element equal to elem to be removed
// total complexity: O(1+load_factor)
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
// worst case: theta(1+load_factor)
// total complexity: O(1+load_factor)
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
// theta(MOD + number_elements)
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