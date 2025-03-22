#include <iostream>
#include "../include/Graph.hpp"
#include "../include/graph.hpp"

using namespace graph;

void Graph::addEdge(int s,int t, int w=1){}

void Graph::removeEdge(int a, int b){}

void Graph::print_graph(){
	for (size_t i = 0; i < this->V; i++)
	{
		for (size_t j = 0; i < this->V; j++)
		{
			std::cout << this->adjList[i][j] << ", " << std::endl;
		}
		std::cout<< std::endl;
	}
	
}