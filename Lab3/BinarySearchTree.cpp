#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;
typedef BinarySearchTree::DataType DataType;

BinarySearchTree::Node::Node(DataType newval)
{
	val = newval;
	left = NULL;
	right = NULL;
}

BinarySearchTree::BinarySearchTree()
{

	root_ = NULL;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	while(root_ != NULL)
	remove(root_ -> val);
}

bool BinarySearchTree::insert(DataType newVal)
{
	Node* newNode = new Node(newVal);
	if(size() == 0)
	{
		root_ = newNode;
		size_++;
		return true;
	}		
	else if(exists(newVal))
		return false;
	else
	{
		Node* parent = root_;
		Node* newNode = new Node(newVal);
		while(parent -> left != NULL || parent -> right != NULL)
		{
			if(newVal < parent->val && parent -> left != NULL)
				parent = parent -> left;
			else if (newVal > parent->val && parent -> right != NULL)
				parent = parent -> right;
			else
				break;
		}
		if(newVal < parent->val)
			parent -> left = newNode;
		else if (newVal >= parent->val)
			parent -> right = newNode;
		size_++;
		return true;
	}

}

bool BinarySearchTree::remove(DataType delVal)
{
	if(!exists(delVal))
		return false;
	else
	{		
		Node* parent;
		Node* toDel = root_;
		
		// Traverse to node to be deleted and carry pointer to parent along with it
		while(toDel -> val != delVal)
		{
			parent = toDel;
			if(delVal >= toDel -> val)
				toDel = toDel -> right;
			else if(delVal < toDel -> val)
				toDel = toDel -> left;
		}
		//Case 1: Deleting root
		if(root_->val==delVal)
		{
			//If only root
			if(root_->left == NULL || root_->right == NULL)
			{
				Node* tempRoot = NULL;
				if(root_ -> left == NULL)
					tempRoot = root_ -> right;
				if(root_ -> right == NULL)
					tempRoot = root_ -> left;
				delete(root_);
				root_ = tempRoot;
				size_--;
				return true;  
			}
			
			else
			{
				Node* tempRoot = root_ -> left;
				Node* parents = root_;
				while(tempRoot-> right !=NULL)
				{
					parent = tempRoot;
					tempRoot = tempRoot -> right;
				}
				if(parent->val==root_-> val)
				{
					root_ -> val = tempRoot -> val;
					root_ -> left = tempRoot -> left;
					delete(tempRoot);
					size_--;
					return true;
				}
				parents -> right = tempRoot -> left;
				root_ ->val = tempRoot -> val;
				delete (tempRoot);
				size_--;
				return true; 
			}
			
		}
		
		//Case 1: Single element 
		if(size_==1)
		{
			Node* toDelHold = root_;
			delete(toDelHold);
			root_=NULL;
			size_--;
			return true;
		}
		// Case 2: toDel is a leaf
		else if(toDel -> right == NULL && toDel -> left == NULL)
		{
			if(parent -> left == toDel)
				parent -> left = NULL;
			else if(parent -> right == toDel)
				parent -> right = NULL;
			delete toDel;
			
		}
		// Case 3: toDel only has one child
		else if(toDel -> right == NULL && toDel -> left != NULL)
		{
			if(parent -> left == toDel)
				parent -> left = toDel -> left;
			else if(parent -> right == toDel)
				parent -> right = toDel -> left;
			delete toDel;
		}
		else if(toDel -> left == NULL && toDel -> right != NULL)
		{
			if(parent -> left == toDel)
				parent -> left = toDel -> right;
			else if(parent -> right == toDel)
				parent -> right = toDel -> right;
			delete toDel;
		}
		// Case 4: toDel has two children
		else
		{
			// Find lowest node in right subtree
			Node* lowest = toDel -> right;
			while(lowest -> left != NULL)
				lowest = lowest -> left;
			
			////Store lowest value
			int parentVal = lowest -> val;
		
			
			// Delete lowest
			remove(lowest -> val);
			
			// Store lowest value in parent
			parent -> val = parentVal;
			
	
//			if(parent -> right == toDel && toDel -> left == NULL)
//				parent -> right = toDel -> right;
//			else if(parent -> right == toDel && toDel -> right == NULL)
//				parent -> right = toDel -> left;
//			else if(parent -> left == toDel && toDel -> left == NULL)
//				parent -> left = toDel -> right;
//			else if(parent -> left == toDel && toDel -> right == NULL)
//				parent -> left = toDel -> left;
//			delete toDel;
//			remove(lowest -> val);
//			parent -> val = parentVal;
		}
		size_--;
		return true;
	}
}

bool BinarySearchTree::exists(DataType searchVal) const
{
	Node* currentNode = root_;
	if(size() == 0)
		return false;
	else if((root_ -> val) ==  searchVal)
		return true;
	else
	{
		
		while(currentNode != NULL)
		{
			if (searchVal == currentNode -> val)
				return true;
			else if(searchVal < currentNode -> val)
				currentNode = currentNode -> left;
			else if(searchVal > currentNode -> val)
				currentNode = currentNode -> right;
		}
		return false;
	}
}

DataType BinarySearchTree::BinarySearchTree::min() const
{
	Node* currentNode = root_;
	while(currentNode -> left != NULL)
	{
		currentNode = currentNode -> left;
	}
	return (currentNode -> val);
}

DataType BinarySearchTree::BinarySearchTree::max() const
{
	Node* currentNode = root_;
	while(currentNode -> right != NULL)
	{
		currentNode = currentNode -> right;
	}
	return (currentNode -> val);
}

unsigned int BinarySearchTree::BinarySearchTree::size() const
{
	return size_;
}

unsigned int BinarySearchTree::depth() const
{
	if(size() == 0)
		return 0;
	else
		return getNodeDepth(root_);
}

void BinarySearchTree::print() const //in order 
{	
//	if (root_==NULL)
//		return 0;
//		
//	std::stringstream ss;
//	std::queue<BinarySearchTree::Node*> node_queue;
//	node_queue.push(root);
//	while(!node_queue.empty())
//	{
//		BinarySearchTree::Node* cur_node=node_queue.front();
//		node_queue.pop();
//		ss << cur_node->val <<" ";
//		if(cur_node->left !=NULL)
//		{
//			node_queue.push(cur_node->left);
//		}
//		if (cur_node->right !=NULL)
//		{
//			node_queue.push(cur_node->right);
//		}
//		
//		std::string leve_order_str = ss.str();
//		return level_order_str.substr(0, level_order_str.size()-1);
//	}
}


int BinarySearchTree::getNodeDepth(Node* n) const
{
	if(n == NULL)
		return 0;
	while(n -> left != NULL || n -> right != NULL)
	{
		if(getNodeDepth(n -> left) < getNodeDepth(n->right))
			return (1 + getNodeDepth(n -> right));
		else
			return (1 + getNodeDepth(n -> left));
	}
}	


