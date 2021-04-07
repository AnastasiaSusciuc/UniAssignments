#include <fstream>
#include <iostream>
#include "TestDG/testDG.h"
#include "Externals/random_graph.cpp"
#include "Externals/bfs.cpp"
#include <chrono>
using namespace std::chrono;


//int find_lowest_length_path(DirectedGraph& graph, int start, int end)
//{
//    int number_nodes = graph.get_number_nodes();
//    int INF = 0x3f3f3f3f;
//    std::queue <int> Q;
//    std::vector <int> distance(number_nodes+5);
//    std::fill(distance.begin(), distance.end(), INF);
//
//    distance[end] = 0;
//    Q.push(end);
//
//    while (!Q.empty() && distance[start] == INF)
//    {
//        int node = Q.front();
//        // std::cout << node << ' ';
//        Q.pop();
//
//        std::vector <std::pair <int, int> > edges_in = graph.parse_edges_in_with_costs(node);
//
////        std::cout << "NODE " << node << '\n';
////        for (auto& neighbour: edges_in)
////            std::cout << neighbour.first << " " << neighbour.second << '\n';
//
//        for (auto& neighbour: edges_in)
//        {
//            if (distance[neighbour.first] > distance[node] + neighbour.second)
//            {
//                distance[neighbour.first] = distance[node] + neighbour.second;
//                Q.push(neighbour.first);
//            }
//        }
//
//    }
////    std::cout << '\n';
////
////    for (int i = 0; i <= 7; i++)
////        std::cout << i << " " << distance[i] << '\n';
//
//    return distance[start];
//}

int main() {

    TestDG::run_all_tests();

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

    // std::cout << find_lowest_length_path(g, 1, 5);
    assert(find_lowest_length_path(g, 1, 5) == 13);


    return 0;
}
