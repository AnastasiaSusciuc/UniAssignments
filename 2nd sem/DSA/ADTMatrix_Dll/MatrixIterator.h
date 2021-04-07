#pragma once

#include "Matrix.h"


class MatrixIterator {
    friend class Matrix;
public:

private:
    MatrixIterator(const Matrix &matrix);
    const Matrix &matrix;

    Matrix::DLLNode *node;
    int line, col;

public:
    TElem getLine();
    TElem getCol();
    TElem getValue();

    void next();
    void first();
    bool valid();

};
