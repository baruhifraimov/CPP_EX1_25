#include <iostream>
#include "../include/Graph.hpp"
#include "../include/graph.hpp"



using namespace graph;

Graph::Graph(int V){
	this->V = V;
	adjlist = new Pnode[V];
	for (size_t i = 0; i < V; i++)
	{
		adjlist[i] = nullptr;
	}
}

Graph::~Graph(){

	for (size_t i = 0; i < V; i++)
	{
		while(!adjlist[i]){
			Pnode curr = adjlist[i];
			adjlist[i] = adjlist[i]->next;
			delete curr;
		}
		delete[] adjlist[i];
	}

	delete[] adjlist;

}

void Graph::addEdge(int s,int t, int w=0){
	Pnode source = adjlist[s];
	while (!source->next && source->index != t)
	{
		source = source->next;
	}
	if(source->index == t){
		std::cout << "The edge already exists!" << std::endl;
		return;
	}
	source->next = new Node(t,w);

	Pnode sink = adjlist[t];
	while (!sink->next)
	{
		sink = sink->next;
	}
	sink->next = new Node(s,w);
}

void Graph::removeEdge(int a, int b){

	for (size_t i = 0; !adjlist[b]; i++)
	{
		if(adjlist[b]->next->index == a){
			Pnode temp = adjlist[b]->next;
			adjlist[b]->next = temp->next;
			delete temp;
		}
	}

	for (size_t i = 0; adjlist[a] != nullptr; i++)
	{
		if(adjlist[a]->next->index == b){
			Pnode temp = adjlist[a]->next;
			adjlist[a]->next = temp->next;
			delete temp;
		}
	}
	
}

void Graph::print_graph(){
	for (size_t i = 0; i < V; i++)
	{
		while(adjlist[i]){
			std::cout << "V:" << i << " --" << "("<< adjlist[i]->edgeWeight << ")"<< "-- " << "V:" << adjlist[i]->index << std::endl;
			adjlist[i] = adjlist[i]->next;
		}
	}
	
}