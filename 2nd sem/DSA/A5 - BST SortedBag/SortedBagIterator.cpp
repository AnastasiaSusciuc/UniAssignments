#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
//    current = bag.bst.root;
//
//    /// from the root we go left as much as we can
//    if (current != -1)
//        while (bag.bst.left[current] != NULL_POS)
//            current = bag.bst.left[current];

    Travers = new int[bag.dimension];
    first();
}

TComp SortedBagIterator::getCurrent() {
//    if (current == -1)
//        throw std::exception();
//
//    return bag.bst.info[current];

    if (top >= 0)
        return bag.bst.info[currentNode];
    else
        throw std::exception();
}

bool SortedBagIterator::valid() {
//    return (current != -1);
    return (currentNode != NULL_POS);
}

void SortedBagIterator::next() {
//    if (current == -1)
//        throw std::exception();
//
//    current = bag.find_succesor(current);

    if (top >= 0)
    {
        int node = Travers[top];
        top--;
        if (bag.bst.right[node] != NULL_POS)
        {
            node = bag.bst.right[node];
            while (node != NULL_POS)
            {
                Travers[++top] = node;
                node = bag.bst.left[node];
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

void SortedBagIterator::first() {
//    current = bag.bst.root;
//
//    /// from the root we go left as much as we can
//    if (current != -1)
//        while (bag.bst.left[current] != NULL_POS)
//            current = bag.bst.left[current];

    int node = bag.bst.root;
    if (bag.bst.root != -1)
    {
        top = -1;
        while (node != NULL_POS)
        {
            Travers[++top] = node;
            node = bag.bst.left[node];
        }
        if (top >= 0)
            currentNode = Travers[top];
        else
            currentNode = NULL_POS;
    }
    else
        currentNode = NULL_POS;
}

