#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class MatrixIterator;

class Matrix {
    friend class MatrixIterator;

private:
    class DLLNode {
    public:
        int      line;
        int      column;
        TElem    value;
        DLLNode* next;
        DLLNode* prev;
    }   *head, *tail;
    int lines, cols;

    void        validatePosition(int i, int j) const;
    DLLNode*    searchPosition  (int i, int j) const;
    void        addElem         (int i, int j, int e);
    static bool cmpPositions    (int i, int j, int i2, int j2);

public:
	//constructor
	Matrix(int nrLines, int nrCols);
    ~Matrix();

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

    MatrixIterator iterator() const;

};