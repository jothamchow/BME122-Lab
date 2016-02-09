#include "DynamicStack.hpp"

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
	init_capacity_ = 16;
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
}

int DynamicStack::size() const
{
}

void DynamicStack::push(StackItem value)
{
}

StackItem DynamicStack::pop()
{
}

StackItem DynamicStack::peek() const
{
}

void DynamicStack::print() const
{
}
