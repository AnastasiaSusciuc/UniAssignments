//
// Created by susci on 4/7/2021.
//

#include "external_functions.h"

void read_graph_from_file(DirectedGraph& graph)
{
    std::ifstream f("../graph.in");
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
        g << std::get<0>(all_edge) << " " << std::get<1>(all_edge) << " " << std::get<2>(all_edge) << "\n";
    }

}

void create_random_graph(DirectedGraph& graph, int number_nodes, int number_edges)
{
    for (int i = 0; i < number_nodes; i++)
        graph.add_node(i);

    std::random_device hardware_random;  // will be used to obtain a seed for the random number engine
    std::mt19937 gen(hardware_random()); // standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, number_nodes-1);

    std::random_device hardware_random_cost;
    std::mt19937 gen_cost(hardware_random_cost());
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

int find_lowest_length_path(DirectedGraph& graph, int start, int end)
{
    int number_nodes = graph.get_number_nodes();
    int INF = 0x3f3f3f3f;
    std::queue <int> Q;
    std::vector <int> distance(number_nodes+5);
    std::fill(distance.begin(), distance.end(), INF);

    distance[end] = 0;
    Q.push(end);

    while (!Q.empty() && distance[start] == INF)
    {
        int node = Q.front();
        Q.pop();

        std::vector <std::pair <int, int> > edges_in = graph.parse_edges_in_with_costs(node);

        for (auto& neighbour: edges_in)
        {
            if (distance[neighbour.first] > distance[node] + neighbour.second)
            {
                distance[neighbour.first] = distance[node] + neighbour.second;
                Q.push(neighbour.first);
            }
        }

    }
    return distance[start];
}

SCCTarjanAlgorithm::SCCTarjanAlgorithm(DirectedGraph& gr): graph{gr} {
    int number_nodes = gr.get_number_nodes();
    this->on_stack.resize(number_nodes+2);
    this->ids.resize(number_nodes+2);
    this->low_link_value.resize(number_nodes+2);

    SCC.resize(number_nodes+2);
    findSCCs();
}

void SCCTarjanAlgorithm::findSCCs() {
    std::vector <int> all_nodes = graph.parse_through_vertices();
    initialization();

    for (auto& node: all_nodes)
    {
        if (ids[node] == -1)
            dfs(node);
    }
}

void SCCTarjanAlgorithm::dfs(int node) {
    stack.push(node);
    on_stack[node] = true;
    ids[node] = low_link_value[node] = ++counter_ids;

    std::vector <int> neighbour_list = graph.parse_edges_out(node);

    for (auto& neighbour: neighbour_list)
    {
        if (ids[neighbour] == -1)
        {
            dfs(neighbour);
            low_link_value[node] = std::min(low_link_value[neighbour], low_link_value[node]);
        }
        if (on_stack[neighbour])
            low_link_value[node] = std::min(low_link_value[neighbour], low_link_value[node]);
    }

    if (ids[node] == low_link_value[node])
    {
        counter_SCC++;
        while(!stack.empty())
        {
            int node_in_SCC = stack.top();
            on_stack[node_in_SCC] = false;
            SCC[counter_SCC].push_back(node_in_SCC);
            stack.pop();
            if (node_in_SCC == node)
                break;
        }
    }

}

void SCCTarjanAlgorithm::print_SCCs() {
    std::cout << counter_SCC << '\n';
    for (int i = 1; i <= counter_SCC; i++)
    {
        for (auto& node: SCC[i])
            std::cout << node << " ";
        std::cout << '\n';
    }
}

std::vector<std::vector<int> >& SCCTarjanAlgorithm::get_SCCs(){
    return SCC;   // just the reference!!
}

int SCCTarjanAlgorithm::get_number_SCCs() const {
    return counter_SCC;
}

BiconexAlgorithm::BiconexAlgorithm(DirectedGraph& ref_graph) : graph{ref_graph} {
    int number_nodes = graph.get_number_nodes();
    this->lowest_lvl.resize(number_nodes+5);
    this->lvl.resize(number_nodes+5);
    this->used.resize(number_nodes+5);
    this->biconex_components.resize(number_nodes+5);
    find_biconex_component();
}

void BiconexAlgorithm::find_biconex_component() {
    std::vector <int> all_nodes = graph.parse_through_vertices();

    for (auto& node: all_nodes)
    {
        if (!used[node])
            dfs(node, 1);
    }
}

void BiconexAlgorithm::dfs(int node, int level) {
    used[node] = true;
    lvl[node] = lowest_lvl[node] = level;
    stack.push(node);

    std::vector <int> neighbour_list = graph.parse_edges_out(node);

    for (auto& neighbour: neighbour_list)
    {
        if (used[neighbour]) lowest_lvl[node] = std::min(lowest_lvl[node], lvl[neighbour]);
        else
        {
            dfs(neighbour, level+1);

            if (lvl[node] <= lowest_lvl[neighbour])
            {
                this->counter_biconex_components++;

                while (stack.top() != neighbour)
                {
                    biconex_components[counter_biconex_components].push_back(stack.top());
                    stack.pop();
                }
                biconex_components[counter_biconex_components].push_back(stack.top());
                stack.pop();
                biconex_components[counter_biconex_components].push_back(node);
            }
            lowest_lvl[node] = std::min(lowest_lvl[node], lowest_lvl[neighbour]);
        }
    }
}

int BiconexAlgorithm::get_number_biconex_components(){

    return this->counter_biconex_components;
}

std::vector<std::vector<int> > &BiconexAlgorithm::get_biconex_components() {
    return biconex_components;
}
