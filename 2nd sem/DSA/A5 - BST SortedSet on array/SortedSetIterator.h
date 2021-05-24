#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);
    int current = 0;
    int counter = 0;
    TElem* preorder;
    void get_preorder(int position);
public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};

