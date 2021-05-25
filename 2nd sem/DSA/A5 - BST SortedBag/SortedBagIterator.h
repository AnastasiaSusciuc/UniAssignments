#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

    //int current;
    int currentNode;
    int* Travers;
    int top = -1;

	//TODO - Representation

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

