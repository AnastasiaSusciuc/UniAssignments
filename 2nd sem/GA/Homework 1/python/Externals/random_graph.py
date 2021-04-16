import random


def generate_random_graph(graph, nodes, edges):

    INF = 10000

    for i in range(nodes):
        graph.add_node(i)

    while graph.get_number_of_edges() < edges:
        node_in = random.randint(0, nodes-1)
        node_out = random.randint(0, nodes-1)
        cost = random.randint(-INF, INF)

        if not graph.exists_edge(node_in, node_out):
            graph.add_edge(node_in, node_out, cost)
