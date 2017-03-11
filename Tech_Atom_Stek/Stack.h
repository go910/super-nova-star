#pragma once
#include <stdio.h>
#include <iostream>
#include <cassert>
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file Stack.h
//! Implements a stack class
//!
//! @author Den, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Stack class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
class Stack
{
public:
	typedef float value_type; //!< Elements type
	typedef size_t size_type; //!< Size type
	Stack();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the top element of the stack
	//! @return Top element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type top();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks the existance of elements in the stack
	//! @return Result
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool empty();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the size of stack
	//! @return Size of stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type size();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Pushes a value to the stack
	//! @param Value is an element to be pushed
	//! @return Success of operation
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool push(value_type value);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the top element from the stack
	//! and than delete this element
	//! @return Top element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type pop();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns capacity of the stack
	//! @return Capacity
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_type capacity();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks the stack overflow
	//! @return Result
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool ok() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Shows the condition of memory
	//! @return Condition of attributes and stack elements
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void dump() const;
private:
	static const size_type capacity_ = 10;
	value_type data_[capacity_];
	size_type size_;
};
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to check a condition and exit if it failes
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#define ASSERT_OK() \
	if (!ok()) \
	{ \
		dump(); \
		assert(!"ERROR"); \
	}

Stack::Stack() : size_(0)
{
	for (size_t i = 0; i < capacity_; i++)
		data_[i] = 0;
}

Stack::value_type Stack::top()
{
	ASSERT_OK();
	if (size_ > 0)
		return data_[size_ - 1];
	else
		abort();
}

bool Stack::empty()
{
	ASSERT_OK();
	return !size_;
}

Stack::size_type Stack::size()
{
	return size_;
}

bool Stack::push(value_type value)
{
	ASSERT_OK();
	if (size_ >= capacity_)
		return false;
	data_[size_++] = value;
	ASSERT_OK();
	return true;
}

Stack::value_type Stack::pop()
{
	ASSERT_OK();
	if (size_ > 0)
	{
		value_type popValue = 0;
		popValue = data_[--size_];
		data_[size_] = 0;
		return popValue;
	}
	else
		abort();
}

Stack::size_type Stack::capacity()
{
	return capacity_;
}

bool Stack::ok() const
{
	return size_ <= capacity_;
}

void Stack::dump() const
{
	std::cout << "capacity_ = " << capacity_ << std::endl;
	std::cout << "size_ = " << size_ << std::endl;
	std::cout << "data_[" << capacity_ << "]:" << std::endl;
	for (size_t i = 0; i < capacity_; i++)
	{
		if (i < size_)
			std::cout << " * [" << i << "] = " << data_[i] << std::endl;
		else
			std::cout << "   [" << i << "] = " << data_[i] << std::endl;
	}
}
