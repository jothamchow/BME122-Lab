#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
	this -> value = data;
	this -> next = NULL;
	this -> prev = NULL;
	
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if(size_ == 1)
	{
		delete head_;
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
	}	
	if(head_ != NULL && size_ > 1)
	{
		Node* current = head_ -> next;
		while(current -> next != NULL)
		{
			delete current -> prev;
			current = current -> next;
		}
		delete current;
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
	}
}

bool DoublyLinkedList::empty() const
{
	if(size_ <= 0)
		return true;
	else
		return false;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	if(empty())
	{
		cout << "There are no nodes in the list." << endl;
	} 
	else
	{
		Node* current;
		current = head_;
		cout << "Printing: " << endl;
		while(current -> next != NULL)
		{
			cout << current -> value << " --> ";
			current = current -> next;
		}
		cout << current -> value << " --> NULL" << endl;
	}	
}

bool DoublyLinkedList::insert_front(DataType value)
{
	Node* newNode = new Node(value);
	
	if(full())
		return false;
	else if(empty())
	{
		head_ = newNode;
		tail_ = newNode;
		size_++;
		return true;
	}
	else if(full())
		return false;
	else
	{
		newNode -> next = head_;
		head_ -> prev = newNode;
		head_ = newNode;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_front()
{
	if(empty())
		return false;
	else if(size_ == 1)
	{
		delete head_;
		head_ = NULL;
		tail_ = NULL;
		size_--;
		return true;
	}
	else
	{
		Node* toDelete = head_;
		head_ = head_ -> next;
		head_ -> prev = NULL;
		
		delete toDelete;
		toDelete = NULL;
		size_--;	
		return true;
	}
	
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if(full())
		return false;
	else if(empty())
	{
		Node* newNode = new Node(value);
		head_ = newNode;
		tail_ = newNode;
		size_++;
		return true;
	}
	else if(full())
		return false;
	else
	{
		Node* newNode = new Node(value);
		tail_ -> next = newNode;
		newNode -> prev = tail_;
		tail_ = newNode;
		size_++;
		return true;
	}

}

bool DoublyLinkedList::remove_back()
{
	if(empty())
		return false;
	else if(size_ == 1)
	{
		delete tail_;
		head_ = NULL;
		tail_ = NULL;
		size_--;
		return true;
	}
	else
	{
		Node* toDelete = tail_;
		tail_ = tail_ -> prev;
		tail_ -> next = NULL;
		
		delete toDelete;
		toDelete = NULL;
		size_--;
		return true;
	}
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if(index > size_ || index < 0)
		return false;
	else if(full())
		return false;
	else {					
		Node* newNode = new Node(value);
		
		if(index == 0)
		{
			return insert_front(value);
		} 
		else if(index == size_)
		{
			return insert_back(value);
		}
		else
		{
			//move to the index
			Node* current = head_;
			unsigned int counter = 0;
			while(counter < index - 1)
			{
				current = current -> next;
				counter++;
			}
			//now current is at index-1
			Node* after = current -> next;
			
			current -> next = newNode;
			newNode -> prev = current;
			after -> prev = newNode;
			newNode -> next = after;
			size_++;
			
			return true; 
		
		}
	}
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if(index >= size_ || index < 0)
		return false;
	else if(empty())
		return false;	
	else
	{	
		if(index == 0)
		{
			return remove_front();
		}
		else if(index == size_ - 1)
		{
			return remove_back();
		}
		else
		{
			//move to the index
			Node* before = head_;
			unsigned int counter = 0;
			while(counter < index - 1)
			{
				before = before -> next;
				counter++;
			}
			//now before is at index-1
			Node* toDelete = before -> next;
			Node* after = before -> next -> next;
			
			before -> next = after;
			after -> prev = before;
			
			delete toDelete;
			toDelete = NULL;
			size_--;
			return true;
		}
	}
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	Node* current = head_;
	int counter = 0;
	while(current != NULL)
	{	
		if(current -> value == value)
			return counter;
		current = current -> next;
		counter++;
	}
	return size_;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if(empty())
		return -1;
	else if(index > size_ - 1 || index < 0)
		return (tail_ -> value);
	else
	{
		Node* current = head_;
		int counter = 0;
		while(counter < index)		//move current to the "ith" node, where i is index
		{
			current = current -> next;
			counter++;
		}
		return (current -> value);	
	}
}

bool DoublyLinkedList::replace(unsigned int index, DataType value_)
{
	if(index < 0 || index > size_ - 1 || empty())
		return false;
	else
	{			
		Node* newNode = new Node(value_);
		
		//Only one node
		if(size_ == 1)
		{
			delete head_;
			head_ = newNode;
			tail_ = newNode;
		}
		
		//Replace first node
		else if(index == 0)
		{
			newNode -> next = head_ -> next;
			head_ -> next -> prev = newNode;
			delete head_;
			head_ = newNode;
		}
		//Replace last node
		else if(index == size_ - 1)
		{
			tail_ -> prev -> next = newNode;
			newNode -> prev = tail_ -> prev;
			delete tail_;
			tail_ = newNode;
		}
		//Replace node in the middle
		else
		{
			Node*  before = head_;
			int counter = 0;
			
			//while((before -> next -> value) != value_ && before -> next != NULL)	//traverse to the node before the node to be replaced
			while(counter < index -1)
			{
				before = before -> next;
				counter++;
			}
			
			if(before -> next != NULL)
			{
				Node* after = before -> next -> next;		
				before -> next = newNode;
				newNode -> prev = before;
				newNode -> next = after;
				after -> prev = newNode;
			}
			else
				return false;
			
		}
		return true;
	}
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if(index > size_ -1)
		return NULL;
	else
	{
		int counter = 0;
		Node* current = head_;
		while(counter < index)	//traverse to the node at the index
		{
			counter++;
		}
		
		return current;
	}
}

bool DoublyLinkedList::full() const
{
	if(size_ == CAPACITY)
		return true;
	else
		return false;
}
