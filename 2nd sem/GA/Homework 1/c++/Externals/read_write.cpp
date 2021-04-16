//
// Created by susci on 3/28/2021.
//

#include "../Graphs/DirectedGraph.h"
#include <string>
#include <fstream>
//
//void read_graph_from_file_DA(DirectedGraph& graph)
//{
//    std::ifstream f("graph.in");
//    int source, target, cost;
//    int number_nodes, number_edges;
//
//    f >> number_nodes >> number_edges;
//
//    for (int i = 0; i < number_nodes; i++)
//        graph.add_node(i);
//
//    for (int i = 0; i < number_edges; i++)
//    {
//        f >> source >> target >> cost;
//        graph.add_edge(source, target, cost);
//    }
//    f.close();
//}

//void write_graph_in_file(DirectedGraph& graph, std::string& filename)
//{
//    std::ofstream g(filename);
//
//    int nodes = graph.get_number_nodes();
//    int edges = graph.get_number_edges();
//
//    g << nodes << " " << edges << '\n';
//
//    std::vector <std::tuple<int, int, int> > all_edges = graph.parse_edges();
//
////    for (auto & all_edge : all_edges)
////    {
////        g << std::get<0>(all_edge) << " " << std::get<1 >(all_edge) << " " << std::get<2>(all_edge) << "\n";
////    }
//
//}