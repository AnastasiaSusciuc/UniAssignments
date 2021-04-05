import unittest

from Graphs.DirectedGraph import DirectedGraph


class TestDirectedGraph(unittest.TestCase):

    def run_all(self):
        self.test_add_node()
        self.test_add_edge()
        self.test_remove_node()
        self.test_exists_edge()
        self.test_degree()
        self.test_get_nodes()
        self.test_in_out_bound_edges()
        self.test_copy_graph()

    def test_add_node(self):

        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)
        g.add_node(3)
        g.add_node(4)
        g.add_node(4)

        self.assertEqual(g.get_number_of_nodes(), 4)

    def test_add_edge(self):
        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)
        g.add_node(3)

        g.add_edge(1, 2, 10)
        g.add_edge(1, 3, 7)

        self.assertEqual(g.get_number_of_edges(), 2)

        with self.assertRaises(ValueError):
            g.add_edge(10, 3, 7)

        with self.assertRaises(ValueError):
            g.add_edge(1, 30, 7)

        g.add_edge(1, 3, 9)                 # same edge different cost
        self.assertEqual(g.get_number_of_edges(), 2)

    def test_remove_node(self):
        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)
        g.add_node(3)
        g.add_node(4)

        g.add_edge(1, 2, 10)
        g.add_edge(1, 3, 7)

        g.remove_node(1)

        self.assertEqual(g.get_number_of_nodes(), 3)
        self.assertEqual(g.get_number_of_edges(), 0)

        g.add_edge(2, 3, 7)
        g.remove_node(10)

        self.assertEqual(g.get_number_of_nodes(), 3)
        self.assertEqual(g.get_number_of_edges(), 1)

    def test_degree(self):
        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)
        g.add_node(3)
        g.add_node(4)

        g.add_edge(1, 4, 10)
        g.add_edge(1, 3, 7)
        g.add_edge(2, 4, 8)

        self.assertEqual(g.in_degree(1), 0)
        self.assertEqual(g.in_degree(2), 0)
        self.assertEqual(g.in_degree(3), 1)
        self.assertEqual(g.in_degree(4), 2)

        self.assertEqual(g.out_degree(1), 2)
        self.assertEqual(g.out_degree(2), 1)
        self.assertEqual(g.out_degree(3), 0)
        self.assertEqual(g.out_degree(4), 0)

    def test_get_nodes(self):
        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)
        g.add_node(3)
        g.add_node(4)
        count = 0
        for i in g.get_nodes():
            count = count+1
            self.assertEqual(i, count)

    def test_in_out_bound_edges(self):
        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)
        g.add_node(3)
        g.add_node(4)

        g.add_edge(1, 4, 10)
        g.add_edge(1, 3, 7)
        g.add_edge(1, 2, 5)
        g.add_edge(2, 4, 8)

        result_outbound = [4, 3, 2]

        index = 0
        for node_in in g.outbound_edges(1):
            self.assertEqual(node_in, result_outbound[index])
            index = index + 1

        index = 0
        result_inbound = [1, 2]
        for node_in in g.inbound_edges(4):
            self.assertEqual(node_in, result_inbound[index])
            index = index + 1

    def test_copy_graph(self):
        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)
        g.add_node(3)
        g.add_node(4)
        g.add_node(5)

        g.add_edge(1, 4, 10)
        g.add_edge(1, 3, 7)
        g.add_edge(1, 2, 5)
        g.add_edge(2, 4, 8)

        copied_graph = g.get_copy_of_graph()

        copied_graph.add_node(10)
        copied_graph.add_edge(1, 10, 200)

        self.assertEqual(g.get_number_of_edges(), 4)
        self.assertEqual(copied_graph.get_number_of_edges(), 5)

        self.assertEqual(g.get_number_of_nodes(), 5)
        self.assertEqual(copied_graph.get_number_of_nodes(), 6)

    def test_exists_edge(self):
        g = DirectedGraph()

        g.add_node(1)
        g.add_node(2)

        g.add_edge(1, 2, 10)

        self.assertEqual(g.exists_edge(1, 2), True)
        self.assertEqual(g.exists_edge(2, 1), False)


if __name__ == "__main__":
    unittest.main()
