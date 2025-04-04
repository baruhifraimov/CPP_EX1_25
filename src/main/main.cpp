//baruh.ifraimov@gmail.com
#include "../../include/namespace/graph.hpp"
#include "../../include/Graph.hpp"
#include "../../include/Algorithms.hpp"
#include "../../include/DataStructures.hpp"

using namespace graph;

int main(){
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

	graph::Graph t = graph::Algorithms::dijkstra(g,0);
	t.print_graph();

	graph::Graph e = graph::Algorithms::prim(g);
	e.print_graph();

	graph::Graph x = graph::Algorithms::kruskal(g);
	x.print_graph();

	graph::Graph a = graph::Algorithms::dfs(g,4);
	a.print_graph();
	
	graph::Graph b = graph::Algorithms::bfs(g,1);
	b.print_graph();

	std::cout << "\n==========GRAPH STATS ==========" << std::endl;
	std::cout << "General Graph: |V|= "<<g.getNumVertices() << "|E|=" << g.getNumEdges()<< std::endl;
	std::cout << "Dijkstra: |V|= "<<t.getNumVertices() << "|E|=" << t.getNumEdges()<< std::endl;
	std::cout << "Prim: |V|= "<<e.getNumVertices() << "|E|=" << e.getNumEdges()<< std::endl;
	std::cout << "Kruskal: |V|= "<<x.getNumVertices() << "|E|=" << x.getNumEdges()<< std::endl;
	std::cout << "DFS: |V|= "<<a.getNumVertices() << "|E|=" << a.getNumEdges()<< std::endl;
	std::cout << "BFS: |V|= "<<b.getNumVertices() << "|E|=" << b.getNumEdges()<< std::endl;

	b.removeEdge(0,1);
	std::cout << "removed edge BFS: |V|= "<<b.getNumVertices() << "|E|=" << b.getNumEdges()<< std::endl;

	a.addEdge(3,6);
	std::cout << "added edge DFS: |V|= "<<a.getNumVertices() << "|E|=" << a.getNumEdges()<< std::endl;


	return 0;
}