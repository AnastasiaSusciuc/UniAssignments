#pragma once
#include "../A3 - DLLA IteratedList/IteratedList.h"

//DO NOT CHANGE THIS PART
class IteratedList;
typedef int TElem;

class ListIterator{
	friend class IteratedList;
private:
	int iterator;
	//DO NOT CHANGE THIS PART
	const IteratedList& list;
	explicit ListIterator(const IteratedList& lista);
public:
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;

};


