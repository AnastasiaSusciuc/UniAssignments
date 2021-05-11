#include "ListIterator.h"
#include "../A3 - DLLA IteratedList/IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	this->iterator = list.dlla.head;
}

void ListIterator::first() {
	this->iterator = list.dlla.head;
}

void ListIterator::next() {
    if (this->iterator == -1)
        throw std::exception();
    this->iterator = list.dlla.nodes[this->iterator].next;
}

bool ListIterator::valid() const {
	if (this->iterator == -1)
        return false;
	return true;

}

TElem ListIterator::getCurrent() const {
	if (this->iterator == -1)
	    return NULL_TELEM;
    return list.dlla.nodes[this->iterator].info;
}



