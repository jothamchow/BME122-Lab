#include "SequentialList.hpp"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
	DataType* seq_list = new DataType[cap];	
	
	if(seq_list == NULL)
		cout << "Error: Cannot initialize list." << endl;
	else
	{
		data_ = seq_list;
		capacity_ = cap;
		size_ = 0;
	}

}

SequentialList::~SequentialList()
{
	delete data_;
	data_ = NULL;
}

bool SequentialList::empty() const
{
	if(size_ <= 0)
		return true;
	else
		return false;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	if(size_ == capacity_)
		return true;
	else
		return false;
}

void SequentialList::print() const
{
	cout << "The list has " << size_ << "elements: " << endl;
	for(int i = 0; i < size_; i++)
	{
		cout << data_[i];
	}
}

bool SequentialList::insert_front(DataType val)
{
	if(full())
		return false;
	else 
	{
		if(size_ > 0)
		{
			for(int i = size_; i > 0; i--)
			{
				data_[i] = data_[i-1];
			}
		}
		data_[0] = val;
		size_ ++;
		return true;
	}
}

bool SequentialList::remove_front()
{
	if(empty())
		return false;
	else
	{
		for(int i = 0; i < size_ - 1; i++)
		{
			data_[i] = data_[i] + 1;
		}
		size_--;
		return true;
	}
}

bool SequentialList::insert_back(DataType val)
{
	if(full())
		return false;
	else 
	{
		data_[size_] = val;
		size_ ++;
		return true;
	}
}

bool SequentialList::remove_back()
{
	if(empty())
		return false;
	else
	{
		size_--;
		return true;
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(full())
		return false;
	if(index > size_ - 1)
		return false;
	else
	{
		if(empty())
			data_[0] = val;
		else
		{
			//Move all of the data to the right of the index (inclusively) to the right
			for(int i = size_; i > index; i--)
			{
				data_[i] = data_[i-1];
			}
			
			data_[index] = val;
			size_++;
		}
		return true;
	}
}

bool SequentialList::remove(unsigned int index)
{
	if(empty())
		return false;
	if(index > size_ - 1)
		return false;
	else
	{
		//Move all of the data to the right of the index (not including the data at the index itself) to the left
		for(int i = index; i < size_ - 1; i++)
		{
			data_[i] = data_[i] + 1;
		}
		size_--;
		return true;
	}
}

unsigned int SequentialList::search(DataType val) const	//returns first index of the value
{
	if(empty())
		return size_;
	else
	{
		bool found = false;
		int index = size_;
		for(int i = 0; i < size_ - 1; i++)
		{
			if(data_[i] == val)
			{
				found = true;
				index = i;
				break;
			}	
		}
		return index;
	}
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if(empty())
		return -999;
	if(index > size_ - 1)
		return data_[size_-1];
	else
	{
		return data_[index];
	}
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(empty())
		return false;
	if(index > size_ - 1)
		return false;
	else
	{
		data_[index] = val;
		return true;
	}
}
