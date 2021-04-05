#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <exception>

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	this->current = d.head;
}

void SMMIterator::first(){
    this->current = map.head;
}

void SMMIterator::next(){
    if (this->current == nullptr)
        throw std::exception();

	this->current = this->current->next;
}

bool SMMIterator::valid() const {
    if (this->current == nullptr)
	    return false;
    return true;
}

TElem SMMIterator::getCurrent() const{

    if (this->current == nullptr)
        throw std::exception();
    return this->current->kv_pair;

}


