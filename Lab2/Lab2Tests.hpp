#ifndef LAB2_TESTS_HPP
#define LAB2_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "DynamicStack.hpp"
#include "CircularQueue.hpp"

class DynamicStackTest
{
public:
    bool test1()
    {
      unsigned int size = 24;

      DynamicStack default_size_stack;
      ASSERT_TRUE(default_size_stack.empty() == true)
      ASSERT_TRUE(default_size_stack.size() == 0)    
      ASSERT_TRUE(default_size_stack.capacity_ == 16);

      DynamicStack stack(size);
      ASSERT_TRUE(stack.empty() == true)
      ASSERT_TRUE(stack.size() == 0)    
      return true;
    }

    bool test2()
    {
      DynamicStack stack;
      stack.push(10);
      ASSERT_TRUE(stack.empty() == false)
      ASSERT_TRUE(stack.size() == 1)       
      ASSERT_TRUE(stack.pop() == 10);
      ASSERT_TRUE(stack.empty() == true)
      ASSERT_TRUE(stack.size() == 0)     
      return true;
    }

    bool test3()
    {
      DynamicStack stack(24);
      stack.push(10);
      stack.push(20);
      ASSERT_TRUE(stack.peek() == 20)     
      ASSERT_TRUE(stack.pop() == 20)
      ASSERT_TRUE(stack.pop() == 10)     
      ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
      ASSERT_TRUE(stack.peek() == DynamicStack::EMPTY_STACK)
      return true;
    }
    
    bool test4()
    {
    	DynamicStack stack(10);
    	for(int i = 0; i < 10; i++)
    	{
    		stack.push(i);
		}
		ASSERT_TRUE(stack.size() == 10);
		ASSERT_TRUE(stack.capacity_ == 10);
		stack.push(10);
		ASSERT_TRUE(stack.size() == 11);
		ASSERT_TRUE(stack.capacity_ == 20);
		for(int i = 10; i >= 0; i--)
		{
			ASSERT_TRUE(stack.pop() == i);
			ASSERT_TRUE(stack.size() == i);
		}
		ASSERT_TRUE(stack.size() == 0);
		ASSERT_TRUE(stack.capacity_ == 10);
		ASSERT_TRUE(stack.pop() == stack.EMPTY_STACK);
		ASSERT_TRUE(stack.size() == 0);
		
		for(int i = 0; i < 1000; i++)
		{
			stack.push(i);
		}
		ASSERT_TRUE(stack.size() == 1000);
		ASSERT_TRUE(stack.capacity_ == 1280);
		ASSERT_TRUE(stack.peek() == 999);
		ASSERT_TRUE(stack.size() == 1000);

		for(int i = 999; i >= 0; i--)	
		{
			ASSERT_TRUE(stack.pop() == i);
		}
		return true;
	}
	
	bool test5()
	{
		DynamicStack stack2(0);
		ASSERT_TRUE( stack2.capacity_== 16 );
		ASSERT_TRUE( stack2.init_capacity_ == 16);
		ASSERT_TRUE( stack2.size_ == 0);
		stack2.~DynamicStack();
		
		DynamicStack stack3;
		ASSERT_TRUE( stack3.capacity_== 16 );
		ASSERT_TRUE( stack3.init_capacity_ == 16);
		ASSERT_TRUE( stack3.size_ == 0);
		stack3.~DynamicStack();
		
		DynamicStack stack(8);
		ASSERT_TRUE( stack.capacity_== 8 );
		ASSERT_TRUE( stack.init_capacity_ == 8);
		ASSERT_TRUE( stack.size_ == 0);
		
		ASSERT_TRUE( stack.empty() == true);
		ASSERT_TRUE( stack.pop() == -999);
		ASSERT_TRUE( stack.size_ == 0);
	
		stack.push(10);
		ASSERT_TRUE(stack.empty() == false);
		ASSERT_TRUE(stack.size_ == 1);
		ASSERT_TRUE(stack.peek() == 10);
		
		ASSERT_TRUE(stack.pop()== 10);
		ASSERT_TRUE(stack.size_ == 0);
		ASSERT_TRUE( stack.pop() == -999);
		ASSERT_TRUE( stack.peek() == -999);
		
		stack.push(1);
		stack.push(2);
		ASSERT_TRUE( stack.size_ == 2);
		stack.push(3);
		ASSERT_TRUE( stack.peek() == 3);
		stack.push(4);
		ASSERT_TRUE( stack.size_ == 4);
		ASSERT_TRUE( stack.pop() == 4);
		ASSERT_TRUE( stack.peek() == 3);
		ASSERT_TRUE( stack.size_ == 3);
		stack.push(4);
		ASSERT_TRUE( stack.size_ == 4);
		stack.push(5);
		ASSERT_TRUE( stack.peek() == 5);
		stack.push(6);
		stack.push(7);
		stack.push(8);
		ASSERT_TRUE( stack.peek() == 8);
		ASSERT_TRUE( stack.capacity_== 8);
		stack.push(9);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		ASSERT_TRUE( stack.capacity_== 16);
		ASSERT_TRUE( stack.size_ == 9);
		ASSERT_TRUE( stack.peek() == 9);
		stack.push(10);
		stack.push(11);
		stack.push(12);
		ASSERT_TRUE( stack.size_ == 12);
		ASSERT_TRUE( stack.peek() == 12);
		ASSERT_TRUE( stack.pop() == 12);
		ASSERT_TRUE( stack.size_ == 11);
		ASSERT_TRUE( stack.peek() == 11);
		stack.push(12);
		ASSERT_TRUE( stack.size_ == 12);
		ASSERT_TRUE( stack.peek() == 12);
		ASSERT_TRUE( stack.capacity_== 16);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 12);
		ASSERT_TRUE( stack.size_ == 11);
		ASSERT_TRUE( stack.peek() == 11);
		
		ASSERT_TRUE( stack.pop() == 11);
		ASSERT_TRUE( stack.size_ == 10);
		ASSERT_TRUE( stack.peek() == 10);
		
		ASSERT_TRUE( stack.pop() == 10);
		ASSERT_TRUE( stack.size_ == 9);
		ASSERT_TRUE( stack.peek() == 9);
		
		ASSERT_TRUE( stack.pop() == 9);
		ASSERT_TRUE( stack.size_ == 8);
		ASSERT_TRUE( stack.peek() == 8);
		ASSERT_TRUE( stack.capacity_== 16);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 8);
		ASSERT_TRUE( stack.size_ == 7);
		ASSERT_TRUE( stack.peek() == 7);
		ASSERT_TRUE( stack.capacity_== 16);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 7);
		ASSERT_TRUE( stack.size_ == 6);
		ASSERT_TRUE( stack.peek() == 6);
		
		ASSERT_TRUE( stack.pop() == 6);
		ASSERT_TRUE( stack.size_ == 5);
		ASSERT_TRUE( stack.peek() == 5);
		ASSERT_TRUE( stack.capacity_== 16);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 5);
		ASSERT_TRUE( stack.size_ == 4);
		ASSERT_TRUE( stack.peek() == 4);
		ASSERT_TRUE( stack.capacity_== 8);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		stack.push(5);
		ASSERT_TRUE( stack.size_ == 5);
		ASSERT_TRUE( stack.peek() == 5);
		ASSERT_TRUE( stack.capacity_== 8);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 5);
		ASSERT_TRUE( stack.size_ == 4);
		ASSERT_TRUE( stack.peek() == 4);
		ASSERT_TRUE( stack.capacity_== 8);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 4);
		ASSERT_TRUE( stack.size_ == 3);
		ASSERT_TRUE( stack.peek() == 3);
		ASSERT_TRUE( stack.capacity_== 8);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 3);
		ASSERT_TRUE( stack.size_ == 2);
		ASSERT_TRUE( stack.peek() == 2);
		ASSERT_TRUE( stack.capacity_== 8);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 2);
		ASSERT_TRUE( stack.size_ == 1);
		ASSERT_TRUE( stack.peek() == 1);
		ASSERT_TRUE( stack.capacity_== 8);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.pop() == 1);
		ASSERT_TRUE( stack.size_ == 0);
		ASSERT_TRUE( stack.peek() == -999);
		ASSERT_TRUE( stack.capacity_== 8);
		ASSERT_TRUE( stack.init_capacity_ == 8);
		
		ASSERT_TRUE( stack.empty() == true);
		ASSERT_TRUE( stack.pop() == -999);
		ASSERT_TRUE( stack.peek() == -999);
		ASSERT_TRUE( stack.size_ == 0);
		
		stack.~DynamicStack();
		return true;
	}


};

class CircularQueueTest
{
public:
    bool test1()
    {
      CircularQueue queue;
      ASSERT_TRUE(queue.empty() == true)
      ASSERT_TRUE(queue.full() == false)
      ASSERT_TRUE(queue.size() == 0)
      ASSERT_TRUE(queue.size_ == 0)
      ASSERT_TRUE(queue.capacity_ == 16)     
      return true;
    }

    bool test2()
    {
      CircularQueue queue;
      ASSERT_TRUE(queue.enqueue(10) == true)
      ASSERT_TRUE(queue.empty() == false)
      ASSERT_TRUE(queue.full() == false )
      ASSERT_TRUE(queue.size_ == 1)
      ASSERT_TRUE(queue.head_ == 0)
      ASSERT_TRUE((queue.tail_ == 1) || (queue.tail_ == 2))
      ASSERT_TRUE(queue.dequeue() == 10);
      ASSERT_TRUE(queue.empty() == true)
      ASSERT_TRUE(queue.size_ == 0)
      return true;
    }

    bool test3()
    {
      CircularQueue queue;
      ASSERT_TRUE(queue.enqueue(10) == true)
      ASSERT_TRUE(queue.enqueue(20) == true)     
      ASSERT_TRUE(queue.empty() == false)
      ASSERT_TRUE(queue.full() == false)
      ASSERT_TRUE(queue.size_ == 2)
      ASSERT_TRUE(queue.head_ == 0)
      ASSERT_TRUE((queue.tail_ == 2) || ((queue.tail_ == 3)))
      ASSERT_TRUE(queue.peek() == 10);  
      ASSERT_TRUE(queue.dequeue() == 10);
      ASSERT_TRUE(queue.peek() == 20);  
      ASSERT_TRUE(queue.dequeue() == 20);
      ASSERT_TRUE(queue.peek() == CircularQueue::EMPTY_QUEUE);  
      ASSERT_TRUE(queue.dequeue() == CircularQueue::EMPTY_QUEUE);     
      ASSERT_TRUE(queue.empty() == true)
      ASSERT_TRUE(queue.size_ == 0)
      ASSERT_TRUE(queue.head_ == 2)
      ASSERT_TRUE((queue.tail_ == 2) || (queue.tail_ == 3))
      return true;
    }
    
    bool test4()
    {
    	CircularQueue queue(10);
    	//ASSERT_TRUE(queue.enqueue());
	}

};


#endif
