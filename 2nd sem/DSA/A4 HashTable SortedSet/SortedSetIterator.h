#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);
    // TODO how to access MOD from multime
    TElem current_element = NULL_TELEM;
	Node* current[8000];

public:
	void first();
	void next();
	TElem getCurrent() const;
	bool valid() const;
};

