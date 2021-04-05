#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

/*
ADT SortedMultiMap – using a SLL with unique keys ordered based on a relation on the
keys. Every key will be associated with a SLL of the values belonging to that key
 * */

int main(){

    testAll();
    testAllExtended();

    std::cout<< "Finished SMM Tests!" <<std::endl;

	return 0;
}
