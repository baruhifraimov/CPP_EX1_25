//baruh.ifraimov@gmail.com
#ifndef DATASTRUCTURES_HPP
#define DATASTRUCTURES_HPP

#include "../include/Graph.hpp"


/**************************************************************
 *                           QUEUE                            *
 **************************************************************/
 class Queue{
		int first;
		int last;
		int size;
		int capacity;
		int* queue;

	public:
	/**
	 * @brief Construct a new Queue object
	 * 
	 * @param capacity The capacity of the Queue 
	 */
		Queue(int capacity) : first(0),last(0),size(0),capacity(capacity){
			this->queue = new int[capacity];	
		}

		~Queue(){
			delete[] queue;
		}

		/**
		 * @brief Adds an element to the end of the queue.
		 * 
		 * @param vertex The element to be added to the queue.
		 * @return true if the element was successfully added.
		 * @return false if the queue is full and the element could not be added.
		 */
		bool enqueue(int vertex);

		/**
		 * @brief Removes and returns the front element of the queue.
		 * 
		 * If the queue is empty, it returns a max int value (2147483647).
		 * 
		 * @return int The front element of the queue, or 2147483647 if the queue is empty.
		 */
		int dequeue();

		/**
		 * @brief Checks if the queue is empty.
		 * 
		 * @return true if the queue has no elements.
		 * @return false if the queue contains one or more elements.
		 */
		bool isEmpty();

};

/**************************************************************
 *                           PQUEUE                           *
 **************************************************************/

 /**
  * @brief a vertex definiton that includes the index of it vertex for identification
  * and a distance that will act as the weight/priority
  * 
  */
typedef struct _Vertex {
    int vertex;
    int distance;
	}Vertex;

class Pqueue{
	private:
		Vertex *pqueue;
		int size;
		int capacity;

	public:
	/**
	 * @brief Construct a new Pqueue object
	 * 
	 * @param capacity The capacity of the Priority Queue
	 */
		Pqueue(int capacity):capacity(capacity){
			this->size = 0;
			this->pqueue = new Vertex[capacity];
			for (int i = 0; i < capacity; i++)
			{
				pqueue[i].vertex = -1;
			}
			
		}

		~Pqueue(){
			delete[] pqueue;
		}
		
		/**
		 * @brief Insert a vertices and his priority.
		 * 
		 * @param vertex a vertex that exists in the graph
		 * @param priority the value that you want it to be prioritized
		 */
		void insert(int vertex, int priority);

		/**
		 * @brief Extracting the minimum priority by value, runing all over the queue linearly
		 * 
		 * @return int retunrs the minimum vertex index
		 */
		int extractMin();

		/**
		 * @brief Checks if the queue is empty by comparing capacity to size
		 * 
		 * @return true if empty
		 * @return false if not empty
		 */
		bool isEmpty();

		/**
		 * @brief Checks if a certain vertex contains in the queue
		 * 
		 * @param vertex The vertex that you want to check
		 * @return true If in
		 * @return false If not in
		 */
		bool contains(int vertex);

		/**
		 * @brief Decreasing the priority value of a given vertex
		 * 
		 * @param vertex The vertex index you want to decrease his value
		 * @param newPriority New value
		 */
		void decreaseKey(int vertex, int newPriority);

		int getSize();
};
/**************************************************************
 *                           STACK                            *
 **************************************************************/
class Stack{
		int* array;
		int top;
		int capacity;

	public:
	/**
	 * @brief Construct a new Stack object
	 * 
	 * @param capacity The capacity of the Stack
	 */
		Stack(int capacity) : top(-1), capacity(capacity){
			this->array = new int[capacity];
		}
		~Stack(){
			delete[] array;
		}

		/**
		 * @brief Adding an element regarding top index
		 * 
		 * @param value The integer element that will be added to the stack
		 */
		void push(int value);

		/**
		 * @brief Removing the top arguemnt
		 * 
		 * @return int returning the top argument in the stack
		 */
		int pop();

		/**
		 * @brief Returning the top element of the stack
		 * 
		 * @return int the top element of the stack
		 */
		int peek();

		/**
		 * @brief checks if the stack is empty, if top is < 0
		 * 
		 * @return true if empty
		 * @return false if not empty
		 */
		bool isEmpty();
};
/**************************************************************
 *                           UNIONFIND                        *
 **************************************************************/
class UnionFind{
		int* parent;
		int size;

	public:
	/**
	 * @brief Construct a new Union Find object
	 * 
	 * @param size The size of the UnionFind, regulary will be |V|
	 */
		UnionFind(int size){
			this->size = size;
			this->parent = new int[size];
			for (int i = 0; i < size; i++)
			{
				// every vertex is a single union that own itself
				this->parent[i] = i;
			}
			
		}

		~UnionFind(){
			delete[] parent;
		}

		/**
		* @brief Searched the root/head of the vertex (recursively)
		* 
		* @param i the vertex that we want to find its root
		* @return int returns the root/head of the group
		*/
		int find(int i);

		/**
		* @brief Joins the groups/trees into one. searching the root of i 
		* and the root of j and unite them to a one parent. 
		* in this matter the root of j will be the root of the group/tree of i
		* 
		* @param i group that contains i
		* @param j group that contains j
		*/
		void unite(int i, int j);
};

#endif