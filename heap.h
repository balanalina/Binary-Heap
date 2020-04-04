#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
typedef int TElem;
class heap
{
private:
	int capcity;
	int length;
	TElem* elems;
	int sum;
public:
	heap(int capacity = 10);
	~heap();
	void add(TElem e);
	int getRoot();
	int getParentPosition(int i);
	int getLeftChild(int i);
	int getRightChild(int i);
	int getSum();
	void bubbleDown(int p);
	void bubbleUp(int p);
};

