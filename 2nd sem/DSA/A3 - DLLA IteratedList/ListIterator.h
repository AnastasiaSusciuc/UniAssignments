#pragma once
#include "../A3 - DLLA IteratedList/IteratedList.h"

//DO NOT CHANGE THIS PART
class IteratedList;
typedef int TElem;

class ListIterator{
	friend class IteratedList;
private:

    DLLANode* current_node;
    int current;

	//DO NOT CHANGE THIS PART

	const IteratedList& list;
	explicit ListIterator(const IteratedList& lista);

public:
    int get_position();
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;
};
