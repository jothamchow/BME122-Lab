#include "PriorityQueue.hpp"
#include<iostream>
using namespace std;
typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
	heap_ = new DataType[capacity + 1];
	capacity_ = capacity;
	size_ = 0;
}
PriorityQueue::~PriorityQueue()
{
	delete heap_;
	heap_ = NULL;
}

bool PriorityQueue::enqueue(DataType val)
{
	if(full())
		return false;
	
	size_++;
	heap_[size_] = val;
	int i = size_;
	while(heap_[i/2] < heap_[i] && i != 1)
	{
		DataType temp = heap_[i/2];
		heap_[i/2] = heap_[i];
		heap_[i] = temp;
		i = i/2;
	}
	return true;
}

bool PriorityQueue::dequeue()
{
	
	
	cout << "Before: ";
	print();
	
	if(empty())
		return false;
		
	heap_[size_] = heap_[1];
	size_--;
	
	int i = 1;
	int temp;
	int a;
	int b;
	while(2*i < size_)
	{
		if(heap_[2*i] < heap_[2*i+1])
		{
			//swap with right child
			a = heap_[i];
			b = heap_[2*i+1];
			
			heap_[i] = b;
			heap_[2*i+1] = a;
			i = 2*i + 1;
		}
		else
		{
			//swap with left child
			a = heap_[i];
			b = heap_[2*i];
			
			heap_[i] = b;
			heap_[2*i] = a;
			i = 2*i;
		}
	}
	cout << "After: ";
	print();
	return true;
}

DataType PriorityQueue::max() const
{
	//cout << heap_[1];
	return heap_[1];
}

bool PriorityQueue::empty() const
{
	if(size_ == 0)
		return true;
	return false;
}

bool PriorityQueue::full() const
{
	if(size_ == capacity_)
		return true;
	return false;
}

unsigned int PriorityQueue::size() const
{
	return size_;
}

void PriorityQueue::print() const
{
	cout << "[ ";
	for(int i = 1; i <= size_; i++)
	{
		cout << heap_[i] << " ";
	}	
	cout << "]" << endl;
}


