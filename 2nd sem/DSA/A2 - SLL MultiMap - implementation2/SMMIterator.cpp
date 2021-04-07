#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <exception>

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	this->current_key = d.head;
	if (this->current_key != nullptr)
	    this->current_value = this->current_key->head;
}

void SMMIterator::first()
// theta(1)
{
    this->current_key = map.head;
    if (this->current_key != nullptr)
        this->current_value = this->current_key->head;
}

void SMMIterator::next()
// theta(1)
{
    if (this->current_key == nullptr)
        throw std::exception();

	if (this->current_value->next != nullptr)
	    this->current_value = this->current_value->next;
	else
    {
        this->current_key = this->current_key->next;
        if (this->current_key != nullptr)
            this->current_value = this->current_key->head;
    }
}

bool SMMIterator::valid() const
//theta(1)
{
    if (this->current_key == nullptr)
	    return false;
    return true;
}

TElem SMMIterator::getCurrent() const
// theta(1)
{
    if (this->current_key == nullptr)
        throw std::exception();
    return std::make_pair(this->current_key->key, this->current_value->value);
}


