//baruh.ifraimov@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "./namespace/graph.hpp"
#include <iostream>


namespace graph{

	// The vertices
	typedef struct _Node{
			int index;
			int edgeWeight;
			_Node* next;
		public:
			_Node():next(nullptr){}
			_Node(int value, int w = 1) : index(value),edgeWeight(w){
				this->next = nullptr;}
	}Node,*Pnode;

	class Graph{
		// number of vertices [V], number of edges [E]
		int V,E;
		// the graph itself, array of nodes(vertices)
		Pnode* adjlist;
		public:
			Graph(int V);
			Graph(const Graph& other);
			~Graph();

			/**
			 * @brief Adds an edge (not directed) to the graph
			 * 
			 * @param s first vertix
			 * @param t second vertix
			 * @param w edge weight
			 */
			void addEdge(int s, int t, int w=1);

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

			/**
			 * @brief Get the Graph object
			 * 
			 * @return Pnode* adjlist
			 */
			Pnode* getGraph();

			/**
			 * @brief Returns the number of vertices of the graph
			 * TL;DR - returns |V|
			 * 
			 */
			int getNumVertices();


			/**
			 * @brief Returns the number of Edges of the graph
			 * TL;DR - returns |E|
			 * 
			 */
			int getNumEdges();
	};
}

#endif