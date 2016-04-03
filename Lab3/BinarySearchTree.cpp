#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree()
{
	root_=NULL;
	size_=0;
	val;
	left-> NULL;
	right-> NULL; 
}

BinarySearchTree::~BinarySearch Tree();
{
	delete root_;
	delete size_;
}

bool BinarySearchTree::insert(Datatype val)
{
	Node* newNode = new Node(val);
	
	if(size_==0)
	{
		root_->newNode;
		return true;
	}
	else
	{
		Node* visitor;
		visitor->root;
		
		if(val==visitor->value)
		{
			return false;
		}
		else if(val<visitor->value)
		{
			visitor->left;
		}
		else //(val>current)
		{
			visitor->right;
		}
	}

}

bool BinarySearchTree::remove(DataType val);
{
	Node* visitor;
	visitor->root;
	
	if(val==visitor->value)
		delete visitor->value;
	else 
	{
		if(val<visitor->value)
		{
			node->left;
		}
		else //(val>visitor->value)
		{
			node->right;
		}
	}
	return false;//if val not found 
}
bool BinarySearchTree::exists(DataType val) const;
{
	Node* visitor;
	visitor->root;
	
	if(val==visitor->value)
		return true;
	else 
	{
		if(val<visitor->value)
		{
			visitor->left;
		}
		else 
		{
			visitor->right;
		}
	}
	return false;
}

DataType BinarySearchTree::BinarySearchTree::min() const; //min val
{
	int minVal = root_->data;
	for(Node* visitor= node ; visitor!=NULL; visitor=visitor->left)
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

void BinarySearchTree::print() const; //in order 
{	
	if(root !=NULL)
	{
		Node* visitor;
		visitor->root_; 
		
		while(visitor->left !=NULL)
		{
			visitor->left;
		}
		cout << visitor->value << endl;
		
		while(visitor->right !=NULL)
		{
			visitor->right;
		} 
		cout << visitor->value << endl;
	}
	else
		return false; 
}

int BinarySearchTree::getNodeDepth(Node* n) const;
	
	Node* root_;
	unsigned int size_;
	
BinarySearchTree(const BinarySearchTree& other) {}
BinaryS0earchTree& operator=(const BinarySearchTree& other) {}
