#include "SetIterator.h"
#include "src/Set/Set.h"
#include <iostream>

SetIterator::SetIterator(const Set& m) : set(m)
// theta(1)
{
	this->current = 0;
}


void SetIterator::first()
// theta(1)
{
    this->current = 0;
    this->is_valid = true;
}


void SetIterator::previous()
// theta(1)
{
    if (this->current == -1) {
        this->is_valid = false;
        throw std::exception();
    }
    else
        this->current--;
}

void SetIterator::next()
// theta(1)
{

	if(this->current == this->set.size_set) {
        this->is_valid = false;
        throw std::exception();
    }
	else
	    this->current++;
}


TElem SetIterator::getCurrent()
// theta(1)
{
    if(this->current == this->set.size_set)
        throw std::exception();

    return this->set.elements[this->current];
}


bool SetIterator::valid() const
//theta(1)
{
	if (this->current < this->set.size_set and this->current >= 0 and this->is_valid)
	    return true;
	return false;
}

void SetIterator::last()
// Theta(1)
{
    this->current = this->set.size_set-1;
    this->is_valid = true;
}