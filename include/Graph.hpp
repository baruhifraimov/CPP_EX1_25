#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graph.hpp"
#include <iostream>


namespace graph{

	// The vertices
	typedef struct _Node{
		int index;
		int edgeWeight;
		Pnode next;
		_Node(int value, int w) : index(value),edgeWeight(w=0), next(nullptr){}
	
	}Node,*Pnode;

	class Graph{
		// number of vertexes
		int V;
		// the graph itself, array of nodes(vertices)
		Pnode* adjlist;
		public:

			Graph(int V);
				
			
			~Graph();

			/**
			 * @brief Adds an edge (not directed) to the graph
			 * 
			 * @param s first vertix
			 * @param t second vertix
			 * @param w edge weight
			 */
			void addEdge(int s, int t, int w = 1);

			/**
			 
			 */

			 /**
			  * @brief 
			  * Removes edge given two int numbers that represent an edge and deletes it from the graph
			  * @throws: exception if the edge is invalid 
			  * @param a 
			  * @param b 
			  */
			void removeEdge(int a, int b);

			/**
			 * @brief prints the graph
			 * 
			 */
			void print_graph();

	};
}

#endif