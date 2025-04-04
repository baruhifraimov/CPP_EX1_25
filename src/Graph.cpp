//baruh.ifraimov@gmail.com
#include <iostream>
#include <exception>
#include <stdexcept>
#include "../include/Graph.hpp"
#include "../include/DataStructures.hpp"

#define INF 2147483647



using namespace graph;
Graph::Graph(int V) : V(V){

	if (V <= 0) {
        throw std::invalid_argument("Number of vertices must be positive");
    }

	adjlist = new Pnode[V];
	for (int i = 0; i < V; i++)
	{
		adjlist[i] = nullptr;
	}

	this->E = 0;
}

// Deep copy
Graph::Graph(const Graph& other) : V(other.V) {
    // Deep copy the adjacency list
    adjlist = new Pnode[V];
    for (int i = 0; i < V; i++) {
        adjlist[i] = nullptr;
        
        // Copy the linked list
        Pnode curr = other.adjlist[i];
        Pnode* tail = &adjlist[i];
        
        while (curr != nullptr) {
            *tail = new Node(curr->index, curr->edgeWeight);
            tail = &((*tail)->next);
            curr = curr->next;
        }
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
	if ( s >= this->V || s < 0 || t >= this->V || t < 0 ) {
		if(s == -1 || t == -1){

		}
		else{
		throw std::out_of_range("Invalid edge: " + std::to_string(s) + " --> " + std::to_string(t));
		return;
		}
	}
	if(s == -1){
		if (adjlist[t] == nullptr) {
			adjlist[t] = new Node(w, INF);
		} else {
			Pnode curr = adjlist[t];
			Pnode prev = nullptr;
			
			while (curr != nullptr) {
				prev = curr;
				curr = curr->next;
			}
			prev->next = new Node(w, INF);
		}
		return;
	}
	else if (t == -1){
		if (adjlist[s] == nullptr) {
			adjlist[s] = new Node(w, INF);
		} else {
			Pnode curr = adjlist[s];
			Pnode prev = nullptr;
			
			while (curr != nullptr) {
				prev = curr;
				curr = curr->next;
			}
			prev->next = new Node(w, INF);
		}
		return;
	}

	if (adjlist[s] == nullptr) {
		adjlist[s] = new Node(t, w);
		E++;
	} else {
		Pnode curr = adjlist[s];
		Pnode prev = nullptr;
		
		// Check for duplicates
		while (curr != nullptr) {
			if (curr->index == t) {
				throw std::overflow_error("Edge already exists!");
			}
			prev = curr;
			curr = curr->next;
		}
		
		// Add the new node at the end of the list
		prev->next = new Node(t, w);
		E++;
	}

	// Do the same for the other side of the edge
	if (adjlist[t] == nullptr) {
		adjlist[t] = new Node(s, w);
		E++;
	} else {
		Pnode curr = adjlist[t];
		Pnode prev = nullptr;
		
		while (curr != nullptr) {
			if (curr->index == s) {
				throw std::overflow_error("Edge already exists!");
			}
			prev = curr;
			curr = curr->next;
		}
		
		prev->next = new Node(s, w);
		E++;
	}
}

void Graph::removeEdge(int a, int b) {
	if ((a < 0 || a >= V || b < 0 || b >= V)) {
		throw std::out_of_range("Invalid edge: " + std::to_string(a) + " --> " + std::to_string(b));
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
	E-=2;
}

void Graph::print_graph(){
	for (int i = 0; i < V; i++)
	{
		Pnode curr = adjlist[i];
		while(curr != nullptr){
			if(curr->edgeWeight == INF){
			std::cout << "[" << i << "]" << " --" << "("<< "infinite" << ")"<< "-- " << "[" << curr->index << "]"<< std::endl;
			}
			else{
			std::cout << "[" << i << "]" << " --" << "("<< curr->edgeWeight << ")"<< "-- " << "[" << curr->index << "]"<< std::endl;
			}
			curr = curr->next;
		}
	}
}

Pnode* Graph::getGraph(){
	return this->adjlist;
}

int Graph::getNumVertices(){
	return this->V;
}

int Graph::getNumEdges(){
	return this->E/2;
}