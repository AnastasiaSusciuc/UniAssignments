//
// Created by susci on 4/7/2021.
//

#ifndef C___EXTERNAL_FUNCTIONS_H
#define C___EXTERNAL_FUNCTIONS_H
#include "../Graphs/DirectedGraph.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <queue>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f

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

class DijkstraAlgorithm{
private:
    DirectedGraph& graph;
    std::vector <int> distance;
public:
    explicit DijkstraAlgorithm(DirectedGraph& graph);
    int run_Dijkstra(int start, int end);
    /*
     * description:  - runs the backwards Dijkstra algorithm starting from node 'end' until it is found the distance to node 'start'
     *               - it is implemented with a priority queue, where greater elements have the priority, therefore we keep the -distance
     * param1:       start - int - a node from the graph
     * param2:       end - int - a node from the graph
     *
     * returns:      - integer, the distance from node start to node end
     *
     * throws:       - exception if node start or node end are not a valid nodes
     *
     * */
};

class Walks{
private:
    DirectedGraph& graph;
public:
    Walks(DirectedGraph& gr);
    int count_different_minimum_walks(int start, int end);
    /*
     * description:  - runs a backwards Dijkstra algorithm starting from node 'end'
     *               - it is implemented with a priority queue, where greater elements have the priority, therefore we keep the -distance
     *               - we keep track of the number of paths to every node
     *
     * param1:       start - int - a node from the graph
     * param2:       end - int - a node from the graph
     *
     * returns:      - integer, the distance from node start to node end
     *
     * throws:       - exception if node start or node end are not a valid nodes
     *
     * */
};

class CriticalActivities{
private:
    DirectedGraph& graph;

    std::vector <int> topological_order;                // where we keep the nodes in topological order
    std::vector <int> earliest = {0}, latest = {0};     // earliest/ latest time an activity can start
    std::vector <int> duration;                         // how long an activity takes
    std::vector <int> critical_nodes;                   // the nodes that are critical
    int earliest_time = -1;                             // earliest time the project can finish
    bool dfs(int node, bool visited[], bool *recStack);
    /*
     * description: - basic dfs that keeps track of the visited nodes in visited[]
     *              - in recStack we keep the nodes that are on the current branch of the dfs and in case we meet a
     *              node that has already been placed in the recStack we return true as we have reached a cycle
     * param1:      node - int - the current node in the dfs
     * param2:      visited - bool[] - every node that has been visited will be flagged here
     * param3:      recStack - bool[] - every node that has been visited in the current extension of the dfs is flagged here
     *
     * returns:     true - if there are no cycles
     *              false - otherwise
     * */

public:
    CriticalActivities(DirectedGraph& gr, std::vector <int> dur);
    bool is_DAG();
    void print_earliest();
    /*
     * description: - prints the earliest time every activity can start
     * */
    void print_latest();
    /*
     * description: - prints the latest time every activity can start
     * */
    void get_earliest_latest();
    /*
     * description: - computes the earliest and the latest time every activity can start
     *              - checks whether the graph is a DAG
     * */
    const std::vector <int>&  get_earliest();
    /*
     * returns:     - reference to a vector that keeps the earliest time an activity can start
     * */
    const std::vector <int>&  get_latest();
    /*
     * returns:     - reference to a vector that keeps the latest time an activity can start
     * */
    const std::vector <int>&  get_critical_nodes();
    /*
     * returns:     - reference to a vector that keeps the critical activities
     * */
    int get_different_paths(int start, int end);
    /*
     * description: - counts all the different paths from node 'start' to node 'end'
     *
     * param1:      start - node
     * param2:      end - node
     *
     * returns      - the number of different paths between two nodes
     *
     * throws:      - std::exception if either 'start' or 'end' are not valid nodes in the graph
     *
     * */
    int earliest_time_finish_project();
    /*
     * returns:     - the earliest time to finish the whole project
     * */

};

#endif //C___EXTERNAL_FUNCTIONS_H