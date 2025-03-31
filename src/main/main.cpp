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
	g.addEdge(1,2,13);
	std::cout << "added edge ..." << std::endl;
	g.addEdge(6,2,12);
	std::cout << "added edge ..." << std::endl;
	g.addEdge(2,4,12);
	std::cout << "added edge ..." << std::endl;
	g.addEdge(4,5,12);
	std::cout << "added edge ..." << std::endl;
	g.addEdge(5,1,12);
	std::cout << "added edge ..." << std::endl;
	g.addEdge(1,3,0);
	std::cout << "added edge ..." << std::endl;
	g.print_graph();
	std::cout << "BFS Tree:" << std::endl;
	graph::Graph t = Algorithms::bfs(g, 1);
	t.print_graph();

	graph::Graph et = Algorithms::dfs(g,1);
	et.print_graph();
	return 0;
}