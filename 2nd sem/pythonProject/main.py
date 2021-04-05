from Externals.read_write import read_graph_from_file
from Graphs.DirectedGraph import DirectedGraph
from TestDG.testDirectedGraph import TestDirectedGraph


if __name__ == "__main__":

    test = TestDirectedGraph()
    test.run_all()

    g = DirectedGraph()
    # generate_random_graph(g, 5, 7)
    read_graph_from_file(g, "graph1m.txt")

    print("NODES: ", g.get_number_of_nodes())
    print("EDGES: ", g.get_number_of_edges())

    print("ALL NODES:")
    for i in g.get_nodes():
        print("\t", i)

    print("ALL EDGES:")
    for i in g.get_edges():
        print("\t", i)

    # g.add_edge(2, 4, 2222)
    #
    # print("ADDED NEW edge")
    # print("ALL NODES:")
    # for i in g.get_nodes():
    #     print("\t", i)
    #
    # print("ALL VERTICES:")
    # for i in g.get_edges():
    #     print("\t", i)
    #
    # print("INBOUND 1")
    # for i in g.inbound_edges(1):
    #     print(i)
