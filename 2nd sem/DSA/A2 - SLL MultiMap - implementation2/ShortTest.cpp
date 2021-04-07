#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,3);
    smm.add(1,2);

    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v = smm.search(1);

    assert(v.size()==2);
    // std::cout << v[0] << " " << v[1] << '\n';

    v = smm.search(3);
    assert(v.empty());

    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	// std::cout << e.first << " " << e.second << "\n";
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());

    smm.add(1,3);
    smm.add(1,2);
    smm.add(1,4);
    smm.add(2,5);
    smm.add(3,3);
    smm.add(2,10);

    std::vector <TValue> values_key_2 = smm.removeKey(2);
    assert(values_key_2.size() == 2);
    assert(values_key_2[0] == 10);
    assert(values_key_2[1] == 5);

}

