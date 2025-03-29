#include <iostream>
#include "../include/Graph.hpp"
#include "../include/namespace/graph.hpp"



using namespace graph;

Graph::Graph(int V) : V(V){
	adjlist = new Pnode[V];
	for (int i = 0; i < V; i++)
	{
		adjlist[i] = new Node(i);
	}
}

Graph::~Graph(){

	for (int i = 0; i < V; i++) {
		Pnode curr = adjlist[i];
		while (curr != nullptr) {
			Pnode temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
	delete[] adjlist;

}

void Graph::addEdge(int s,int t, int w){
	if (s >= V || t >= V) {
		std::cout << "Invalid edge: " << s << " -> " << t << std::endl;
		return;
	}

	if (adjlist[s] == nullptr) {
		adjlist[s] = new Node(t, w);
	} else {
		Pnode curr = adjlist[s];
		while (curr->next != nullptr) {
			if (curr->index == t) {
				std::cout << "Edge already exists!" << std::endl;
				return;
			}
			curr = curr->next;
		}
		curr->next = new Node(t, w);
	}

	if (adjlist[t] == nullptr) {
		adjlist[t] = new Node(s, w);
	} else {
		Pnode curr = adjlist[t];
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = new Node(s, w);
	}
}

void Graph::removeEdge(int a, int b){

	for (int i = 0; !adjlist[b]; i++)
	{
		if(adjlist[b]->next->index == a){
			Pnode temp = adjlist[b]->next;
			adjlist[b]->next = temp->next;
			delete temp;
		}
	}

	for (int i = 0; adjlist[a] != nullptr; i++)
	{
		if(adjlist[a]->next->index == b){
			Pnode temp = adjlist[a]->next;
			adjlist[a]->next = temp->next;
			delete temp;
		}
	}
	
}

void Graph::print_graph(){
	for (int i = 0; i < V; i++)
	{
		Pnode curr = adjlist[i];
		while(curr != nullptr){
			std::cout << "[" << i << "]" << " --" << "("<< curr->edgeWeight << ")"<< "-- " << "[" << curr->index << "]"<< std::endl;
			curr = curr->next;
		}
	}
	
}