

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
