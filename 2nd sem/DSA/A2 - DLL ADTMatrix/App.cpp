
#include <iostream>
#include "Matrix.h"
#include "MatrixIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

#include <vector>
#include <stdexcept>
#include <cassert>

using namespace std;


int main() {
	testAll();
	testAllExtended();
	cout << "Test End" << endl;

    {
        Matrix matrix(4, 4);
        matrix.modify(0, 0, 1);
        matrix.modify(0, 1, 1);
        matrix.modify(1, 1, 2);
        matrix.modify(2, 2, 3);
        matrix.modify(3, 3, 4);
        matrix.modify(0, 1, 0);
        matrix.modify(0, 0, 5);

        auto it = matrix.iterator();
        std::vector <std::vector <int>> arr(4, std::vector <int> (4, -1));
        while (it.valid()) {
            arr[it.getLine()][it.getCol()] = it.getValue();
            it.next();
        }
        try { it.getLine(); assert(false); }
        catch (std::runtime_error&) { assert(true); }
        try { it.getCol(); assert(false); }
        catch (std::runtime_error&) { assert(true); }
        try { it.getValue(); assert(false); }
        catch (std::runtime_error&) { assert(true); }

        for (int i=0, j; i<4; ++i) {
            for (j=0; j<4; ++j) {
                std::cout << arr[i][j] << ' ';
            }   std::cout << '\n';
        }
    }

	//  system("pause");

}