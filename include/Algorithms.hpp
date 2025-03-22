#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include "graph.hpp"

namespace graph{
	class Algorithms{

		public:
		
		Graph bfs(Graph g, int vertex);

		Graph dfs(Graph g, int vertex);

		Graph dijkstra(Graph g, int vertex);

		Graph prim(Graph g);

		Graph kruskal(Graph g);
	};
}
#endif