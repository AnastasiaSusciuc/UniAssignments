#include <fstream>
#include <iostream>
#include "TestDG/testDG.h"
#include <chrono>
using namespace std::chrono;

int main() {

    TestDG::run_all_tests();

    return 0;
}
