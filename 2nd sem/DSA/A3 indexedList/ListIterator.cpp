#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

ListIterator::ListIterator(const IndexedList& list) : list(list){
    this->first();
}

void ListIterator::first(){
    if(this->list.no_of_elements)
        this->current = this->list.head_pos;
    else this->current = -1;
}

void ListIterator::next(){
    if(this->valid())
        this->current = this->list.buffer[this->current]->next;
    else
        throw std::exception();

}

bool ListIterator::valid() const{
    if(this->current==-1)
        return false;
    else
        return true;
}

TElem ListIterator::getCurrent() const{
    if(this->valid())
        return this->list.buffer[this->current]->data;
    else
        throw std::exception();
}