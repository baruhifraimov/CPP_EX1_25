#include "../include/DataStructures.hpp"
#include <iostream>

/**************************************************************
 *                           QUEUE                            *
 **************************************************************/
bool Queue::enqueue(int vertex){
	if(size == capacity){
		return false;
	}
	this->queue[this->last] = vertex;
	this->last = (this->last + 1) % this->capacity;
	this->size++;
	return true;
}

int Queue::dequeue(){
	if(isEmpty()){
		return 2147483647;
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
		std::cout<< "Capacity exceeded" <<std::endl;
		return;
	}
	Vertex x;
	x.vertex = vertex;
	x.distance = priority;
	this->pqueue[this->capacity++] = x;
	this->size++;
}

int Pqueue::extractMin(){
	Vertex min = this->pqueue[0];
	for (int i = 0; i < this->capacity; i++)
	{
		if(min.distance > this->pqueue[i].distance){
			min = this->pqueue[i];
		}
	}
	
	return min.vertex;
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
/**************************************************************
 *                           STACK                            *
 **************************************************************/
void Stack::push(int value){
	if (this->top == this->capacity-1){
		std::cout << "The stack is full" << std::endl;
		return;
	}
	this->array[++this->top] = value;
}
int Stack::pop(){
	if(this->isEmpty()){
		return -2147483648;
	}
	int x = this->array[this->top];
	this->top--;
	return x;
}
int Stack::peek(){
	if (this->isEmpty()){
		return -2147483648;
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
	if (this->parent[i] == i){
		return i;
	}
	return find(parent[i]);
 }

void UnionFind::unite(int i, int j){
	this->parent[find(j)] = find(i);
}