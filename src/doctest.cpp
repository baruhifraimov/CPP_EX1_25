//baruh.ifraimov@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/namespace/graph.hpp"
#include "../include/Graph.hpp"
#include "../include/Algorithms.hpp"
#include "../include/DataStructures.hpp"

/**
 * CHECK(expr)	chekcs if true
 * CHECK(expr)	Checks if expr is true (non-fatal)
 * REQUIRE(expr)	Like CHECK but stops on failure
 * CHECK_EQ(a, b)	Checks a == b
 * CHECK_NE(a, b)	Checks a != b
 * CHECK_THROWS(expr)	Checks if expr throws any exception
 * CHECK_THROWS_AS(expr, Type)	Checks if expr throws exception of type Type
 * CHECK_THROWS_WITH(expr, "msg")	Exception must contain "msg"
 * CHECK_NOTHROW(expr)	Checks that expr does not throw
 */


TEST_CASE("Testing Graph::addEdge and Graph::print_graph") {
    graph::Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    CHECK_NOTHROW(g.print_graph()); // just to ensure no exceptions thrown
}

TEST_CASE("Graph::addEdge adds symmetric edge") {
    graph::Graph g(2);
    g.addEdge(0, 1);

	CHECK_EQ(g.getGraph()[0]->index,1);
	CHECK_EQ(g.getGraph()[1]->index,0);

}

// Graph constructor and basic operations tests
TEST_CASE("Graph constructor handles invalid input") {
    CHECK_THROWS_AS(graph::Graph(-1), std::invalid_argument);
    CHECK_THROWS_AS(graph::Graph(0), std::invalid_argument);
    CHECK_NOTHROW(graph::Graph(5));
}

TEST_CASE("Graph::addEdge handles invalid vertices") {
    graph::Graph g(5);
    CHECK_THROWS_AS(g.addEdge(5, 2), std::out_of_range);
    CHECK_THROWS_AS(g.addEdge(2, 5), std::out_of_range);
    CHECK_THROWS_AS(g.addEdge(-2, 3), std::out_of_range);
    CHECK_NOTHROW(g.addEdge(2, 3));
}

TEST_CASE("Graph::addEdge prevents duplicate edges") {
    graph::Graph g(5);
    g.addEdge(1, 2);
    CHECK_THROWS_AS(g.addEdge(1, 2), std::overflow_error);
    CHECK_THROWS_AS(g.addEdge(2, 1), std::overflow_error); // Since edges are undirected
}

TEST_CASE("Graph::removeEdge handles invalid vertices") {
    graph::Graph g(5);
    g.addEdge(1, 2);
    CHECK_THROWS_AS(g.removeEdge(5, 2), std::out_of_range);
    CHECK_THROWS_AS(g.removeEdge(-1, 2), std::out_of_range);
    CHECK_NOTHROW(g.removeEdge(1, 2));
}

// Copy constructor test
TEST_CASE("Graph copy constructor creates deep copy") {
    graph::Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    
    graph::Graph g2 = g1; // Copy constructor
    // Modify g1, shouldn't affect g2
    g1.addEdge(2, 3);

	std::cout << g2.getNumEdges() << std::endl;
	std::cout<< g1.getNumEdges() << std::endl;

	CHECK_NE(g2.getNumEdges(),g1.getNumEdges());
    
}

// Data structures tests
TEST_CASE("Queue handles exceptions properly") {
    Queue q(3);
    CHECK_NOTHROW(q.enqueue(1));
    CHECK_NOTHROW(q.enqueue(2));
    CHECK_NOTHROW(q.enqueue(3));
    CHECK_THROWS_AS(q.enqueue(4), std::overflow_error);
    
    CHECK_NOTHROW(q.dequeue());
    CHECK_NOTHROW(q.dequeue());
    CHECK_NOTHROW(q.dequeue());
    CHECK_THROWS_AS(q.dequeue(), std::underflow_error);
}

TEST_CASE("Priority Queue handles exceptions properly") {
    Pqueue pq(3);
    CHECK_NOTHROW(pq.insert(0, 5));
    CHECK_NOTHROW(pq.insert(1, 2));
    CHECK_NOTHROW(pq.insert(2, 7));
    CHECK_THROWS_AS(pq.insert(3, 1), std::overflow_error);
    
    CHECK_THROWS_AS(pq.decreaseKey(5, 1), std::invalid_argument); // Non-existent vertex
}

TEST_CASE("Stack handles exceptions properly") {
    Stack s(3);
    CHECK_NOTHROW(s.push(1));
    CHECK_NOTHROW(s.push(2));
    CHECK_NOTHROW(s.push(3));
    CHECK_THROWS_AS(s.push(4), std::overflow_error);
    
    CHECK_NOTHROW(s.pop());
    CHECK_NOTHROW(s.pop());
    CHECK_NOTHROW(s.pop());
    CHECK_THROWS_AS(s.pop(), std::underflow_error);
    CHECK_THROWS_AS(s.peek(), std::underflow_error);
}

// Algorithm tests
TEST_CASE("BFS handles invalid start vertex") {
    graph::Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    CHECK_THROWS_AS(graph::Algorithms::bfs(g, 5), std::out_of_range);
    CHECK_THROWS_AS(graph::Algorithms::bfs(g, -1), std::out_of_range);
    CHECK_NOTHROW(graph::Algorithms::bfs(g, 0));
}

TEST_CASE("DFS handles invalid start vertex") {
    graph::Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    
    CHECK_THROWS_AS(graph::Algorithms::dfs(g, 5), std::out_of_range);
    CHECK_THROWS_AS(graph::Algorithms::dfs(g, -1), std::out_of_range);
    CHECK_NOTHROW(graph::Algorithms::dfs(g, 0));
}

TEST_CASE("Dijkstra rejects negative edges") {
    graph::Graph g(3);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, -1); // Negative edge
    
    CHECK_THROWS_AS(graph::Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Checks for empty graph creation is invalid") {
    CHECK_THROWS_AS(graph::Graph emptyGraph(0), std::invalid_argument);
}

TEST_CASE("MST algorithms handle graphs with no edges") {
    graph::Graph disconnectedGraph(5); // No edges added
    
    CHECK_THROWS_AS(graph::Algorithms::kruskal(disconnectedGraph), std::logic_error);
}

TEST_CASE("UnionFind handles invalid indices") {
    UnionFind uf(5);
    
    CHECK_THROWS_AS(uf.find(-1), std::out_of_range);
    CHECK_THROWS_AS(uf.find(5), std::out_of_range);
    CHECK_THROWS_AS(uf.unite(1, 6), std::out_of_range);
    CHECK_NOTHROW(uf.unite(1, 2));
}

TEST_CASE("Check All Functions, STRESS TEST"){
	graph::Graph g(7);

	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 3, 7);
	g.addEdge(1, 4, 1);
	g.addEdge(2, 5, 3);
	g.addEdge(3, 5, 1);
	g.addEdge(4, 6, 5);
	g.addEdge(5, 6, 2);

	CHECK_NOTHROW(graph::Graph t = graph::Algorithms::dijkstra(g,1));

	CHECK_NOTHROW(graph::Graph a = graph::Algorithms::prim(g));

	CHECK_NOTHROW(graph::Graph b = graph::Algorithms::kruskal(g));
	
	CHECK_NOTHROW(graph::Graph y = graph::Algorithms::bfs(g,1));
	
	CHECK_NOTHROW(graph::Graph z = graph::Algorithms::dfs(g,1));
	
}