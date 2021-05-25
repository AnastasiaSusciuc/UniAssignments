#include "SortedSetIterator.h"
#include <exception>

using namespace std;

// O(sizeSet)
SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    Travers = new int[m.setSize];
    ordered = new int[m.setSize];

    int node = m.bst.root;
    count = -1;
    top = -1;

    if (node != -1)
    {
        while (node != NULL_POS)
        {
            Travers[++top] = node;
            node = m.bst.left[node];
        }
    }
    while (true)
    {
        if (top == -1)
            break;
        node = Travers[top];
        top--;

        ordered[++count] = m.bst.info[node];
        if (m.bst.right[node] != NULL_POS)
        {
            node = m.bst.right[node];
            while (node != NULL_POS)
            {
                Travers[++top] = node;
                node = m.bst.left[node];
            }
        }
    }
    first();
}

// theta(1)
void SortedSetIterator::first() {
    currentNode = 0;
}

// theta(1)
void SortedSetIterator::next() {

    if (!valid())
        throw std::exception();
    currentNode++;
}

// theta(1)
TElem SortedSetIterator::getCurrent()
{
    if (!valid())
        throw std::exception();
    return ordered[currentNode];
}

// theta(1)
bool SortedSetIterator::valid() const {
    if (currentNode <= -1 || currentNode > count)
        return false;
    return true;
}

// theta(1)
void SortedSetIterator::prev() {
    if (!valid())
        throw std::exception();
    currentNode--;
}
