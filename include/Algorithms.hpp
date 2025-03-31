#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include "./namespace/graph.hpp"

namespace graph{
	class Algorithms{

		public:

		/**
		 * @brief BFS algorithm on a given graph and a vertex
		 *  and returns a BFS tree.
		 *  
		 * @param g Graph
		 * @param vertex Root
		 * @return Graph A tree where the vertex is the root
		 */
		Graph static bfs(Graph g, int vertex);

		Graph static dfs(Graph g, int vertex);

		int static DFS_Visit(int u,int &time,int *color,int *pie,int *discovery,int *finish,Graph g);

		Graph static dijkstra(Graph g, int vertex);

		Graph static prim(Graph g);

		Graph static kruskal(Graph g);
	};
}
#endif