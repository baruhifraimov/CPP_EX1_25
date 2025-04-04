//baruh.ifraimov@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include "./namespace/graph.hpp"
#include "DataStructures.hpp"

namespace graph{
	class Algorithms{

		public:

		/**
		 * @brief BFS algorithm on a given graph and a vertex
		 *  and returns a BFS tree.
		 *  
		 * @param g The graph being traversed
		 * @param vertex Root vertex
		 * @return Graph BFS tree graph
		 */
		Graph static bfs(Graph g, int vertex);

		/**
		 * @brief DFS algorithm, on a given graph and a vertex
		 * return a forest/tree of all the paths that are available from
		 * the given vertex
		 * 
		 * @param g The graph being traversed
		 * @param vertex Root vertex
		 * @return Graph DFS tree/forest Graph
		 */
		Graph static dfs(Graph g, int vertex);

		/**
		 * @brief 
		 * 
		 * @param u The current vertex being visited
		 * @param time Reference to the current time counter
		 * @param color Array tracking the state of each vertex (White/Gray/Black)
		 * @param pie Array tracking the parent of each vertex in the DFS tree
		 * @param discovery Array storing the discovery time of each vertex
		 * @param finish Array storing the finish time of each vertex
		 * @param g The graph being traversed
		 * @return int The updated time counter after finishing the vertex and its subtree
		 */
		int static DFS_Visit(int u,int &time,int *color,int *pie,int *discovery,int *finish,Graph g);

		/**
		 * @brief 
		 * 
		 * @param g 
		 * @param vertex 
		 * @return Graph 
		 */
		Graph static dijkstra(Graph g, int vertex);

		void static relax(int u_index, Pnode &edge, int *distance, int* pie, Pqueue &pqueue);

		Graph static prim(Graph g);

		Graph static kruskal(Graph g);
	};
}
#endif