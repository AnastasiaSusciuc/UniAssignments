#include "ListIterator.h"
#include "../A3 - DLLA IteratedList/IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list), current{-1} {
	this->first();
}

void ListIterator::first() {

    if(this->list._size)
        this->current = this->list.head;

    else this->current = -1;
}

void ListIterator::next() {
    if(this->valid())
        this->current = this->list.buffer[this->current]->next;
    else
        throw std::exception();
}

bool ListIterator::valid() const {
    if(this->current == -1)
        return false;

    return true;
}

TElem ListIterator::getCurrent() const {
    if(this->valid())
        return this->list.buffer[this->current]->info;
    else
        throw std::exception();
}

int ListIterator::get_position() {
    return this->current;
}
