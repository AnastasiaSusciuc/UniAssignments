#include <fstream>
#include <iostream>
#include "TestDG/testDG.h"
#include "Externals/random_graph.cpp"
#include <chrono>
using namespace std::chrono;


void read_graph_from_file(DirectedGraph& graph)
{
    std::ifstream f("../graph1k.txt");
    int number_nodes = 0, number_edges = 0;

    f >> number_nodes >> number_edges;

    for (int i = 0; i < number_nodes; i++)
        graph.add_node(i);

    int source, target, cost;
    for (int i = 0; i < number_edges; i++)
    {
        f >> source >> target >> cost;
        graph.add_edge(source, target, cost);
    }
    f.close();
}

void write_graph_in_file(DirectedGraph& graph)
{

    std::ofstream g("../graph.out");

    int nodes = graph.get_number_nodes();
    int edges = graph.get_number_edges();

    g << nodes << " " << edges << '\n';

    std::vector <std::tuple<int, int, int> > all_edges = graph.parse_edges();

    for (auto & all_edge : all_edges)
    {
        g << std::get<0>(all_edge) << " " << std::get<1 >(all_edge) << " " << std::get<2>(all_edge) << "\n";
    }

}

void create_random_graph(DirectedGraph& graph, int number_nodes, int number_edges)
{
    for (int i = 0; i < number_nodes; i++)
        graph.add_node(i);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, number_nodes-1);

    std::random_device rd_cost;
    std::mt19937 gen_cost(rd_cost());
    std::uniform_int_distribution<> distrib_cost(-1000, 1000);

    int source, target, cost;
    while (graph.get_number_edges() < number_edges)
    {
        source = distrib(gen);
        target = distrib(gen);
        cost = distrib_cost(gen_cost);

        if(!graph.exists_edge(source, target))
            graph.add_edge(source, target, cost);
    }
}

int main() {

    TestDG::run_all_tests();

    DirectedGraph graph;
    auto start = high_resolution_clock::now();
    // read_graph_from_file(graph);
    create_random_graph(graph, 10, 12);
    write_graph_in_file(graph);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    std::cout << "It all took only " << duration.count() << " seconds :)" << '\n';

    std::cout << "EXISTS IN THE GRAPH EDGE 1->3: " << graph.exists_edge(1, 3) << '\n';

    DirectedGraph copy_graph = graph;

    std::cout << "EXISTS IN THE COPY OF THE GRAPH EDGE 1->3: " << copy_graph.exists_edge(1, 3) << '\n';

    std::cout << "\nREMOVED NODE 3 FROM THE ORIGINAL GRAPH\n";
    graph.remove_node(3);

    std::cout << "EXISTS IN THE GRAPH EDGE 1->3: " << graph.exists_edge(1, 3) << '\n';
    std::cout << "EXISTS IN THE COPY OF THE GRAPH EDGE 1->3: " << copy_graph.exists_edge(1, 3) << '\n';

    return 0;
}
