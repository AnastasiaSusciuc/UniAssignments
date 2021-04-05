

def read_graph_from_file(graph, file_path):

    with open(file_path) as fp:
        line = fp.readline()
        elements = line.split()
        if len(elements) != 2:
            raise ValueError("Incorrect file format! First line should only contain 2 integers!\n")

        nodes = int(elements[0])
        edges = int(elements[1])

        for i in range(nodes):
            graph.add_node(i)

        for i in range(edges):
            line = fp.readline()
            elements = line.split()

            if len(elements) != 3:
                raise ValueError("Incorrect file format!\n")

            graph.add_edge(int(elements[0]), int(elements[1]), int(elements[2]))


def write_graph_in_file(graph, file_path):
    g = open(file_path, "w")

    g.write(str(graph.get_number_of_nodes()) + " " + str(graph.get_number_of_edges()) + "\n")

    for source, target, cost in graph.get_edges():
        g.write(str(source) + " " + str(target) + " " + str(cost) + "\n")

    g.close()
