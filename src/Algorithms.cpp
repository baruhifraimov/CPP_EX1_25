//baruh.ifraimov@gmail.com
#include <iostream>
#include <exception>
#include <stdexcept>
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
		throw std::out_of_range("Vertex " + std::to_string(vertex) + " is out of bounds");
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
			throw std::runtime_error("Queue returned INF value");
		}

		// Check if vertex index is valid
		if(u < 0 || u >= numVer) {
			throw std::out_of_range("Invalid vertex index: " + std::to_string(u));
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
		throw std::out_of_range("Vertex " + std::to_string(vertex) + " is out of bounds");
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
		throw std::out_of_range("Vertex " + std::to_string(vertex) + " is out of bounds");
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
		int u;
		try{
		u = pqueue.extractMin();
		}
		catch(const std::underflow_error& e){
		break;
	}
		Pnode p_u = g.getGraph()[u];
		while(p_u != nullptr){
			// the relax algorithm
			int v = p_u->index;
			int w = p_u->edgeWeight;
			if (w < 0){
				throw std::invalid_argument("Negative edges are not allowed");
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

Graph Algorithms::prim(Graph g) {
    int numVer = g.getNumVertices();
    
    if (numVer == 0) {
        throw std::invalid_argument("Cannot create MST for empty graph");
    }
    
    // Arrays to store MST data
    int* key = new int[numVer];  // Holds minimum edge weight to each vertex
    int* pie = new int[numVer];  // Holds parent of each vertex in MST
    bool* inMST = new bool[numVer]; // Tracks vertices already in MST
    
    // Initialize arrays
    for (int i = 0; i < numVer; i++) {
        key[i] = INF;
        pie[i] = -1;
        inMST[i] = false;
    }
    
    Pnode* g_adjList = g.getGraph();
    
    // Find first vertex with edges to start
    int startVertex = -1;
    for (int i = 0; i < numVer; i++) {
        if (g_adjList[i] != nullptr) {
            startVertex = i;
            break;
        }
    }
    
    if (startVertex == -1) {
        throw std::logic_error("Graph has no defined vertices");
    }
    
    // Start from the selected vertex
    key[startVertex] = 0;
    
    // Create priority queue
    Pqueue pq(numVer);
    
    // Add all vertices to the priority queue
    for (int i = 0; i < numVer; i++) {
        pq.insert(i, key[i]); // All vertices start with INF except startVertex
    }
    
    while (!pq.isEmpty()) {
        // Extract the vertex with minimum key value
        int u;
        try {
            u = pq.extractMin();
        } catch (const std::underflow_error& e) {
            break;
        }
        
        inMST[u] = true;
        
        // Process all adjacent vertices of u
        Pnode curr = g_adjList[u];
        while (curr != nullptr) {
            int v = curr->index;
            int weight = curr->edgeWeight;
            
            // Update key if v is not in MST and weight is smaller than current key
            if (!inMST[v] && weight < key[v]) {
                pie[v] = u;
                key[v] = weight;
                pq.decreaseKey(v, weight);
            }
            
            curr = curr->next;
        }
    }
    
    // Construct MST
    Graph mst(numVer);
    for (int i = 0; i < numVer; i++) {
        if (pie[i] != -1) {
            mst.addEdge(pie[i], i, key[i]);
        }
    }
    
	std::cout<<"Prim MST built successfully" << std::endl;

    delete[] key;
    delete[] pie;
    delete[] inMST;
    
    return mst;
}

Graph Algorithms::kruskal(Graph g) {
    // Edge structure to store source, destination, and weight
    struct Edge {
        int src;
        int dest;
        int weight;
    };
    
    int numVer = g.getNumVertices();
    if (numVer == 0) {
		throw std::invalid_argument("Cannot create MST for empty graph");
	}
    
    // count the total edges
    int edgeCount = 0;
    Pnode* adjList = g.getGraph();
    for (int i = 0; i < numVer; i++) {
        Pnode curr = adjList[i];
        while (curr != nullptr) {
            // only count edges once (when src < dest to avoid duplicates)
            if (i < curr->index) {
                edgeCount++;
            }
            curr = curr->next;
        }
    }
    
    if (edgeCount == 0) {
		throw std::logic_error("Cannot create MST for graph with no edges");
	}
    
    // create an array of all edges
    Edge* edges = new Edge[edgeCount];
    int edgeIndex = 0;
    for (int i = 0; i < numVer; i++) {
        Pnode curr = adjList[i];
        while (curr != nullptr) {
            // Only add edges once
            if (i < curr->index) {
                edges[edgeIndex].src = i;
                edges[edgeIndex].dest = curr->index;
                edges[edgeIndex].weight = curr->edgeWeight;
                edgeIndex++;
            }
            curr = curr->next;
        }
    }
    
    // sort edges by weight
    for (int i = 0; i < edgeCount - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < edgeCount; j++) {
            if (edges[j].weight < edges[minIdx].weight) {
                minIdx = j;
            }
        }

        Edge temp = edges[i];
        edges[i] = edges[minIdx];
        edges[minIdx] = temp;
    }
    
    // initialize UnionFind
    UnionFind uf(numVer);
    
    // construct MST
    Graph mst(numVer);
    int edgesAdded = 0;
    
    for (int i = 0; i < edgeCount && edgesAdded < numVer - 1; i++) {
        int srcRoot = uf.find(edges[i].src);
        int destRoot = uf.find(edges[i].dest);
        
        // if including this edge doesn't create a cycle
        if (srcRoot != destRoot) {
            mst.addEdge(edges[i].src, edges[i].dest, edges[i].weight);
            uf.unite(srcRoot, destRoot); // join the two components
            edgesAdded++;
        }
    }
    
    // Free memory
    delete[] edges;
    
    std::cout << "Kruskal's MST built successfully" << std::endl;
    return mst;
}