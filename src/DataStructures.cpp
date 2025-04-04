//baruh.ifraimov@gmail.com
#include <iostream>
#include <exception>
#include <stdexcept>
#include "../include/DataStructures.hpp"

#define INF 2147483647

/**************************************************************
 *                           QUEUE                            *
 **************************************************************/
bool Queue::enqueue(int vertex){
	if(size == capacity){
		throw std::overflow_error("Queue capacity exceeded");
	}
	this->queue[this->last] = vertex;
	this->last = (this->last + 1) % this->capacity;
	this->size++;
	return true;
}

int Queue::dequeue(){
	if(isEmpty()){
		throw std::underflow_error("Cannot extract from empty priority");
	}
	int x = this->queue[this->first];
	this->first = (this->first + 1) % this->capacity;
	this->size--;
	return x;
}

bool Queue::isEmpty(){
	return size == 0;
}
/**************************************************************
 *                           PQUEUE                           *
 **************************************************************/
void Pqueue::insert(int vertex, int priority){
	if(this->size == this->capacity){
        throw std::overflow_error("Priority queue capacity exceeded");
		return;
	}
	Vertex x;
	x.vertex = vertex;
	x.distance = priority;
	this->pqueue[this->size++] = x;
}

int Pqueue::extractMin() {
    int minIndex = -1;
    int minDistance = INF;

    for (int i = 0; i < this->capacity; i++) {
        if (pqueue[i].vertex != -1 && pqueue[i].distance < minDistance) {
            minDistance = pqueue[i].distance;
            minIndex = i;
        }
    }

    if (minIndex == -1) {
        throw std::underflow_error("Cannot extract from empty priority queue");
    }

    int minVertex = pqueue[minIndex].vertex;
    pqueue[minIndex].vertex = -1;
    pqueue[minIndex].distance = INF;
    this->size--;
    return minVertex;
}

bool Pqueue::isEmpty(){
	return this->size == 0;
}

bool Pqueue::contains(int vertex){
	for (int i = 0; i < this->size; i++)
	{
		if(this->pqueue[i].vertex == vertex){
			return true;
		}
	}
	return false;
}

void Pqueue::decreaseKey(int vertex, int newPriority){
    for (int i = 0; i < capacity; i++) {
        if (pqueue[i].vertex == vertex) {
            pqueue[i].distance = newPriority;
            return;
        }
    }
    throw std::invalid_argument("Vertex " + std::to_string(vertex) + " not found in queue");
}

int Pqueue::getSize(){
	return this->size;
}

/**************************************************************
 *                           STACK                            *
 **************************************************************/
void Stack::push(int value){
	if (this->top == this->capacity-1){
        throw std::overflow_error("Stack capacity exceeded");
		return;
	}
	this->array[++this->top] = value;
}
int Stack::pop(){
	if(this->isEmpty()){
        throw std::underflow_error("Cannot pop from empty stack");
	}
	int x = this->array[this->top];
	this->top--;
	return x;
}
int Stack::peek(){
	if (this->isEmpty()){
        throw std::underflow_error("Cannot peek at empty stack");
	}
	return this->array[this->top];
}
bool Stack::isEmpty(){
	return this->top < 0;
}
 /**************************************************************
 *                           UNIONFIND                         *
 **************************************************************/

 int UnionFind::find(int i){
	if (i < 0 || i >= this->size) {
        throw std::out_of_range("Index " + std::to_string(i) + " out of range");
    }

	if (this->parent[i] == i){
		return i;
	}
	return find(parent[i]);
 }

void UnionFind::unite(int i, int j){
	if (i < 0 || i >= size || j < 0 || j >= this->size) {
        throw std::out_of_range("Index out of range");
    }
	this->parent[find(j)] = find(i);
}