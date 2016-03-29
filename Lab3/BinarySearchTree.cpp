#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;
typedef BinarySearchTree::DataType DataType;

BinarySearchTree::BinarySearchTree()
{
	root_ = NULL;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	delete root_;
	root_ = NULL;
}

bool BinarySearchTree::insert(DataType val)
{
}

bool BinarySearchTree::remove(DataType val)
{
}
bool BinarySearchTree::exists(DataType val) const
{
	
}

DataType BinarySearchTree::BinarySearchTree::min() const
{
	Node* current = root_;
	while(current -> left != NULL)
	{
		current = current -> left;
	}
	return (current -> val);
}

DataType BinarySearchTree::BinarySearchTree::max() const
{
	Node* current = root_;
	while(current -> right != NULL)
	{
		current = current -> right;
	}
	return (current -> val);
}

unsigned int BinarySearchTree::BinarySearchTree::size() const
{
	return size_;
}

unsigned int BinarySearchTree::depth() const
{
	
}

void BinarySearchTree::print() const
{
	cout << "[ ";
	
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
	
}	


