#pragma once
#include "my_utils.h"
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file Stack.h
//! Implements a stack class
//!
//! @author Denis & Ilya, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Stack class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
template <typename T>
class Stack
{
public:
	Stack();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the top element of the stack
	//! @return Top element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T top();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks the existance of elements in the stack
	//! @return Result
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool empty();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the size of stack
	//! @return Size of stack
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t size();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Pushes a value to the stack
	//! @param Value is an element to be pushed
	//! @return Success of operation
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool push(T value);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns the top element from the stack
	//! and than delete this element
	//! @return Top element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T pop();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns capacity of the stack
	//! @return Capacity
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t capacity();
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
	static const size_t capacity_ = 10;
	T data_[capacity_];
	size_t size_;
};

template <typename T>
Stack<T>::Stack() : size_(0)
{
	PRINTOUT();
	for (size_t i = 0; i < capacity_; i++)
		data_[i] = 0;
}

template <typename T>
T Stack<T>::top()
{
	PRINTOUT();
	ASSERT_OK();
	if (size_ > 0)
		return data_[size_ - 1];
	else
		throw std::logic_error("No elements in the stack, top impossible");
}

template <typename T>
bool Stack<T>::empty()
{
	ASSERT_OK();
	return !size_;
}

template <typename T>
size_t Stack<T>::size()
{
	return size_;
}

template <typename T>
bool Stack<T>::push(T value)
{
	PRINTOUT();
	ASSERT_OK();
	if (size_ >= capacity_)
		return false;
	data_[size_++] = value;
	ASSERT_OK();
	return true;
}

template <typename T>
T Stack<T>::pop()
{
	PRINTOUT();
	ASSERT_OK();
	if (size_ > 0)
	{
		T popValue = 0;
		popValue = data_[--size_];
		data_[size_] = 0;
		return popValue;
	}
	else
		throw std::logic_error("size_ = 0, pop impossible");
}

template <typename T>
size_t Stack<T>::capacity()
{
	return capacity_;
}

template <typename T>
bool Stack<T>::ok() const
{
	return size_ <= capacity_;
}

template <typename T>
void Stack<T>::dump() const
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
