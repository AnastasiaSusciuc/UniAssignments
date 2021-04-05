#include "src/Set/Set.h"
#include "src/SetIterator/SetIterator.h"
#include "src/ExtendedTest/ExtendedTest.h"
#include "src/ShortTest/ShortTest.h"
#include <stack>
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

// 17205437 microseconds - V1
// 18318986 microseconds - V2

int main()
{
    auto start = high_resolution_clock::now();

    testAll();
	testAllExtended();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    cout << "It all took only " << duration.count() << " seconds :)" << endl;
    cout << "That's all!" << endl;

	system("pause");
}



