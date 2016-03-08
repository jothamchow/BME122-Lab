#include "DynamicStack.hpp"
#include <iostream>
using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;



DynamicStack::DynamicStack()
{
	items_ = new StackItem[16];
	size_ = 0;
	capacity_ = 16;
	init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	items_ = new StackItem[capacity];
	size_ = 0;
	capacity_ = capacity;
	init_capacity_ = capacity;
}

DynamicStack::~DynamicStack()
{
	delete items_;
	items_ = NULL;
}

bool DynamicStack::empty() const
{
	if(size_ == 0)
		return true;
	else
		return false;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_ == capacity_)
	{
		capacity_ *= 2;
		StackItem* newStack = new StackItem[capacity_];
		for(int i = 0; i < capacity_/2; i++)
		{
			newStack[i] = items_[i];
		}
		delete items_;
		items_ = newStack;
		
		items_[size_] = value;
		size_++;
	}
	else
	{
		items_[size_] = value;
		size_++;
	}
}

StackItem DynamicStack::pop()
{
	if(empty())
		return EMPTY_STACK;
	else
	{
		size_--;
		
		if(size_ <= capacity_/4 && capacity_/2 >= init_capacity_)
		{
			capacity_ /= 2;
			StackItem* newStack = new StackItem[capacity_];
			for(int i = 0; i < size_; i++)
			{
				newStack[i] = items_[i];
			}
			items_ = newStack;
		}
		return items_[size_];
	}
}

StackItem DynamicStack::peek() const
{
	if(empty())
		return EMPTY_STACK;
	else
		return items_[size_ - 1];
}

void DynamicStack::print() const
{
	cout << "[ ";
	for(int i = 0; i < size_; i++)
	{
		cout << items_[i] << " ";
	}
	cout << "]" << endl;
}
