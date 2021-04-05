//
// Created by susci on 3/28/2021.
//

#ifndef C___DIRECTEDGRAPH_H
#define C___DIRECTEDGRAPH_H

#pragma once
#include <map>
#include <vector>

class DirectedGraph{

private:
    std::vector <int> nodes;
    std::map < std::pair <int, int>, int> edges;
    std::map <int, std::vector<int> > directDG;
    std::map <int, std::vector<int> > transposedDG;
public:

    DirectedGraph();
    /*
     * creates the DirectedGraph object
     * */
    DirectedGraph(const DirectedGraph& graph);
    /*
     * description: copy constructor
     *              constructs a new object with the same properties as 'graph'
     * param1:      graph - of type DirectedGraph
     *
     * returns:     -
     * */

    void add_node(int node);
    /*
     * description: adds a node in the graph
     *
     * param1:      node - integer
     *
     * returns:     -
     *
     * throws:      runtime error if the node already exists in the graph
     * */

    void add_edge(int source, int target, int cost);
    /*
     * description: adds teh edge from node 'source' to node 'target' with the cost 'cost' in the graph
     *
     * param1:      source - integer; has to be a node from the graph
     * param2:      target - integer; has to be a node from the graph
     * param3:      cost   - integer; represents the cost of the edge
     *
     * returns:     -
     *
     * throws:      runtime error if the node 'source' is not in the graph
     *              runtime error if the node 'target' is not in the graph
     *              runtime error if the edge source->target already exists
     * */

    int get_number_nodes() const;
    /*
     * description: getter for the number of nodes in the graph
     *
     * returns:     integer - number of nodes in the graph
     * */

    int get_number_edges() const;
    /*
      * description: getter for the number of edges in the graph
      *
      * returns:     integer - number of edges in the graph
      * */

    bool exists_node(int node);
    /*
     * description: checks whether there exists in the graph the node 'node'
     *
     * returns:     true - if the node is in the graph
     *              false - otherwise
     * */

    bool exists_edge(int node_in, int node_out);
    /*
     * description: checks whether there exists in the graph an edge from 'node_in' to 'node_out'
     *
     * returns:     true - if it exists such an edge is in the graph
     *              false - otherwise
     * */

    int in_degree(int node);
    /*
     * description: checks the in degree of the node 'node'
     *
     * param1:      node - integer; has to be a node in the graph
     *
     * returns:     the in_degree of the node
     *
     * throws:        runtime_error if 'node' is not in the graph
     * */

    int out_degree(int node);
    /*
     * description: checks the in degree of the node 'node'
     *
     * param1:       node - integer; has to be a node in the graph
     *
     * returns:     the in_degree of the node
     *
     * throws:        runtime_error if 'node' is not in the graph
     * */

    int get_edge_cost(int source, int target);
    /*
     * description: gets the cost of the edge from 'source' to 'target'
     *
     * param1:       source - integer; has to be a node in the graph
     * param2:       target - integer; has to be a node in the graph
     *
     * returns:      the cost of the edge source->target
     *
     * throws:        runtime_error if 'node' is not in the graph
     * */

    void change_edge_cost(int source, int target, int cost);
    /*
     * description: changes the cost of the edge 'source'->'target' with the new cost 'cost'
     *
     * param1:      source - integer; has to be a node in the graph
     * param2:      target - integer; has to be a node in the graph
     *
     * returns:     -
     *
     * throws:      runtime error if either 'source' or 'target' are not in the graph as nodes
     *              runtime error if either there is no edge from 'source' to 'target' in the graph
     * */

    void remove_node(int node);
    /*
     * description: removes a node from the graph together with all the edges that were adjacent with it
     * */

    void remove_edge(int source, int target);
    std::pair< std::vector<int>::const_iterator, std::vector<int>::const_iterator> parse_through_vertices();
    std::vector <int> parse_edges_out(int node);
    std::vector <int> parse_edges_in(int node);
    std::vector <std::tuple<int, int, int> > parse_edges();
};

#endif //C___DIRECTEDGRAPH_H
