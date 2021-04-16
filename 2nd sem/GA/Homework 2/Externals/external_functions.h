//
// Created by susci on 4/7/2021.
//

#ifndef C___EXTERNAL_FUNCTIONS_H
#define C___EXTERNAL_FUNCTIONS_H
#include "../Graphs/DirectedGraph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <queue>
#include <stack>
#include <bitset>

void read_graph_from_file(DirectedGraph& graph);
/*
 * description:  - reads from the file 'graph.in' a graph that is structured so:
 *                      - first line: two integers, namely the number of nodes (n) and the number of edges (m)
 *                                                                                              of the directed graph
 *                      - on the following m lines contain three integers, namely tha start of the edge, the end ant the cost
 *               - adds in the graph the nodes 1, 2, ... n, and all the edges
 *
 * param1:       - graph - DirectedGraph - the graph whose attributes are read from file
 *
 * returns:      -
 * */
void write_graph_in_file(DirectedGraph& graph);
/*
 * description:  - writes in the file 'graph.out' the structure of the in memory graph
 *                      - on the first line, the number of nodes and the number of edges
 *                      - on the following line, the start of an edge, its end and its cost
 *
 * param1:       - graph - DirectedGraph - the graph whose attributes are read from file
 * */
void create_random_graph(DirectedGraph& graph, int number_nodes, int number_edges);
/*
 * description:  - creates a random graph, with a fixed number of nodes and edges
 *               - using an operating system based random generator we set the seed
 *               - with the truly random seed, a mersenne_twister_engine generates all the random edges
 *               - there will be added exactly 'number_edges' new edges
 *
 * param1:       - graph - reference to a DirectedGraph object - namely the graph we want to generate into
 * param2:       - number_nodes - int - the number of nodes of the graph
 * param3:       - number_edges - int - the number of edges of the graph
 *
 * returns:      -
 * */

int find_lowest_length_path(DirectedGraph& graph, int start, int end);
/*
 * description:  - finds the lowest length path from the start to end;
 *               - it is implemented on the inbound graph, the bfs starting from the end and
 *                                                                          stopping when the distance to start is found
 * param1:       - graph - reference to a DirectedGraph object - namely the graph we work on
 * param2:       - start - int - the number of the start node
 * param3:       - end - int - the number of the end node
 *
 * returns:      - the lowest length of a path found between node start and node end
 * */


class SCCTarjanAlgorithm{
private:
    DirectedGraph& graph;                       // the graph where we start the Tarjan's algorithm
    std::stack  <int>  stack;                   // to keep track of the order of the nodes traversed in the DFS
    std::vector <int>  ids;                     // each node will have assigned a unique id
    std::vector <int>  low_link_value;          // the smallest id of a reachable node from the current one
    std::vector <bool> on_stack;                // true if the node is on the stack, false otherwise
    std::vector < std::vector <int> > SCC;      // each SCC will be stored on a different line

    int counter_ids = 0;                        // will keep the last used id
    int counter_SCC = 0;                        // count the number of strongly connected components found

    void initialization() { std::fill(this->ids.begin(), this->ids.end(), -1);}
    /*
     * description:  sets all ids to -1, meaning the nodes with this is have not been visited
     *
     * returns:      -
     * */
    void dfs(int node);
    /*
     * description:  a basic DFS traversal with some additions, namely:
     *                  - each time a node is visited, it is added on the stack and an id is given to it
     *                  - the idea of Tarjan's algorithm is to keep track of the smallest id reachable form a certain
     *                          node, that is low_link_value
     *                  - the low_link_value is computed as the minimum of the node's id, and the minimum of all nodes
     *                          that are reachable from it and are on the stack
     *                  - the name of critic node is given to those nodes that have the id equal to the low_link_value
     *                  - the moment we backtrack from the dfs and we arrive in a critic node, we found a SCC, that can
     *                          be extracted from the stack
     * param1:       node - int- the start of the DFS
     *
     * returns:      -
     * */
    void findSCCs();
    /*
     * description:  - parses through the vertices
     *               - starts the dfs from each node that was not visited yet
     *
     * params:       -
     *
     * returns:      -
     * */
public:
    explicit SCCTarjanAlgorithm(DirectedGraph& graph);
    /*
     * description:  constructor of the Tarjan's Algorithm object
     *
     * param1:       graph - reference to object of type DirectedGraph
     * */


    void print_SCCs();
    /*
     * description:  -prints on the console:
     *                      - on the first line, the number of strongly connected components
     *                      - on the following lines, the components of a SCC, separated by spaces, in an arbitrary order
     * params:       -
     *
     * returns:      -
     * */

    std::vector < std::vector <int> >& get_SCCs();
    /*
     * description:  - getter for the reference of the strongly connected components
     *
     * returns:      - reference to a std::vector < std::vector <int> >
     * */

    int get_number_SCCs() const;
    /*
     * description:  - getter for the number of strongly connected components
     *
     * returns:      - integer, the number of SCCs found in the graph
     * */

};

class BiconexAlgorithm{
private:
    DirectedGraph& graph;                       // reference to a graph object
    std::stack  <int> stack;                    // to keep track of the order of the nodes traversed in the DFS
    std::vector <int> lvl;                      // the level of a node with respect to the start node of the DFS
    std::vector <int> lowest_lvl;               // the lowest level we can reach from a node
    std::vector <bool> used;                    // node was visited or not
    std::vector <std::vector <int> > biconex_components; // each line represents a biconex component
    int counter_biconex_components = 0;         // the number of biconex components

    void find_biconex_component();              // starts all the DFS s
    void dfs(int node, int level);

public:
    explicit BiconexAlgorithm(DirectedGraph& ref_graph);
    int get_number_biconex_components();
    std::vector < std::vector <int> >& get_biconex_components();
};

//class DijkstraAlgorithm{
//private:
//    DirectedGraph& graph;
//    std::vector <int> distance;
//public:
//    DijkstraAlgorithm(DirectedGraph& graph);
//    void run_Dijkstra(int node);
//
//};

#endif //C___EXTERNAL_FUNCTIONS_H
