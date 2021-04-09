#include <fstream>
#include <iostream>
#include "TestDG/testDG.h"
#include <chrono>
using namespace std::chrono;

int main() {

    TestDG::run_all_tests();
/*
8 12
1 2
2 6
6 7
7 6
3 1
3 4
2 3
4 5
5 4
6 5
5 8
8 7
 * */


    return 0;
}
