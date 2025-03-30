#ifndef DATASTRUCTURES_HPP
#define DATASTRUCTURES_HPP
#include "../include/Graph.hpp"


/**************************************************************
 *                           QUEUE                            *
 **************************************************************/
 class Queue{
		int first;
		int last;
		int capacity;
		int size;
		int* queue;

	public:
		Queue(int capacity) : capacity(capacity),first(0),last(0),size(0){
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
		Pqueue(int capacity):capacity(capacity){
			this->size = 0;
			this->pqueue = new Vertex[capacity];
		}
		~Pqueue(){
			delete[] pqueue;
		}
		
		/**
		 * @brief 
		 * 
		 * @param vertex 
		 * @param priority 
		 */
		void insert(int vertex, int priority);

		/**
		 * @brief 
		 * 
		 * @return int 
		 */
		int extractMin();

		/**
		 * @brief 
		 * 
		 * @return true 
		 * @return false 
		 */
		bool isEmpty();

		/**
		 * @brief 
		 * 
		 * @param vertex 
		 * @return true 
		 * @return false 
		 */
		bool contains(int vertex);
};
/**************************************************************
 *                           STACK                            *
 **************************************************************/
class Stack{
		int* array;
		int top;
		int capacity;

	public:
		Stack(int capacity) : capacity(capacity), top(-1){
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

	public:
		UnionFind(int size){
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