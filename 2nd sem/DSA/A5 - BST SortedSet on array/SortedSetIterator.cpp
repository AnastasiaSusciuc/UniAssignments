#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	current = 0;
	preorder = new TElem [m.capacity];
	counter = 0;
    get_preorder(1);
//    std::cout << "preorder ";
//    for (int i = 0; i < 3; i++)
//        std::cout << preorder[i] << ' ';
//    std::cout << '\n';
}

void SortedSetIterator::get_preorder(int position) {
//    std::cout << position << " ";
    if (multime.array[position] == NULL_TELEM) return;
    get_preorder(2*position);
    preorder[counter++] = multime.array[position];
    get_preorder(2*position+1);
}

void SortedSetIterator::first() {
	current = 0;
}


void SortedSetIterator::next() {
    if (!valid())
        throw std::exception();
	current++;
}


TElem SortedSetIterator::getCurrent()
{
    if (!valid())
        throw std::exception();
    return preorder[current];
}

bool SortedSetIterator::valid() const {
	return (current < counter);
}