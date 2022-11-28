#ifndef SQ_H
#define SQ_H
#include <string>

class IStack {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	/// Adds a value to the Stack.  Returns true if able to add, otherwise false
	virtual bool push(const int & val) = 0;
	/// removes a value from the stack.   Feturns true if able to remove an element, otherwise false
	virtual bool pop() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns top of stack
	virtual int peek() const = 0;
	// outputs contents to a string
	virtual std::string toString() const = 0;
	
protected:
	int count = 0;
};



class ArrayBasedStack : IStack {
public:
	ArrayBasedStack(void);
	virtual ~ArrayBasedStack();
	bool isEmpty() const override;
	bool push(const int & val) override;
	bool pop() override;
	//If the ADT is empty throw an exception indicating this
	int peek() const override;
	std::string toString() const override;
private:
	int stack[4];
	

};


class IQueue {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	// Adds a value to the Q.  Returns true if able otherwise false
	virtual bool enQueue(const std::string &val) = 0;
	// remove a value to the Q.  Returns true if able otherwise false
	virtual bool deQueue() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns the value of the 
	// front of the Q
	virtual std::string peekFront() const = 0;

	// outputs contents to a string
	virtual std::string toString() const = 0;
protected:
	int count = 0;
};



class  ArrayBasedQueue : IQueue {
public:
	ArrayBasedQueue(void);
	virtual ~ArrayBasedQueue();
	bool isEmpty() const override;
	bool enQueue(const std::string &val) override;
	bool deQueue() override;
	//If the ADT is empty throw an exception indicating this
	std::string peekFront() const override;
	std::string toString() const override;
private:
	// If you use more than 100 moves, sorry I guess.
	std::string queue[100];

};

#endif








