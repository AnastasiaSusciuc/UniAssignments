#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    int node = m.bst.root;
    if (m.bst.root != -1)
    {
        while (!Travers.empty())
            Travers.pop();
        while (node != NULL_POS)
        {
            Travers.push(node);
            node = m.bst.left[node];
        }
        if (!Travers.empty())
            currentNode = Travers.top();
        else
            currentNode = NULL_POS;
    }
    else
        currentNode = NULL_POS;
}


void SortedSetIterator::first() {
    int node = multime.bst.root;
    if (multime.bst.root != -1)
    {
        while (!Travers.empty())
            Travers.pop();
        while (node != NULL_POS)
        {
            Travers.push(node);
            node = multime.bst.left[node];
        }
        if (!Travers.empty())
            currentNode = Travers.top();
        else
            currentNode = NULL_POS;
    }
    else
        currentNode = NULL_POS;
}


void SortedSetIterator::next() {
    if (!Travers.empty())
    {
        int node = Travers.top();
        Travers.pop();
        if (multime.bst.right[node] != NULL_POS)
        {
            node = multime.bst.right[node];
            while (node != NULL_POS)
            {
                Travers.push(node);
                node = multime.bst.left[node];
            }
        }
        if (!Travers.empty())
            currentNode = Travers.top();
        else
            currentNode = NULL_POS;
    }
    else
        throw std::exception();
}


TElem SortedSetIterator::getCurrent()
{
    if (!Travers.empty())
        return multime.bst.info[currentNode];
    else
        throw std::exception();
}

bool SortedSetIterator::valid() const {
    return currentNode != NULL_POS;
}

