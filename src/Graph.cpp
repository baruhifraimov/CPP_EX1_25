#include <iostream>
#include "../include/Graph.hpp"
#include "../include/namespace/graph.hpp"
#include "../include/DataStructures.hpp"



using namespace graph;

Graph::Graph(int V) : V(V){
	adjlist = new Pnode[V];
	for (int i = 0; i < V; i++)
	{
		adjlist[i] = nullptr;
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
	if (s >= this->V || s < 0 || t >= this->V || t < 0 ) {
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

void Graph::removeEdge(int a, int b) {
	if (a < 0 || a >= V || b < 0 || b >= V) {
        std::cout << "Invalid edge: " << a << " -> " << b << std::endl;
        return;
    }

    // Remove edge from b's adjacency list
    Pnode curr = adjlist[b];
    Pnode prev = nullptr;
    while (curr != nullptr) {
        if (curr->index == a) {
            if (prev == nullptr) { // Edge is the first node
                adjlist[b] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // Remove edge from a's adjacency list
    curr = adjlist[a];
    prev = nullptr;
    while (curr != nullptr) {
        if (curr->index == b) {
            if (prev == nullptr) { // Edge is the first node
                adjlist[a] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
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