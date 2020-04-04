#include "heap.h"
using namespace std;

// theta(1)
heap::heap(int capacity)
{
	this->capcity = capacity;
	this->length = 0;
	this->elems = new TElem[capacity];
	this->sum = 0;
}


heap::~heap()
{
	delete elems;
}

// returns the sum of the elements from the heap
//theta(1)
int heap::getSum()
{
	return this->sum;
}

/*Adds elements until the heap reaches its capacity.
After that we add ony the highest k elements( k  is capacity) replacing the root (min element from the heap)
and then bubble down to keep the heap a minHeap.
O(log n)
*/
void heap::add(TElem e)
{
	if (this->length == this->capcity)
	{
		if (e > getRoot())
		{
			this->sum -= this->elems[0];
			this->elems[0] = e;
			this->sum += e;
			this->bubbleDown(0);
		}
	}
	else
	{
		this->elems[this->length] = e;
		this->length++;
		this->sum += e;
		this->bubbleUp(this->length-1);
	}
}

void heap::bubbleUp(int p) 
{
	if(p>0 && this->elems[p] >  this->elems[this->getParentPosition(p)])
	{
		auto aux = this->elems[p];
		this->elems[p] = this->elems[this->getParentPosition(p)];
		this->elems[this->getParentPosition(p)] = aux;
		this->bubbleUp(this->getParentPosition(p));
	}
}

/*
O(log n)
Turns the heap into a minHeap by comparing the parent p wuth its leaves.
*/
void heap::bubbleDown(int p)
{
		int i = p;
		int minC = -1;
		if (this->getLeftChild(i) < this->length) // verify if the parent has a left child and assume it is minimum child
			minC = this->getLeftChild(i);
		if (this->getRightChild(i) < this->length && this->elems[getLeftChild(i)] > this->elems[getRightChild(i)])
			minC = this->getRightChild(i); // the right is the smaller children
		if (minC != -1 && this->elems[minC] < this->elems[i])
		{
			auto aux = this->elems[minC];
			this->elems[minC] = this->elems[i];
			this->elems[i] = aux;
			this->bubbleDown(minC);
		}
}


//returns the root of the heap
//theta(1)
int heap::getRoot()
{
	return this->elems[0];
}

//theta(1)
//returns the parent's position  of the element on position i
int heap::getParentPosition(int i)
{
	return (i -1)/ 2;
}

//theta(1)
//returns the position of the left child of node i
int heap::getLeftChild(int i)
{
	return 2*i+1;
}

//theta(1)
//returns the position of the right child of the node i
int heap::getRightChild(int i)
{
	return 2*i+2;
}
