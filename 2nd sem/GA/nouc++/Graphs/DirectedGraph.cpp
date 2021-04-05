//
// Created by susci on 3/28/2021.
//

#include <algorithm>
#include <vector>
#include "DirectedGraph.h"

DirectedGraph::DirectedGraph() = default;


DirectedGraph::DirectedGraph(const DirectedGraph &graph) {
    nodes = graph.nodes;
    edges = graph.edges;
    directDG = graph.directDG;
    transposedDG = graph.transposedDG;
}

int DirectedGraph::get_number_nodes() const {
    return nodes.size();
}

int DirectedGraph::get_number_edges() const {
    return edges.size();
}

bool DirectedGraph::exists_node(int node){
    return std::find(nodes.begin(), nodes.end(), node) != nodes.end();
}

bool DirectedGraph::exists_edge(int source, int target){
    if (!exists_node(source) || !exists_node(target))
        throw std::runtime_error{"given nodes are invalid!\n"};
    else
        return std::find(directDG[source].begin(), directDG[source].end(), target) != directDG[source].end();
}

int DirectedGraph::in_degree(int node){
    if (!exists_node(node))
        throw std::runtime_error{"invalid given node!\n"};
    return transposedDG[node].size();
}

int DirectedGraph::out_degree(int node){
    if (!exists_node(node))
        throw std::runtime_error{"invalid given node!\n"};
    return directDG[node].size();
}

void DirectedGraph::add_node(int node) {
    if (exists_node(node))
        throw std::runtime_error{"node already in graph!\n"};
    nodes.push_back(node);
    transposedDG[node] = std::vector <int>();
    directDG[node] = std::vector <int>();
}

void DirectedGraph::add_edge(int source, int target, int cost) {
    if (!exists_node(source))
        throw std::runtime_error{"Invalid source node!\n"};

    if (!exists_node(target))
        throw std::runtime_error{"Invalid target node!\n"};

    if (exists_edge(source, target))
        throw std::runtime_error{"Edge already exists!\n"};

    edges[std::make_pair(source, target)] = cost;
    directDG[source].push_back(target);
    transposedDG[target].push_back(source);
}

int DirectedGraph::get_edge_cost(int source, int target){
    if (!exists_node(source))
        throw std::runtime_error{"Invalid source node!\n"};

    if (!exists_node(target))
        throw std::runtime_error{"Invalid target node!\n"};

    if (!exists_edge(source, target))
        throw std::runtime_error{"Edge doesn't exist!\n"};

    return edges[std::make_pair(source, target)];
}

void DirectedGraph::change_edge_cost(int source, int target, int cost) {
    if (!exists_node(source))
        throw std::runtime_error{"Invalid source node!\n"};

    if (!exists_node(target))
        throw std::runtime_error{"Invalid target node!\n"};

    if (!exists_edge(source, target))
        throw std::runtime_error{"Edge doesn't exist!\n"};

    edges[std::make_pair(source, target)] = cost;
}

void DirectedGraph::remove_node(int node) {
    if (!exists_node(node))
        throw std::runtime_error{"Invalid node!\n"};

    for (int& sources : directDG[node]) {
        transposedDG[sources].erase(find(transposedDG[sources].begin(), transposedDG[sources].end(), node));
        edges.erase(edges.find(std::make_pair(node, sources)));
    }
    for (int& sources : transposedDG[node]) {
        directDG[sources].erase(find(directDG[sources].begin(), directDG[sources].end(), node));
        edges.erase(edges.find(std::make_pair(sources, node)));
    }
    directDG.erase(directDG.find(node));
    transposedDG.erase(transposedDG.find(node));
    nodes.erase(find(nodes.begin(), nodes.end(), node));
}

void DirectedGraph::remove_edge(int source, int target) {
    if (!exists_edge(source, target))
        throw std::runtime_error{"invalid edge!\n"};
    directDG[source].erase(find(directDG[source].begin(), directDG[source].end(), target));
    transposedDG[target].erase(find(transposedDG[target].begin(), transposedDG[target].end(), source));
    edges.erase(edges.find(std::make_pair(source, target)));
}

std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> DirectedGraph::parse_through_vertices() {
    return {nodes.begin(), nodes.end()};
}

std::vector<int> DirectedGraph::parse_edges_out(int node) {

    std::vector<int> edges_out;
    for (int & it : directDG[node])
        edges_out.push_back(it);

    return edges_out;
}

std::vector<int> DirectedGraph::parse_edges_in(int node) {
    std::vector<int> edges_in;
    for (int & it : transposedDG[node])
        edges_in.push_back(it);

    return edges_in;
}

std::vector<std::tuple<int, int, int> > DirectedGraph::parse_edges() {

    std::vector<std::tuple<int, int, int> > all_edges;
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        int source = it->first.first;
        int target = it->first.second;
        int cost = it->second;
        all_edges.emplace_back(std::tie(source, target, cost));
    }

    return all_edges;
}



//std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> DirectedGraph::parse_through_edges() {
//    return {edges.begin(), edges.end()};
//}

//std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> DirectedGraph::parse_edges_out(int node) {
//    if (!exists_node(node))
//        throw std::runtime_error{"invalid given node!\n"};
//    return std::make_pair(directDG[node].begin(), directDG[node].end());
//}
//
//std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> DirectedGraph::parse_edges_in(int node) {
//    if (!exists_node(node))
//        throw std::runtime_error{"invalid given node!\n"};
//    return std::make_pair(transposedDG[node].begin(), transposedDG[node].end());
//}


