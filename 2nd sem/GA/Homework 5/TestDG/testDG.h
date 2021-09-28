//
// Created by susci on 3/28/2021.
//

#ifndef C___TESTDG_H
#define C___TESTDG_H

#include <cassert>
#include <algorithm>
#include <iostream>
#include "../Graphs/DirectedGraph.h"
#include "../Externals/external_functions.h"

class TestDG{
private:
    static void test_add_node();
    static void test_add_edge();
    static void test_change_cost_edge();
    static void test_remove_node();
    static void test_remove_edge();
    static void test_in_degree();
    static void test_out_degree();
    static void test_parse_in_out_edges();
    static void test_copy_graph();
    static void test_all_edges();
    static void test_backward_bfs();
    static void test_Tarjan_SCC();
    static void test_biconex_components();
    static void test_DAG();
    static void test_Hamilton_TSP();
    static void test_minimum_cycle();
public:
    static void run_all_tests();

};

#endif //C___TESTDG_H
