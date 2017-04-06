﻿#pragma once
#include "my_utils.h"
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file Array.h
//! Implements an array class
//!
//! @author Denis & Ilya, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Array class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
template <typename T, size_t SIZE>
class Array	
{
public:
	class IteratorForArray;
	const T POISON_VALUE = T();

	Array()
		: capacity_(SIZE), size_(0)
	{
		PRINTOUT();
	};
	~Array()
	{
		std::cout << __FUNCTION__ << std::endl;
		for (size_t i = 0; i < SIZE; ++i)
			data_[i] = POISON_VALUE;
		dump();
		capacity_ = POISON_VALUE;
		size_ = POISON_VALUE;
		std::cout << "capacity_ = " << capacity_ << std::endl <<
			"size_ = " << size_ << std::endl;
	};
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Overrides of operator []
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& operator[] (size_t index);
	const T& operator[] (size_t index) const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Gives access to the element by index
	//! @param Index of element
	//! @return Reference to an element by index
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& at(size_t pos);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Gives access to the first element
	//! @return Reference to the first element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& front();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Gives access to the last element
	//! @return Reference to the last element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& back();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks the existance of elements in array
	//! @return Result
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool empty() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Getter of size
	//! @return Size of array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t size() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Getter of capacity
	//! @return Capacity of array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t capacity() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Fills the array with specified values
	//! @param The value to fill in the array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void fill(T value);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Displays information about the state of array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void dump() const;
	bool ok() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Moves iterator to the beginning of array
	//! @return Iterator on the first element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForArray begin();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Moves iterator to the end of array
	//! @return Iterator on the element after last
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForArray end();
private:
	size_t capacity_;
	T data_[SIZE];
	size_t size_; 
};

template <typename T, size_t SIZE>
T& Array<T, SIZE>::operator[] (size_t index)
{
	ASSERT_OK();
	PRINTOUT();
	if (index < 0 || index >= size)
		throw std::logic_error("Index went out of Array");
	return data_[index];
}

template <typename T, size_t SIZE>
const T& Array<T, SIZE>::operator[] (size_t index) const
{
	ASSERT_OK();
	PRINTOUT();
	if (index < 0 || index >= size)
		throw std::logic_error("Index went out of Array");
	return data_[index];
}

template <typename T, size_t SIZE>
T& Array<T, SIZE>::at(size_t pos)
{
	return data_[pos];
}

template <typename T, size_t SIZE>
T& Array<T, SIZE>::front()
{
	return data_[0];
}

template <typename T, size_t SIZE>
T& Array<T, SIZE>::back()
{
	return data_[capacity_ - 1];
}

template <typename T, size_t SIZE>
bool Array<T, SIZE>::empty() const
{
	return !size_;
}

template <typename T, size_t SIZE>
size_t Array<T, SIZE>::size() const
{
	return size_;
}

template <typename T, size_t SIZE>
size_t Array<T, SIZE>::capacity() const
{
	return capacity_;
}

template <typename T, size_t SIZE>
void Array<T, SIZE>::fill(T value)
{
	PRINTOUT();
	for (size_t i = 0; i < capacity_; ++i)
	{
		data_[i] = value;
		++size_;
	}
	dump();
}

template <typename T, size_t SIZE>
bool Array<T, SIZE>::ok() const
{
	return size_ <= capacity_;
}

template <typename T, size_t SIZE>
void Array<T, SIZE>::dump() const
{
	std::cout << "capacity_ = " << capacity_ << std::endl;
	std::cout << "size_ = " << size_ << std::endl;
	for (size_t i = 0; i < capacity_; ++i)
	{
		std::cout << "[ " << i << " ] = " << data_[i] << std::endl;
	}
}
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Iterator for array class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
template <typename T, size_t SIZE>
class Array<T, SIZE>::IteratorForArray
{
public:
	IteratorForArray (Array<T,SIZE>& that)
		: iterator_(that.data_), sizeOfArray_(that.size_), counter_(0)
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	~IteratorForArray()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator ++
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForArray& operator++();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator --
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForArray& operator--();
	T& operator*();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator !=
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator!= (IteratorForArray& rhs)
	{
		return iterator_ != rhs.iterator_;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator ==
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator== (IteratorForArray& rhs)
	{
		return iterator_ == rhs.iterator_;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Getter of iterator
	//! @return Value of iterator
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t iterator();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Getter of size
	//! @return Value of sizeOfArray
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t sizeOfArray();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Getter of counter
	//! @return Value of counter
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t counter();
private:
	T * iterator_;
	size_t sizeOfArray_;
	size_t counter_;
};

template <typename T, size_t SIZE>
typename Array<T, SIZE>::IteratorForArray& Array<T, SIZE>::IteratorForArray::operator++ ()
{
	if (counter_ > sizeOfArray_)
		throw std::logic_error("Iterator points to the last element");
	++iterator_;
	++counter_;
	return *this;
}

template <typename T, size_t SIZE>
typename Array<T, SIZE>::IteratorForArray& Array<T, SIZE>::IteratorForArray::operator-- ()
{
	if (counter_ == 0)
		throw std::logic_error("Iterator points to the first element");
	--iterator_;
	--counter_;
	return *this;
}

template <typename T, size_t SIZE>
T& Array<T, SIZE>::IteratorForArray::operator* ()
{
	return *iterator_;
}

template <typename T, size_t SIZE>
size_t Array<T, SIZE>::IteratorForArray::iterator()
{
	return iterator_;
}

template <typename T, size_t SIZE>
size_t Array<T, SIZE>::IteratorForArray::sizeOfArray()
{
	return sizeOfArray_;
}

template <typename T, size_t SIZE>
size_t Array<T, SIZE>::IteratorForArray::counter()
{
	return counter_;
}

template <typename T, size_t SIZE>
typename Array<T, SIZE>::IteratorForArray Array<T, SIZE>::begin()
{
	IteratorForArray it(*this);
	return it;
}

template <typename T, size_t SIZE>
typename Array<T, SIZE>::IteratorForArray Array<T, SIZE>::end()
{
	IteratorForArray it(*this);
	while (it.counter() != it.sizeOfArray())
		++it;
	return it;
}