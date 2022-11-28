// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"

ArrayBasedStack::ArrayBasedStack(void) 
{
	// Use -1 to signify "Empty"
	for (int i = 0; i < 4; i++) {
		stack[i] = -1;
	}
}

ArrayBasedStack::~ArrayBasedStack() 
{

}

int ArrayBasedStack::peek() const
{
	
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return this->stack[count-1];
	}
}

std::string ArrayBasedQueue::peekFront() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return queue[0];
	}


}
// Stack

bool ArrayBasedStack::isEmpty() const 
{
	return this->count == 0;
}

bool ArrayBasedStack::push(const int & val) 
{
	if (count == 4) return false;
	this->stack[count] = val;
	count++;
	return true;
}

bool ArrayBasedStack::pop() 
{
	if (this->isEmpty()) return false;
	stack[--count] = -1;
	return true;
}

std::string ArrayBasedStack::toString() const 
{
	if (stack[0] == -1) return "";
	std::string str = "";

	str.append(std::to_string(stack[0]));

	for (int i = 1; i < count; i++) {
		if (stack[i] == -1) return str;
		str.append(" " + std::to_string(stack[i]));
	}
	return str;
}

// Queue

ArrayBasedQueue::ArrayBasedQueue(void) 
{

}

ArrayBasedQueue::~ArrayBasedQueue() 
{

}

bool ArrayBasedQueue::isEmpty() const 
{
	return this->count == 0;
}

bool ArrayBasedQueue::enQueue(const std::string &val) 
{
	if (count == 100) return false;
	this->queue[count] = val;
	count++;
	return true;
}

bool ArrayBasedQueue::deQueue() 
{
	if (this->isEmpty()) return false;
	for (int i = 1; i < count; i++) 
	{
		queue[i-1] = queue[i];
	}
	count--;
	return true;
}

std::string ArrayBasedQueue::toString() const 
{
	std::string str = "";
	str.append(queue[0]);
	for (int i = 0; i < count; i++) {
		str.append(" " + queue[i]);
	}
	return str;
}

