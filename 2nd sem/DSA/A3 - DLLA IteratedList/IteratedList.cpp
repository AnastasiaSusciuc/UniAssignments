
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList()
// theta(MAX_CAP)
{
    this->dlla.head = -1;
    this->dlla.tail = -1;
    this->dlla.size_list = 0;
    this->dlla.first_empty = 1;
    this->dlla.capacity = MAX_CAP;

    for (int i = 0; i < MAX_CAP-1; i++)
        this->dlla.nodes[i].next = i+1;
    this->dlla.nodes[MAX_CAP-2].next = -1;

    for (int i = 0; i < MAX_CAP; i++)
        this->dlla.nodes[i].prev = i-1;
}

int IteratedList::size() const {

	return this->dlla.size_list;
}

bool IteratedList::isEmpty() const {
	return (this->dlla.size_list == 0);
}

ListIterator IteratedList::first() const {
	return ListIterator(this*);
}

TElem IteratedList::getElement(ListIterator pos) const {
    return this->dlla.nodes[pos.iterator].info;
}

TElem IteratedList::remove(ListIterator& pos) {
	//TODO - Implementation
	return NULL_TELEM;
}

ListIterator IteratedList::search(TElem e) const{
	//TODO - Implementation
	return ListIterator(*this);	
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    //TODO - Implementation
	return NULL_TELEM;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    //TODO - Implementation
}

void IteratedList::addToEnd(TElem e) {
	//TODO - Implementation
}

IteratedList::~IteratedList() {
	//TODO - Implementation
}

void IteratedList::addToBeginning(TElem e) {

}

int IteratedList::allocate() {
    int new_elem = this->dlla.first_empty;
    if (new_elem != -1)
    {
        this->dlla.first_empty = this->dlla.nodes[this->dlla.first_empty].next;
        if (this->dlla.first_empty != -1)
        {
            this->dlla.nodes[this->dlla.first_empty].prev=-1;
        }
        this->dlla.nodes[new_elem].next=-1;
        this->dlla.nodes[new_elem].prev=-1;
    }
    return new_elem;
}

void IteratedList::free(int poz) {
    this->dlla.nodes[poz].next = this->dlla.first_empty;
    this->dlla.nodes[poz].prev = -1;
    if (this->dlla.first_empty != -1)
        this->dlla.nodes[this->dlla.first_empty].prev = poz;
    this->dlla.first_empty = poz;
}
