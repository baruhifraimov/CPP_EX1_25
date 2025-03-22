#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graph.hpp"
#include <iostream>

namespace graph{
	class Graph{
		int V; // number of vertexes
		// the graph itself, array of arrays that each unit is a vertex that 
		// holds his neighbouts, the limit is clique
		int ** adjList;

		public:

		//inline
			Graph(int V){
				this->V = V;
				this->adjList = new int*[V];
				for (size_t i = 0; i < V; i++)
				{
					adjList[i] = new int[V];
				}
			}
				
			
			~Graph(){
				// delete the inner arrays and the array itself
				for (size_t i = 0; i < V; i++)
				{
					delete[] adjList[i];
				}
				delete[] adjList;
			}

			/**
			 * Adds an edge (not directed) to the graph
			 */
			void addEdge(int s, int t, int w = 1);

			/**
			 * Removes edge given two int numbers that represent an edge and deletes it from the graph
			 * @throws: exception if the edge is invalid
			 */
			void removeEdge(int a, int b);

			/**
			 * Prints the graph
			 */
			void print_graph();

	};
}

#endif