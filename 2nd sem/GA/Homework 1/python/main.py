from Externals.read_write import read_graph_from_file, write_graph_in_file
from Graphs.DirectedGraph import DirectedGraph
from TestDG.testDirectedGraph import TestDirectedGraph
import time

# 1m graph 16 sec
# 100k graph 1.3 sec
# 10k graph 0.1 sec
# 1k graph 0.009 sec

if __name__ == "__main__":

    test = TestDirectedGraph()
    test.run_all()

    # start = time.perf_counter()
    g = DirectedGraph()

    read_graph_from_file(g, "graph.in")

    print("There is an edge between 1 and 2 in the original graph: ", g.exists_edge(1, 2))

    copy_graph = g.get_copy_of_graph()

    print("There is an edge between 1 and 2 in the copied graph: ", copy_graph.exists_edge(1, 2))

    print("Remove node 2 in the original graph")
    g.remove_node(2)

    print("There is an edge between 1 and 2 in the original graph: ", g.exists_edge(1, 2))
    print("There is an edge between 1 and 2 in the copied graph: ", copy_graph.exists_edge(1, 2))

    # stop = time.perf_counter()

    # print("It took ", stop-start, " seconds")
