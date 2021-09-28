#pragma once
#include "SortedSet.h"
#include <stack>

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);

    int currentNode = 0;
    int count = 0;
    int* Travers;
    int* ordered;
    int top = -1;

public:
	void first();
	void next();
	void prev();
	TElem getCurrent();
	bool valid() const;
};

