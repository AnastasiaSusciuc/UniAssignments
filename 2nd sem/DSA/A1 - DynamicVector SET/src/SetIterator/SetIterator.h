#pragma once
#include "src/Set/Set.h"
#include <exception>

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);

	int current;
	bool is_valid = true;

public:

    // moves the iterator to the first element
	void first();

    // moves the iterator to the last element
	void last();

    //changes the current element from the iterator to the previous element, or, if the current element was the first, makes the iterator invalid
    //throws an exception if the iterator is not valid
	void previous();

    //changes the current element from the iterator to the next element, or, if the current element was the last, makes the iterator invalid
    //throws an exception if the iterator is not valid
	void next();

	// returns the current element from the iterator
	TElem getCurrent();

	// returns true if the iterator is valid, false otherwise
	bool valid() const;
};
