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
    DirectedGraph g;
    for (int i = 1; i <= 8; i++)
        g.add_node(i);

    g.add_edge(1, 2, 0);
    g.add_edge(2, 6, 0);
    g.add_edge(6, 7, 0);
    g.add_edge(7, 6, 0);
    g.add_edge(3, 1, 0);
    g.add_edge(3, 4, 0);
    g.add_edge(2, 3, 0);
    g.add_edge(4, 5, 0);
    g.add_edge(5, 4, 0);
    g.add_edge(6, 5, 0);
    g.add_edge(5, 8, 0);
    g.add_edge(8, 7, 0);

    SCCTarjanAlgorithm tarjan(g) ;
    tarjan.findSCCs();
    tarjan.print_SCCs();

    return 0;
}
