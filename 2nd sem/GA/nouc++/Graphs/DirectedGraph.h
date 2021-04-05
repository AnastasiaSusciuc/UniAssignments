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
    DirectedGraph(const DirectedGraph& graph);
    void add_node(int node);
    void add_edge(int source, int target, int cost);

    int get_number_nodes() const;
    // void set_number_nodes(int no_nodes);

    int get_number_edges() const;
    // void set_number_edges(int no_edges);

    // todo parse the nodes/edges
    bool exists_node(int node);
    bool exists_edge(int node_in, int node_out);

    int in_degree(int node);
    int out_degree(int node);

    int get_edge_cost(int source, int target);
    void change_edge_cost(int source, int target, int cost);

    void remove_node(int node);
    void remove_edge(int source, int target);
    std::pair< std::vector<int>::const_iterator, std::vector<int>::const_iterator> parse_through_vertices();
    std::vector <int> parse_edges_out(int node);
    std::vector <int> parse_edges_in(int node);
    std::vector <std::tuple<int, int, int> > parse_edges();
};

#endif //C___DIRECTEDGRAPH_H
