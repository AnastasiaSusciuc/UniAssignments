#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list)
// theta(1)
{
    this->first();
}

void ListIterator::first()
// theta(1)
{
    if(this->list.no_of_elements)
        this->current = this->list.head_pos;
    else this->current = -1;
}

void ListIterator::next()
// theta(1)
{
    if (this->valid())
        this->current = this->list.buffer[this->current]->next;
    else
        throw std::exception();
}

bool ListIterator::valid() const
// theta(1)
{
    if (this->current==-1)
        return false;
    return true;
}

TElem ListIterator::getCurrent() const
// theta(1)
{
    if(this->valid())
        return this->list.buffer[this->current]->data;
    else
        throw std::exception();
}

int ListIterator::get_position() const
// theta(1)
{
    return this->current;
}