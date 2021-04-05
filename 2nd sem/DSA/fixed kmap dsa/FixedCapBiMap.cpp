#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>

FixedCapBiMap::FixedCapBiMap(int capacity) {
//    if(capacity < 0)
//        throw std::exception();
    this->capacity = capacity;
    this->nrPairs = 0;
    this->elements = new TElem[capacity];
}

FixedCapBiMap::~FixedCapBiMap() {
	//TODO - Implementation
}

bool FixedCapBiMap::add(TKey c, TValue v){

    int index = 0;
    int count = 0;
    while (count < 2 && index < this->nrPairs)
    {
        if (this->elements[index].first == c)
            count++;
        index++;
    }

    if (count == 2)
        return false;
    else
    {
        this->elements[this->nrPairs].first = c;
        this->elements[this->nrPairs].second = v;
        this->nrPairs++;
        return true;
    }
}

ValuePair FixedCapBiMap::search(TKey c) const{
	//TODO - Implementation
	return std::pair<TValue, TValue>(NULL_TVALUE, NULL_TVALUE);
}

bool FixedCapBiMap::remove(TKey c, TValue v){
	//TODO - Implementation
	return false;
}


int FixedCapBiMap::size() const {
	//TODO - Implementation
	return 0;
}

bool FixedCapBiMap::isEmpty() const{
	//TODO - Implementation
	return false;
}

bool FixedCapBiMap::isFull() const {
	//TODO - Implementation
	return false;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}

ValuePair FixedCapBiMap::removeKey(TKey k)
{
    ValuePair pair = {NULL_TVALUE, NULL_TVALUE};
    int found = 0;
    for (int i = 0; i < this->nrPairs && found < 2; i++)
    {
        if (this->elements[i].first == k)
        {
            found++;
            if (found == 1)
                pair.first = this->elements[i].second;
            else
                pair.second = this->elements[i].second;
            swap(this->elements[i], this->elements[this->nrPairs-1]);
            this->nrPairs--;
        }
    }
    return pair;
}


