from copy import deepcopy


class DirectedGraph:

    def __init__(self, inbound=None, outbound=None, edges=None, nodes=None):
        self.__directDG = deepcopy(inbound) if inbound else {}
        self.__transposedDG = deepcopy(outbound) if outbound else {}
        self.__edges = deepcopy(edges) if edges else {}
        self.__nodes = nodes if nodes else 0

    def get_copy_of_graph(self):
        return DirectedGraph(self.__directDG, self.__transposedDG, self.__edges, self.__nodes)

    def set_nodes(self, nodes):
        self.__nodes = nodes

    def get_number_of_edges(self):
        return len(self.__edges)

    def get_number_of_nodes(self):
        return self.__nodes

    def get_nodes(self):
        for node in self.__directDG.keys():
            yield node

    def get_edges(self):
        for k in self.__edges.keys():
            yield k[0], k[1], self.__edges[k]

    def add_node(self, node: int):
        if node in self.__directDG.keys():
            return

        self.__nodes = self.__nodes+1
        self.__directDG[node] = []
        self.__transposedDG[node] = []

    def add_edge(self, node_in: int, node_out: int, cost: int):
        if node_in not in self.__directDG.keys():
            raise ValueError("Node {} not in graph".format(node_in))
        if node_out not in self.__transposedDG.keys():
            raise ValueError("Node {} not in graph".format(node_out))

        for node in self.__directDG[node_in]:
            if node == node_out:
                # We already have the edge
                self.__edges[(node_in, node_out)] = cost
                return

        self.__directDG[node_in].append(node_out)
        self.__transposedDG[node_out].append(node_in)
        self.__edges[(node_in, node_out)] = cost

    def remove_node(self, node):
        # Remove all edges
        if node not in self.__directDG.keys():
            return

        for node_in in self.__transposedDG[node]:
            self.__directDG[node_in].remove(node)
            self.__edges.pop((node_in, node))

        for node_out in self.__directDG[node]:
            self.__transposedDG[node_out].remove(node)
            self.__edges.pop((node, node_out))

        if node in self.__directDG:
            del self.__directDG[node]

        if node in self.__transposedDG:
            del self.__transposedDG[node]

        self.__nodes = self.__nodes-1

    def exists_edge(self, node1, node2):
        for node_out in self.__directDG[node1]:
            if node_out == node2:
                return True

        return False

    def in_degree(self, node):
        return len(self.__transposedDG[node])

    def out_degree(self, node):
        return len(self.__directDG[node])

    def print_list_edges(self):
        for k in self.__edges.keys():
            print("Edge {}->{} with cost {}".format(k[0], k[1], self.__edges[k]))

    def outbound_edges(self, node: int):
        for node_in in self.__directDG[node]:
            yield node_in

    def inbound_edges(self, node: int):
        for node_out in self.__transposedDG[node]:
            yield node_out

    def change_cost(self, node_in: int, node_out: int, cost: int):
        if (node_in, node_out) not in self.__edges:
            raise ValueError("Edge {}->{} not in graph".format(node_in, node_out))

        if node_in not in self.__directDG.keys():
            raise ValueError("Node {} not in graph".format(node_in))
        if node_out not in self.__transposedDG.keys():
            raise ValueError("Node {} not in graph".format(node_out))

        for node in self.__directDG[node_in]:
            if node == node_out:
                self.__edges[(node_in, node_out)] = cost
                return
