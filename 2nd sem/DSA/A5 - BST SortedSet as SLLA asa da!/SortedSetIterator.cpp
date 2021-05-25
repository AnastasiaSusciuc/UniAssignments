#include "SortedSetIterator.h"
#include <exception>

using namespace std;

// O(log sizeSet)
SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    Travers = new int[m.setSize];
    first();
}

// O(log sizeSet)
void SortedSetIterator::first() {
    int node = multime.bst.root;
    if (multime.bst.root != -1)
    {
        top = -1;
        while (node != NULL_POS)
        {
            Travers[++top] = node;
            node = multime.bst.left[node];
        }
        if (top >= 0)
            currentNode = Travers[top];
        else
            currentNode = NULL_POS;
    }
    else
        currentNode = NULL_POS;
}

// O(log sizeSet)
void SortedSetIterator::next() {
    if (top >= 0)
    {
        int node = Travers[top];
        top--;
        if (multime.bst.right[node] != NULL_POS)
        {
            node = multime.bst.right[node];
            while (node != NULL_POS)
            {
                Travers[++top] = node;
                node = multime.bst.left[node];
            }
        }
        if (top >= 0)
            currentNode = Travers[top];
        else
            currentNode = NULL_POS;
    }
    else
        throw std::exception();
}

// theta(1)
TElem SortedSetIterator::getCurrent()
{
    if (top >= 0)
        return multime.bst.info[currentNode];
    else
        throw std::exception();
}

// theta(1)
bool SortedSetIterator::valid() const {
    return currentNode != NULL_POS;
}