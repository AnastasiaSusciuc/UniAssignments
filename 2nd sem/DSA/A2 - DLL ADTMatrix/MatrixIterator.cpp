//
// Created by quackdratic on 4/6/2021.
//

#include "MatrixIterator.h"

#include <stdexcept>


//  Complexity: theta(1)
MatrixIterator::MatrixIterator(const Matrix &matrix) : matrix(matrix) {
    node = matrix.head;
    line = 0;
    col = 0;
}

//  Complexity: theta(1)
TElem MatrixIterator::getLine() {
    if (!this->valid()) throw std::runtime_error("");
    return line;
}

//  Complexity: theta(1)
TElem MatrixIterator::getCol() {
    if (!this->valid()) throw std::runtime_error("");
    return col;
}

//  Complexity: theta(1)
TElem MatrixIterator::getValue() {
    if (!this->valid()) throw std::runtime_error("");
    if (node->line == line && node->column == col) return node->value;
    return NULL_TELEM;
}

//  Complexity: theta(1)
void MatrixIterator::next() {
    if (!this->valid()) throw std::runtime_error("");
    if (node->line == line && node->column == col) node = node->next;
    col += 1;
    if (col == matrix.cols) col = 0, line += 1;
}

//  Complexity: theta(1)
void MatrixIterator::first() {
    line = 0;
    col = 0;
    node = matrix.head;
}

//  Complexity: theta(1)
bool MatrixIterator::valid() {
    return (line < matrix.lines && col < matrix.cols);
}
