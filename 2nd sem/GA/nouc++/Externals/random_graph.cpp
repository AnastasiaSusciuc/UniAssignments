//
// Created by susci on 3/28/2021.
//

#include "../Graphs/DirectedGraph.h"
#include <random>

//void create_random_graph(DirectedGraph& graph, int number_nodes, int number_edges)
//{
//    for (int i = 0; i < number_nodes; i++)
//        graph.add_node(i);
//
//    std::random_device rd;  //Will be used to obtain a seed for the random number engine
//    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//    std::uniform_int_distribution<> distrib(0, number_edges-1);
//
//    std::random_device rd_cost;
//    std::mt19937 gen_cost(rd());
//    std::uniform_int_distribution<> distrib_cost(0, number_edges-1);
//
//    int source, target, cost;
//    while (graph.get_number_edges() < number_edges)
//    {
//        source = distrib(gen);
//        target = distrib(gen);
//        cost = distrib_cost(gen_cost);
//
//        if(!graph.exists_edge(source, target))
//            graph.add_edge(source, target, cost);
//    }
//}