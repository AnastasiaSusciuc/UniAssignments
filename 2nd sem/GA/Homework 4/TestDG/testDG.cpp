//
// Created by susci on 3/28/2021.
//

#include "testDG.h"

void TestDG::run_all_tests() {
    test_add_node();
    test_add_edge();
    test_change_cost_edge();
    test_remove_node();
    test_remove_edge();
    test_in_degree();
    test_out_degree();
    test_parse_in_out_edges();
    test_copy_graph();
    test_all_edges();
    test_backward_bfs();
    test_Tarjan_SCC();
    test_biconex_components();
    test_DAG();
    std::cout << "TESTS FINISHED!\n";
}

void TestDG::test_add_node() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(4);
    g.add_node(5);

    assert(g.get_number_nodes() == 4);

    try{
        g.add_node(5);
        assert(false);
    }
    catch (std::runtime_error&)
    {
        assert(true);
    }

}

void TestDG::test_add_edge() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);

    try{
        g.add_edge(1, 2, 10);
        assert(false);
    }
    catch (std::runtime_error&)
    {
        assert(true);
    }

    try{
        g.add_edge(100, 2, 10);
        assert(false);
    }
    catch (std::runtime_error&)
    {
        assert(true);
    }

    try{
        g.add_edge(1, 200, 10);
        assert(false);
    }
    catch (std::runtime_error&)
    {
        assert(true);
    }

    assert(g.get_number_edges() == 2);

    try{
        g.get_edge_cost(1, 200);
        assert(false);
    }
    catch (std::runtime_error&)
    {
        assert(true);
    }

    assert(g.get_edge_cost(1, 2) == 5);
}

void TestDG::test_change_cost_edge() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);

    assert(g.get_edge_cost(1, 2) == 5);
    assert(g.get_edge_cost(2, 4) == 9);

    g.change_edge_cost(1, 2, 20);
    g.change_edge_cost(2, 4, 30);

    assert(g.get_edge_cost(1, 2) == 20);
    assert(g.get_edge_cost(2, 4) == 30);

    try{
        g.change_edge_cost(1, 200, 20);
        assert(false);
    }
    catch (std::runtime_error&)
    {
        assert(true);
    }
}

void TestDG::test_remove_node() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 1, 19);
    g.add_edge(5, 4, 7);
    g.add_edge(4, 1, 21);

    assert(g.get_number_edges() == 6);
    assert(g.get_number_nodes() == 4);

    g.remove_node(1);

    assert(g.get_number_edges() == 2);
    assert(g.get_number_nodes() == 3);
}

void TestDG::test_remove_edge() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 1, 19);
    g.add_edge(5, 4, 7);
    g.add_edge(4, 1, 21);

    g.remove_edge(4, 1);
    g.remove_edge(1, 4);

    assert(g.get_number_edges() == 4);
    assert(g.get_number_nodes() == 4);
}

void TestDG::test_in_degree() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 1, 19);
    g.add_edge(5, 4, 7);
    g.add_edge(4, 1, 21);

    assert(g.in_degree(1) == 2);
}

void TestDG::test_out_degree() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 1, 19);
    g.add_edge(5, 4, 7);
    g.add_edge(1, 5, 21);

    assert(g.out_degree(1) == 3);
}

void TestDG::test_parse_in_out_edges() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(3);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 1, 19);
    g.add_edge(5, 4, 7);
    g.add_edge(1, 5, 21);

    std::vector <int> edges_out = g.parse_edges_out(1);

    assert(edges_out[0] == 2);
    assert(edges_out[1] == 4);
    assert(edges_out[2] == 5);

    std::vector <int> edges_in = g.parse_edges_in(4);

    assert(edges_in[0] == 2);
    assert(edges_in[1] == 1);
    assert(edges_in[2] == 5);
}

void TestDG::test_copy_graph() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(3);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 3, 9);

    DirectedGraph copy_g = g;

    copy_g.add_edge(2, 1, 1000);
    copy_g.add_node(10);

    assert(g.get_number_nodes() == 3);
    assert(g.get_number_edges() == 2);

    assert(copy_g.get_number_nodes() == 4);
    assert(copy_g.get_number_edges() == 3);

    g.remove_node(3);

    assert(g.get_number_nodes() == 2);

    assert(copy_g.get_number_nodes() == 4);

}

void TestDG::test_all_edges() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(3);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(1, 4, 10);


    std::vector <std::tuple<int, int, int> > all_edges = g.parse_edges();

    assert(all_edges[0] == std::make_tuple(1, 2, 5));
    assert(all_edges[1] == std::make_tuple(1, 4, 10));
    assert(all_edges[2] == std::make_tuple(2, 4, 9));

}

void TestDG::test_backward_bfs() {
    DirectedGraph g;
    g.add_node(1);
    g.add_node(2);
    g.add_node(3);
    g.add_node(4);
    g.add_node(5);

    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(1, 4, 10);
    g.add_edge(2, 3, 6);
    g.add_edge(3, 5, 2);

    assert(find_lowest_length_path(g, 1, 5) == 13);

    g.add_edge(1, 5, 12);

    assert(find_lowest_length_path(g, 1, 5) == 12);

}

void TestDG::test_Tarjan_SCC() {
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

    std::vector <int> expected_result[3];
    for (int i = 1; i <= 3; i++)
        expected_result[2].push_back(i);

    for (int i = 4; i <= 8; i++)
        expected_result[1].push_back(i);

    std::vector<std::vector<int>>& SCCs = tarjan.get_SCCs();
    int number_SCCs = tarjan.get_number_SCCs();

    for (int i = 1; i <= number_SCCs; i++)
    {
        std::sort(SCCs[i].begin(), SCCs[i].end());

        assert(SCCs[i].size() == expected_result[i].size());
        for (int j = 0; j < SCCs[i].size(); j++)
            assert(SCCs[i][j] == expected_result[i][j]);
    }
}

void TestDG::test_biconex_components() {

    DirectedGraph g;
    for (int i = 1; i <= 8; i++)
        g.add_node(i);

    g.add_edge(1, 2, 0);// g.add_edge(2, 1, 0);
    g.add_edge(2, 3, 0);// g.add_edge(3, 2, 0);
    g.add_edge(3, 4, 0);// g.add_edge(4, 3, 0);
    g.add_edge(4, 1, 0);// g.add_edge(1, 4, 0);
    g.add_edge(1, 5, 0);// g.add_edge(5, 1, 0);
    g.add_edge(5, 6, 0);// g.add_edge(6, 5, 0);
    g.add_edge(6, 7, 0);// g.add_edge(6, 7, 0);
    g.add_edge(7, 5, 0);// g.add_edge(5, 7, 0);
    g.add_edge(7, 8, 0);// g.add_edge(8, 7, 0);


    BiconexAlgorithm biconex(g);

    int number_biconex_comp = biconex.get_number_biconex_components();
    std::vector<std::vector<int>>& biconex_components = biconex.get_biconex_components();

    std::vector <int> expected_result[5];
    expected_result[1].push_back(1); expected_result[1].push_back(2); expected_result[1].push_back(3); expected_result[1].push_back(4);
    expected_result[2].push_back(7); expected_result[2].push_back(8);
    expected_result[3].push_back(5); expected_result[3].push_back(6); expected_result[3].push_back(7);
    expected_result[4].push_back(1); expected_result[4].push_back(5);

    for (int i = 1; i <= number_biconex_comp; i++)
    {
        std::sort(biconex_components[i].begin(), biconex_components[i].end());

        assert(biconex_components[i].size() == expected_result[i].size());
        for (int j = 0; j < biconex_components[i].size(); j++) {
            assert(biconex_components[i][j] == expected_result[i][j]);
        }
    }
}

void TestDG::test_DAG() {
    DirectedGraph graph1;
    for (int i = 1; i <= 4; i++)
        graph1.add_node(i);

    graph1.add_edge(1, 2, 0);
    graph1.add_edge(2, 3, 0);
    graph1.add_edge(3, 4, 0);
    graph1.add_edge(4, 1, 0);

    std::vector <int> dur;
    CriticalActivities cp(graph1, dur);

    assert(cp.is_DAG() == false);

    graph1.remove_edge(4, 1);
    assert(cp.is_DAG() == true);


    DirectedGraph graph2;
    for (int i = 1; i <= 6; i++)
        graph2.add_node(i);

    graph2.add_edge(1, 2, 0);
    graph2.add_edge(2, 3, 0);
    graph2.add_edge(3, 5, 0);
    graph2.add_edge(1, 4, 0);
    graph2.add_edge(5, 6, 0);
    graph2.add_edge(4, 5, 0);

    std::vector <int> duration = {0, 2, 3, 4, 2, 5, 1};
    CriticalActivities cpm(graph2, duration);
    cpm.get_earliest_latest();

    assert(cpm.get_earliest()[1] == 0);
    assert(cpm.get_earliest()[2] == 2);
    assert(cpm.get_earliest()[3] == 5);
    assert(cpm.get_earliest()[4] == 2);
    assert(cpm.get_earliest()[5] == 9);
    assert(cpm.get_earliest()[6] == 14);

    assert(cpm.get_latest()[1] == 0);
    assert(cpm.get_latest()[2] == 2);
    assert(cpm.get_latest()[3] == 5);
    assert(cpm.get_latest()[4] == 7);
    assert(cpm.get_latest()[5] == 9);
    assert(cpm.get_latest()[6] == 14);

    assert(cpm.get_critical_nodes()[0] == 1);
    assert(cpm.get_critical_nodes()[1] == 2);
    assert(cpm.get_critical_nodes()[2] == 3);
    assert(cpm.get_critical_nodes()[3] == 5);
    assert(cpm.get_critical_nodes()[4] == 6);

    assert(cpm.earliest_time_finish_project() == 15);

    DirectedGraph graph3;
    for (int i = 1; i <= 6; i++)
        graph3.add_node(i);

    graph3.add_edge(1, 2, 0);
    graph3.add_edge(1, 3, 0);
    graph3.add_edge(1, 6, 0);
    graph3.add_edge(2, 4, 0);
    graph3.add_edge(3, 4, 0);
    graph3.add_edge(3, 5, 0);
    graph3.add_edge(4, 6, 0);
    graph3.add_edge(5, 6, 0);

    std::vector <int> duration2 = {0, 0, 0, 0, 0, 0, 0};
    CriticalActivities cpm2(graph3, duration2);

    assert(cpm2.get_different_paths(1, 6) == 4);
    
    graph3.remove_edge(4, 6);
    assert(cpm2.get_different_paths(1, 6) == 2);

}


