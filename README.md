# Graph Data Structure & Algorithms Implementation

## Project Overview

This project provides a comprehensive implementation of a graph data structure using adjacency lists, along with several common graph algorithms. The project doesn't use the C++ Standard Template Library (STL) and instead implements the necessary data structures from scratch.

## Data Structures

### Graph Class

The core data structure is an undirected graph implemented using adjacency lists:

- **Vertices**: Each vertex has an index (0 to V-1) and a linked list of adjacent vertices.
- **Edges**: Undirected weighted edges between vertices.
- **Initialization**: Created with a fixed number of vertices that cannot be changed.
- **Memory Management**: Uses deep copy constructor and proper memory cleanup in destructor.

#### Key Methods:
- `addEdge(s, t, w=1)`: Adds an undirected edge with optional weight between vertices `s` and `t`.
- `removeEdge(a, b)`: Removes an edge between vertices `a` and `b`.
- `print_graph()`: Displays the graph's structure.
- `getNumVertices()`: Returns the number of vertices.
- `getNumEdges()`: Returns the number of edges.

#### Error Handling:
- Throws `std::invalid_argument` when constructing with non-positive vertex count.
- Throws `std::out_of_range` when accessing vertices outside valid range.
- Throws `std::overflow_error` when attempting to add duplicate edges.
- Throws `std::invalid_argument` when attempting to remove non-existent edges.

### Helper Data Structures

#### Queue
- Circular array-based implementation for BFS.
- Operations: `enqueue`, `dequeue`, `isEmpty`.
- Exception handling for queue overflow and underflow.

#### Priority Queue
- Array-based implementation for Dijkstra's and Prim's algorithms.
- Operations: `insert`, `extractMin`, `decreaseKey`, `contains`, `isEmpty`.
- Exception handling for capacity limits and invalid operations.

#### Stack
- Array-based implementation for DFS.
- Operations: `push`, `pop`, `peek`, `isEmpty`.
- Exception handling for overflow and underflow conditions.

#### UnionFind
- Disjoint-set data structure for Kruskal's algorithm.
- Operations: `find`, `unite`.
- Exception handling for invalid indices.

## Algorithms

### Breadth-First Search (BFS)
- **Input**: A graph and a source vertex.
- **Output**: A tree rooted at the source vertex.
- **Process**: Uses a queue to discover vertices in order of their distance from the source.
- **Exceptions**: Throws `std::out_of_range` if source vertex is invalid.

### Depth-First Search (DFS)
- **Input**: A graph and a starting vertex.
- **Output**: A forest containing tree edges from the DFS traversal.
- **Process**: Uses a stack-based approach to explore as far as possible along branches before backtracking.
- **Exceptions**: Throws `std::out_of_range` if starting vertex is invalid.

### Dijkstra's Algorithm
- **Input**: A graph and a source vertex.
- **Output**: A tree of shortest paths from the source to all reachable vertices.
- **Process**: Uses a priority queue to greedily select vertices with minimum distance.
- **Exceptions**: 
  - Throws `std::out_of_range` if source vertex is invalid.
  - Throws `std::invalid_argument` if graph contains negative edges.

### Prim's Algorithm (MST)
- **Input**: A graph.
- **Output**: A minimum spanning tree.
- **Process**: Grows the MST by adding the minimum-weight edge that connects a vertex in the tree to a vertex outside.
- **Exceptions**:
  - Throws `std::invalid_argument` for empty graphs.
  - Throws `std::logic_error` if graph has no valid vertices.

### Kruskal's Algorithm (MST)
- **Input**: A graph.
- **Output**: A minimum spanning tree.
- **Process**: Sorts all edges by weight and adds them to the MST if they don't create a cycle.
- **Exceptions**:
  - Throws `std::invalid_argument` for empty graphs.
  - Throws `std::logic_error` for graphs with no edges.

## Testing

The project includes comprehensive test cases to verify the correctness of all implementations:

- **Basic Graph Operations**: Constructor, edge addition/removal, copy constructor.
- **Data Structure Tests**: Queue, Priority Queue, Stack, UnionFind.
- **Algorithm Tests**: Validation of BFS, DFS, Dijkstra's, Prim's, and Kruskal's algorithms.
- **Error Handling Tests**: Verification that appropriate exceptions are thrown for invalid inputs.
- **Comprehensive Stress Test**: Tests all algorithms on a complex graph.

## Build and Run

The project includes a Makefile with the following targets:

- `make Main`: Builds and runs the demonstration file.
- `make test`: Builds and runs the unit tests.
- `make valgrind`: Runs memory leak tests using Valgrind.
- `make clean`: Removes all build artifacts.

### Running Tests

```bash
# Run all tests
make test

# Check for memory leaks
make valgrind
```

## Error Handling

The implementation employs robust error handling using exceptions:

- `std::invalid_argument`: For invalid inputs like negative vertex counts.
- `std::out_of_range`: For accessing vertices beyond the valid range.
- `std::overflow_error`: For operations that exceed capacity limits.
- `std::underflow_error`: For operations on empty data structures.
- `std::logic_error`: For operations that are logically impossible (like MST on a disconnected graph).

## Project Structure

- `include/`: Header files defining class interfaces.
- `src/`: Implementation files.
- `doctest.cpp`: Unit tests using the doctest framework.
- `Makefile`: Build automation.

## Notes

This project was developed as an assignment focusing on C++ fundamental concepts including memory management, classes, constructors/destructors, objects, namespaces, parameter passing, and returning objects.

