#include "../../include/namespace/graph.hpp"
#include "../../include/Graph.hpp"
#include "../../include/Algorithms.hpp"
#include "../../include/DataStructures.hpp"

using namespace graph;

int main(){
	// debug
	std::cout << "Starting program..." << std::endl;

	graph::Graph g(7);
	std::cout << "created graph..." << std::endl;

	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 3, 7);
	g.addEdge(1, 4, 1);
	g.addEdge(2, 5, 3);
	g.addEdge(3, 5, 1);
	g.addEdge(4, 6, 5);
	g.addEdge(5, 6, 2);




	g.print_graph();

	graph::Graph t = graph::Algorithms::dijkstra(g,1);
	t.print_graph();

	return 0;
}