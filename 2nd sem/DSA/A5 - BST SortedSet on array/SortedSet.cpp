#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r): relation{r} {
    nr_elements = 0;
    array = new TElem [capacity];
	for (int i = 0; i < capacity; i++)
	    array[i] = NULL_TELEM;
}

void SortedSet::resize() {
    capacity *= 2;
    TElem * new_array = new TElem [capacity];
    for (int i = 0; i < capacity/2; i++)
        new_array[i] = array[i];
    for (int i = capacity/2; i < capacity; i++)
        new_array[i] = NULL_TELEM;
    delete [] array;
    array = new_array;
}

bool SortedSet::add(TComp elem) {
	if (nr_elements-1 == capacity)
    {
//	    resize();
    }

	int root = 1;
	while (true)
    {
	    if (array[root] == elem)
	        return false;
	    if (array[root] == NULL_TELEM)
        {
	        nr_elements++;
	        array[root] = elem;
            std::cout << "ADD " << elem << ": ";
//            for (int i = 1; i < 10; i++)
//                std::cout << array[i] << " ";
//            std::cout << '\n';
            return true;
        }

	    if (relation(elem, array[root])) root = 2*root;
        else root = 2*root + 1;
    }

}


bool SortedSet::remove(TComp elem) {
    int root = 1;
    bool last = false; // false - right/ true - left
    while (true) {
        if (array[root] == elem)
            break;
        if (array[root] == NULL_TELEM)
            break;

        if (relation(elem, array[root]))
        {
            root = 2 * root;
            last = false;
        }
        else
        {
            root = 2 * root + 1;
            last = true;
        }
    }

    if (array[root] == NULL_TELEM) return false; // there is no such element in the set

    this->nr_elements--;
    if ((2*root + 1 > capacity || array[2*root+1] == NULL_TELEM) && (2*root > capacity || array[2*root] == NULL_TELEM))
    {
        // this node has no descendents
        array[root] = NULL_TELEM;
        std::cout << "1\n";
        return true;
    }

    if (array[2*root] == NULL_TELEM)
    {
        int old_root = root;
        while (true)
        {
            if (2*old_root+1 >= capacity || array[2*old_root+1] == NULL_TELEM)
                break;
            if (2*old_root+1 < capacity)
            {
                array[old_root] = array[2*old_root+1];
                old_root = old_root*2+1;
            }

        }
        if (old_root < capacity)
            array[old_root] = NULL_TELEM;
        std::cout << "2\n";
        return true;
    }

    if (array[2*root+1] == NULL_TELEM)
    {
        int old_root = root;
        while (true)
        {
            if (2*old_root >= capacity || array[2*old_root] == NULL_TELEM)
                break;
            if (2*old_root < capacity)
            {
                array[old_root] = array[2*old_root];
                old_root = old_root*2;
            }

        }
        if (old_root < capacity)
            array[old_root] = NULL_TELEM;

        std::cout << "REMOVE " << elem << ": ";
        for (int i = 1; i < 10; i++)
            std::cout << array[i] << " ";
        std::cout << '\n';
        std::cout << "3\n";
        return true;
    }

    if (last) // we need to take the minimum of the two kids
    {
        array[root] = array[2*root];
        while (2*root < capacity && array[2*root] != NULL_TELEM)
        {
            array[root] = array[2*root];
            root*=2;
        }
        if (root < capacity)
            array[root] = NULL_TELEM;
        std::cout << "4\n";
        return true;
    }
    else
    {
        array[root] = array[2*root+1];
        while (2*root+1 < capacity && array[2*root+1] != NULL_TELEM)
        {
            array[root] = array[2*root+1];
            root = 2*root+1;
        }
        if (root < capacity)
            array[root] = NULL_TELEM;
        std::cout << "5\n";
        return true;
    }

}


bool SortedSet::search(TComp elem) const {

    TElem root = 1;
    while (true)
    {
        if (array[root] == elem)
            return true;
        if (array[root] == NULL_TELEM)
            return false;

        if (relation(elem, array[root])) root = 2*root;
        else root = 2*root + 1;
    }
}


int SortedSet::size() const {
	return this->nr_elements;
}


bool SortedSet::isEmpty() const {
    return (this->nr_elements == 0);
}


SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    delete[] array;
}

