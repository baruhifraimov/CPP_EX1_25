#include <iostream>
#include "../include/Algorithms.hpp"
#include "../include/namespace/graph.hpp"
#include "../include/DataStructures.hpp"

#define INF 2147483647

using namespace graph;

enum colors{
	White,
	Gray,
	Black
};

Graph Algorithms::bfs(Graph g, int vertex){
	int numVer = g.getNumVertices();
	if (vertex >= numVer || vertex < 0){
		std::cout << "Vertex out of bounds!" << std::endl;
		return Graph(0);
	}

	
	 // 0-white(W) | 1-gray(G) | 2-black(B)
	 int* color = new int[numVer];
	 int* distance = new int[numVer];
	 int* pie = new int[numVer];

	// Initialize arrays
	for (int i = 0; i < numVer; i++)
	{
		color[i] = White;
		distance[i] = INF;
		pie[i] = -1;
	}

	color[vertex] = Gray;
	distance[vertex] = 0;

	Queue queue(numVer);
	queue.enqueue(vertex);

	while(!queue.isEmpty()){
		int u = queue.dequeue();
		
		// Check if dequeued value is INF (which indicates empty queue)
		if(u == INF) {
			std::cout << "Error: Queue returned INF value" << std::endl;
			break;
		}

		// Check if vertex index is valid
		if(u < 0 || u >= numVer) {
			std::cout << "Error: Invalid vertex index " << u << std::endl;
			continue;
		}

		Node* curr = g.getGraph()[u];

		while (curr != nullptr) {
			int v = curr->index;
			if (color[v] == White) {
				color[v] = Gray;
				distance[v] = distance[u] + 1;
				pie[v] = u;
				queue.enqueue(v);
			}
			curr = curr->next;
		}
		color[u] = Black;
	}

	// Generating G' for the new tree graph.
	Graph gTag(numVer);

	for (int i = 0; i < numVer; i++)
	{
		if(pie[i] != -1){
			gTag.addEdge(pie[i],i,distance[i]);
		}
	}
	

	delete[] color;
    delete[] distance;
    delete[] pie;

	std::cout << "BFS Tree built successfully"<< std::endl;

	return gTag;
}

int Algorithms::DFS_Visit(int u,int &time,int *color,int *pie,int *discovery,int *finish,Graph g){
	color[u] = Gray;
	time +=1;
	discovery[u] = time;
	Pnode curr = g.getGraph()[u];
	while(curr != nullptr){
		int v = curr->index;
		if(color[v] == White){
			pie[v] = u;
				DFS_Visit(v,time,color,pie,discovery,finish,g);
		}
		curr = curr->next;
	}
	color[u] = Black;
	finish[u] = ++time;
	return time;
}

Graph Algorithms::dfs(Graph g, int vertex){
	int time = -1;
	int numVer = g.getNumVertices();
	if (vertex >= numVer || vertex < 0){
		std::cout << "Vertex out of bounds!" << std::endl;
		return Graph(0);
	}

	
	 // 0-white(W) | 1-gray(G) | 2-black(B)
	 int* color = new int[numVer];
	 int* pie = new int[numVer];
	 int* discovery = new int[numVer];
	 int* finish = new int[numVer];
	 

	// Initialize arrays
	for (int i = 0; i < numVer; i++)
	{
		color[i] = White;
		pie[i] = -1;
	}

	// first visit of the root vertex
	time = DFS_Visit(vertex,time,color,pie,discovery,finish,g);
	
	// the rest of the vertecies
	for (int i = 0; i < numVer; i++)
	{
		if(color[i] == White){
			time = DFS_Visit(i,time,color,pie,discovery,finish,g);
		}
	}

	// Generating G' for the new tree graph.
	Graph gTag(numVer);

	for (int i = 0; i < numVer; i++)
	{	
		// if pie in i is -1 means that the root is not connected to the current vertex i
		if(pie[i] != -1){
			gTag.addEdge(pie[i],i,discovery[i]);
		}
		else{
		// instead of sending the 'discovery' as a edge 'weight', sending a indicator of pie 
		//that its -1 means that it got no edges between the root and the index, 
		//and by knowing which index, sending it as the weight.
			gTag.addEdge(pie[i],i,vertex);
		}
	}

	delete[] color;
    delete[] pie;
    delete[] discovery;
	delete[] finish;

	std::cout << "DFS Tree built successfully"<< std::endl;

	return gTag;
}















Graph Algorithms::dijkstra(Graph g, int vertex){
	int numVer = g.getNumVertices();
	
	if (vertex >= numVer || vertex < 0){
		std::cout << "Vertex out of bounds!" << std::endl;
		return Graph(0);
	}

	 int* distance = new int[numVer];
	 int* pie = new int[numVer];

	 	// Initialize arrays
	for (int i = 0; i < numVer; i++)
	{
		distance[i] = INF;
		pie[i] = -1;
	}

	Pqueue pqueue(numVer);

	distance[vertex] = 0;

	for (int i = 0; i < numVer; i++)
	{
		pqueue.insert(i,distance[i]);
	}

	while(!pqueue.isEmpty()){
		int u = pqueue.extractMin();
		if(u == -1){
			break;
		}
		Pnode p_u = g.getGraph()[u];
		while(p_u != nullptr){
			// the relax algorithm
			int v = p_u->index;
			int w = p_u->edgeWeight;
			if (w < 0){
				std::cout << "Negative edges are not allowed!" << std::endl;
				return Graph(0);
			}

			if (distance[v] > distance[u] + w){
				distance[v] = distance[u] + w;
				pie[v] = u;
				pqueue.decreaseKey(v, distance[v]);
			}

			p_u = p_u->next;
		}
	}



	// Generating G' for the new tree graph.
	Graph gTag(numVer);

	for (int i = 0; i < numVer; i++) {
		if (pie[i] != -1) {
            int weight = distance[i] - distance[pie[i]];
            gTag.addEdge(pie[i], i, weight);
        }
	}

	std::cout << "Dijkstra Tree built successfully"<< std::endl;

	delete[] distance;
    delete[] pie;

	return gTag;
}

// void Algorithms::relax(int u, Pnode &p_u, int *distance, int* pie, Pqueue &pqueue){
// 	int v = p_u->index;
// 	int w = p_u->edgeWeight;

// 	if (distance[v] > distance[u] + w){
// 		distance[v] = distance[u] + w;
// 		pie[v] = u;
// 		pqueue.decreaseKey(v, distance[v]);
// 	}
// }


















Graph Algorithms::prim(Graph g){
	return NULL;
}

Graph Algorithms::kruskal(Graph g){
	return NULL;
}