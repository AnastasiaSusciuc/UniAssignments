#include "MatrixIterator.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) : lines(nrLines), cols(nrCols) {
    head = tail = nullptr;
}


//  Complexity: theta(1)
int Matrix::nrLines() const {
    return lines;
}


//  Complexity: theta(1)
int Matrix::nrColumns() const {
	return cols;
}


//  Complexity: same as searchPosition
//  Best Case: theta(1) (element is head of sll)
//  Worst Case: theta(n) (n - size of sll; it is not found)
//  Total Case: O(n)
TElem Matrix::element(int i, int j) const {
	validatePosition(i, j);
	auto node = searchPosition(i, j);

	if (node == nullptr) return NULL_TELEM;
	return node->value;
}


//  Complexity: determined by the searchPosition, addElem and remove operation
//  Remove is theta(1), while searchPosition and addElem O(n)
//  Best Case: theta(1) (element is head of sll)
//  Worst Case: theta(n) (n - size of sll; it is not found)
//  Total Case: O(n)
TElem Matrix::modify(int i, int j, TElem e) {
    validatePosition(i, j);
    auto node = searchPosition(i, j);

    if (node == nullptr) {
        if (e == 0) return NULL_TELEM;
        addElem(i, j, e);
        return NULL_TELEM;
    }

    auto value = node->value;
    node->value = e;
    if (e == 0) {
        if (node == head) {
            if (head == tail) {
                head = tail = nullptr;
                delete node;
            }
            else {
                head = head->next;
                head->prev = nullptr;
                delete node;
            }
        }
        else {
            if (node == tail) {
                tail = node->prev;
                tail->next = nullptr;
                delete node;
            }
            else {
                node->next->prev = node->prev;
                node->prev->next = node->next;
                delete node;
            }
        }
    }
    return value;
}


//  Best Case: theta(1) (element is head of list)
//  Worst Case: theta(n) (n - size of sll)
//  Total case: O(n)
Matrix::DLLNode *Matrix::searchPosition(int i, int j) const {
    auto begin = head;
    while (begin != nullptr && cmpPositions(begin->line, begin->column, i, j)) {
        if (begin->line == i && begin->column == j) return begin;
        begin = begin->next;
    }   return nullptr;
}


//  Best Case: theta(1) (we insert it as the new head)
//  Worst Case: theta(n) (n - size of sll)
//  Total Case: O(n)
void Matrix::addElem(int i, int j, int e) {
    auto node = new DLLNode({i, j, e, nullptr, nullptr});

    if (head == nullptr) { head = tail = node; return; }

    auto ptr = head;
    DLLNode *before = nullptr;
    while (ptr != nullptr && cmpPositions(ptr->line, ptr->column, i, j)) {
        before = ptr;
        ptr = ptr->next;
    }

    if (before == nullptr) {
        head->prev = node;
        node->next = head;
        head = node;
        return;
    }
    else if (before == tail) {
        node->next = before->next;
        before->next = node;
        node->prev = before;
        tail = node;
    }
    else {
        node->next = before->next;
        node->next->prev = node;
        before->next = node;
        node->prev = before;
    }
}


//  Complexity: theta(1)
void Matrix::validatePosition(int i, int j) const {
    if (i < 0)      throw std::exception();
    if (j < 0)      throw std::exception();
    if (i >= lines) throw std::exception();
    if (j >= cols)  throw std::exception();
}


//  Complexity: theta(1)
bool Matrix::cmpPositions(int i, int j, int i2, int j2) {
    if (i == i2) return j <= j2;
    return i < i2;
}


Matrix::~Matrix() {
    auto node = head;
    while (node != nullptr) {
        auto cpy = node;
        node = node->next;
        delete cpy;
    }
}

MatrixIterator Matrix::iterator() const {
    return MatrixIterator(*this);
}


