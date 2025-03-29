#include "../../include/namespace/graph.hpp"
#include "../../include/Graph.hpp"
#include "../../include/Algorithms.hpp"


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

	g.print_graph();
	std::cout << "printed graph ..." << std::endl;

	return 0;
}