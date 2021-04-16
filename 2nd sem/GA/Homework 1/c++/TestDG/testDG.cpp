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
    catch (std::runtime_error)
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
    catch (std::runtime_error)
    {
        assert(true);
    }

    try{
        g.add_edge(100, 2, 10);
        assert(false);
    }
    catch (std::runtime_error)
    {
        assert(true);
    }

    try{
        g.add_edge(1, 200, 10);
        assert(false);
    }
    catch (std::runtime_error)
    {
        assert(true);
    }

    assert(g.get_number_edges() == 2);

    try{
        g.get_edge_cost(1, 200);
        assert(false);
    }
    catch (std::runtime_error)
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
    catch (std::runtime_error)
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


