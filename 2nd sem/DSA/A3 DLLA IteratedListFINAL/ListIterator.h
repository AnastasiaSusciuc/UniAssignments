#pragma once
#include "IteratedList.h"

//DO NOT CHANGE THIS PART
class IteratedList;
typedef int TElem;

class ListIterator{
	friend class IteratedList;
private:
	int current; //  pozitia in vector
	//DO NOT CHANGE THIS PART
	const IteratedList& list;
	int get_position() const;
	ListIterator(const IteratedList& lista);
public:
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;

};


