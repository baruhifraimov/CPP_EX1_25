#include "../../include/namespace/graph.hpp"
#include "../../include/Graph.hpp"
#include "../../include/Algorithms.hpp"
#include "../../include/DataStructures.hpp"


int main(){
	// debug
	std::cout << "Starting program..." << std::endl;

	graph::Graph g(7);
	std::cout << "created graph..." << std::endl;
	g.addEdge(1,2,13);
	std::cout << "added edge ..." << std::endl;
	g.addEdge(6,2,12);
	std::cout << "added edge ..." << std::endl;
	g.addEdge(1,3,0);
	std::cout << "added edge ..." << std::endl;

	std::cout << "printed graph ..." << std::endl;
	g.print_graph();

	std::cout << "remove edge ..." << std::endl;
	g.removeEdge(1,2);

	std::cout << "printed graph ..." << std::endl;
	g.print_graph();

	std::cout << "remove invalid edge ..." << std::endl;

	g.removeEdge(1,12);
	g.print_graph();

	UnionFind n(3);
	int x = n.find(1);
	std::cout << x << std::endl;
	n.unite(1,2);
	x = n.find(2);
	std::cout << x << std::endl;

	return 0;
}