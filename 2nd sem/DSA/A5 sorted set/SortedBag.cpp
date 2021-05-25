#include <exception>
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <vector>

SortedBag::SortedBag(Relation r) {

    bst.capacity = 10;
    bst.info = new TElem[bst.capacity];
    bst.left = new int[bst.capacity];
    bst.right = new int[bst.capacity];
    bst.parent = new int[bst.capacity];

    relation = r;
    dimension = 0;
    bst.firstEmpty = 0;
    bst.root = -1;

    for (int i = 0; i < bst.capacity; i++) {
        bst.info[i] = NULL_TCOMP;
        bst.left[i] = i + 1;                  
        bst.right[i] = NULL_POS;
        bst.parent[i] = NULL_POS;
    }

    bst.left[bst.capacity - 1] = -1;
}

void SortedBag::add(TComp e) {

    // bst empty
    if (bst.root == -1) {
        bst.info[bst.firstEmpty] = e;
        bst.parent[bst.firstEmpty] = -1;
        bst.root = bst.firstEmpty;
        bst.firstEmpty = bst.left[bst.firstEmpty];
        bst.left[bst.root] = NULL_POS;
        dimension++;
        return;
    }

    //resize if no space to add a new element
    if (bst.firstEmpty == -1)
        resize();

    //compute the right position
    int current = bst.root;
    int parent = -1;

    while (current != NULL_POS) {
        parent = current;
        if (!relation(bst.info[current], e))
            current = bst.left[current];
        else
            current = bst.right[current];
    }

    bst.info[bst.firstEmpty] = e;
    bst.parent[bst.firstEmpty] = parent;

    if (!relation(bst.info[parent], e))
        bst.left[parent] = bst.firstEmpty;
    else
        bst.right[parent] = bst.firstEmpty;

    int old = bst.firstEmpty;
    bst.firstEmpty = bst.left[bst.firstEmpty];
    bst.left[old] = NULL_POS;
    dimension++;
}


bool SortedBag::remove(TComp e) {
    if (bst.root == -1)
        return false;

    int current = bst.root;
    int parent = -1;

    while (current != NULL_POS) {
        if (bst.info[current] == e) {
            if (bst.left[current] == NULL_POS && bst.right[current] == NULL_POS) {
                if (current == bst.root) {
                    bst.left[current] = bst.firstEmpty;
                    bst.firstEmpty = current;
                    bst.root = -1;
                } else {
                    if (bst.left[parent] == current)
                        bst.left[parent] = NULL_POS;
                    else
                        bst.right[parent] = NULL_POS;

                    bst.left[current] = bst.firstEmpty;
                    bst.firstEmpty = current;
                }
                dimension--;
            } else if (bst.left[current] == NULL_POS && bst.right[current] != NULL_POS) {
                if (current == bst.root) {
                    bst.root = bst.right[current];
                    bst.left[current] = bst.firstEmpty;
                    bst.right[current] = NULL_POS;
                    bst.info[current] = NULL_TCOMP;
                    bst.firstEmpty = current;
                } else {
                    if (bst.left[parent] == current)
                        bst.left[parent] = bst.right[current];
                    else
                        bst.right[parent] = bst.right[current];
                    bst.left[current] = bst.firstEmpty;
                    bst.right[current] = NULL_POS;
                    bst.info[current] = NULL_TCOMP;
                    bst.firstEmpty = current;
                }
                dimension--;
            } else if (bst.left[current] != NULL_POS && bst.right[current] == NULL_POS) {
                if (current == bst.root) {
                    bst.root = bst.left[current];
                    bst.left[current] = bst.firstEmpty;
                    bst.right[current] = NULL_POS;
                    bst.info[current] = NULL_TCOMP;
                    bst.firstEmpty = current;
                } else {
                    if (bst.left[parent] == current)
                        bst.left[parent] = bst.left[current];
                    else
                        bst.right[parent] = bst.left[current];
                    bst.left[current] = bst.firstEmpty;
                    bst.right[current] = NULL_POS;
                    bst.info[current] = NULL_TCOMP;
                    bst.firstEmpty = current;
                }
                dimension--;
            } else {
                int max = get_max(bst.left[current]);
                remove(bst.info[max]);
                bst.info[current] = bst.info[max];

            }
            return true;
        }

        parent = current;
        if (!relation(bst.info[current], e))
            current = bst.left[current];
        else
            current = bst.right[current];
    }
    return false;
}


bool SortedBag::search(TComp elem) const {
    if (bst.root == -1)
        return false;

    int current = bst.root;
    while (current != NULL_POS) {
        if (bst.info[current] == elem)
            return true;

        if (relation(bst.info[current], elem))
            current = bst.right[current];
        else
            current = bst.left[current];
    }
    return false;
}


int SortedBag::nrOccurrences(TComp elem) const {

    if (bst.root == -1)
        return 0;

    int nrOcc=0;
    for (int i = 0; i < this->bst.capacity; i++)
        if (bst.info[i] == elem)
            nrOcc++;

    return nrOcc;

}



int SortedBag::size() const {
	//TODO - Implementation
	return dimension;
}


bool SortedBag::isEmpty() const {
	//TODO - Implementation
	return (dimension == 0);
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    delete[] bst.info;
    delete[] bst.right;
    delete[] bst.left;
    delete[] bst.parent;
}

void SortedBag::resize() {
    auto *info_new = new TElem[bst.capacity * 2];
    int *right_new = new int[bst.capacity * 2];
    int *left_new = new int[bst.capacity * 2];
    int *parent_new = new int[bst.capacity * 2];

    for (int i = 0; i < bst.capacity; i++) {
        info_new[i] = bst.info[i];
        right_new[i] = bst.right[i];
        left_new[i] = bst.left[i];
        parent_new[i] = bst.parent[i];
    }

    for (int i = bst.capacity; i < bst.capacity * 2; i++) {
        info_new[i] = NULL_TCOMP;
        right_new[i] = NULL_POS;
        left_new[i] = i + 1;
        parent_new[i] = NULL_POS;
    }

    left_new[bst.capacity * 2 - 1] = -1;

    bst.firstEmpty = bst.capacity;
    bst.capacity *= 2;

    delete[] bst.info;
    delete[] bst.right;
    delete[] bst.left;
    delete[] bst.parent;

    bst.info = info_new;
    bst.right = right_new;
    bst.left = left_new;
    bst.parent = parent_new;
}

int SortedBag::get_max(int node) const {
    int current = node;
    while (bst.right[current] != NULL_POS)
        current = bst.right[current];
    return current;
}

int SortedBag::find_parent(int node) const {
    if (node < 0 || node >= bst.capacity)
        throw std::exception();

    if (node == bst.root)
        return -1;

    int current = bst.root;

    while (current != -1 &&
            bst.left[current] != node && bst.right[current] != node)
        if (relation(bst.info[current], bst.info[node]))
            current = bst.right[current];
        else
            current = bst.left[current];

    return current;
}

int SortedBag::find_succesor(int nodePosition) const {
    int currentNodePosition;

    if (bst.right[nodePosition] != NULL_POS) {
        currentNodePosition = bst.right[nodePosition];
        while (bst.left[currentNodePosition] != NULL_POS)
            currentNodePosition = bst.left[currentNodePosition];
        return currentNodePosition;
    } else {
        int parentNodePosition = find_parent(nodePosition);
        while (parentNodePosition != -1 && relation(bst.info[parentNodePosition], bst.info[nodePosition]))
            parentNodePosition = find_parent(parentNodePosition);
        return parentNodePosition;
    }
}
