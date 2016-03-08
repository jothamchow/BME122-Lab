#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"
using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	head_ = -1;
	tail_ = 0;
	capacity_ = 16;
	size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	items_ = new QueueItem[capacity];
	head_ = -1;
	tail_ = 0;
	capacity_ = capacity;
	size_ = 0;
}

CircularQueue::~CircularQueue()
{
	delete[] items_;
	items_ = NULL;
}

bool CircularQueue::empty() const
{
	if(size_ == 0)
		return true;
	else 
		return false;    
}

bool CircularQueue::full() const
{
	if(size_ == capacity_)
		return true;
	else 
		return false;
}

int CircularQueue::size() const
{
	return size_;  
}

bool CircularQueue::enqueue(QueueItem value)
{
	if(full())
		return false;
	else 
	{
		if(empty())
			head_++;
		if(tail_ + 1 > capacity_)
			tail_ = 0;
		items_[tail_] = value;
		tail_++;
		if(tail_ == capacity_)
			tail_ = 0;
		size_++;
		return true;
	}
	
}

QueueItem CircularQueue::dequeue()
{
	QueueItem val = items_[head_];
	
	if(empty())
		return EMPTY_QUEUE;
//	else if(size_ == 1)
//	{
//		head_ = -1;
//		tail_ = 0;
//		size_--;
//		return val;
//	}
	else
	{
		if(head_ + 1 == capacity_)
			head_ = 0;
		else
			head_++;
		size_--;
		return val;
	}
}

QueueItem CircularQueue::peek() const
{
	if(empty())
		return EMPTY_QUEUE;
	else
		return items_[head_];
}

void CircularQueue::print() const
{
	cout << "[ ";
	for(int i = 0; i < size_; i++)
	{
		cout << items_[i] << " ";
	}
	cout << "]" << endl;
}
