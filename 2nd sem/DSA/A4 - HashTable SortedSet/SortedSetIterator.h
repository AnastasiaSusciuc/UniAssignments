//#pragma once
//#include "SortedSet.h"
//
////DO NOT CHANGE THIS PART
//class SortedSetIterator
//{
//	friend class SortedSet;
//private:
//	const SortedSet& multime;
//	SortedSetIterator(const SortedSet& m);
//    TElem current_element = NULL_TELEM;
//	Node** current;
//
//public:
//	void first();
//	void next();
//	TElem getCurrent() const;
//	bool valid() const;
//
//    //~SortedSetIterator();
//};
//
#pragma once
#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
    friend class SortedSet;
private:
    SortedSet& multime;
    explicit SortedSetIterator(SortedSet& m);

    TElem current_element = NULL_TELEM;
    Node** current;
    // Node* current[8000];

public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
    TComp remove();
};

