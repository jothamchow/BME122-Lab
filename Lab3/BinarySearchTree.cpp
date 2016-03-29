#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree()
{
	root_=null;
	size_=1;
	val;
	left-> null;
	right-> null; 
}

BinarySearchTree::~BinarySearch Tree();
{
	delete root_;
	delete size_;
}

bool BinarySearchTree::insert(Datatype val)
{
	Node* visitor;
	
	if(val==val)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool BinarySearchTree::remove(DataType val);
{
	Node* visitor;
	visitor->root;
	if(val<root)
		visitor->left;
	else if(val>root)
		visiot->right;
}
bool BinarySearchTree::exists(DataType val) const;
{
	while()
	if(!size_)
		return false;
	else if (val)
		return true;
	else
		return false;
}

DataType BinarySearchTree::BinarySearchTree::min() const; //min val
{
	int minVal = root_->data;
	for(Node* visitor= node ;visitor!=NULL; visitor=visitor->left)
	{
		if(visitor->data > minVal)
		minVal = visitor->data;
	}
	return minVal; 
}

DataType BinarySearchTree::BinarySearchTree::max() const; //max val
{
	int maxVal = root_->data;
	for(Node* visitor= node ; visitor!=NULL; visitor=visitor->right)
	{
		if(visitor->data >maxVal)
		maxVal = visitor->data;
	}
	return maxVal; 
}

unsigned int BinarySearchTree::sBinarySearchTree::size() const; //# of nodes
{
	return size_;
}

unsigned int BinarySearchTree::depth() const; //max depth 
{
	
}

void BinarySearchTree::print() const;
{
	
}

int BinarySearchTree::getNodeDepth(Node* n) const;
	
	Node* root_;
	unsigned int size_;
	
BinarySearchTree(const BinarySearchTree& other) {}
BinaryS0earchTree& operator=(const BinarySearchTree& other) {}
