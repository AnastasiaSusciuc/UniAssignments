//
// Created by susci on 4/7/2021.
//

#include <queue>
#include <vector>

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
