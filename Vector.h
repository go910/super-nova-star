#pragma once
#include <iostream>
#include <cassert>
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file Vector.h
//! Implements a vector class
//!
//! @author Denis & Ilya, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Vector class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
template <typename T>
class Vector
{
public:
	
	class IteratorForVector;
	const int POISON_VALUE = 0xDEADDEAD;//!< Poison value

	Vector()
		: size_(0), capacity_(10), data_(new T[capacity_])
	{
		std::cout << __FUNCTION__ << std::endl;
		dump();
	}
	
	explicit Vector(size_t capacity)
	{
		size_ = 0;
		capacity_ = capacity;
		if (capacity_ == 0)
			data_ = nullptr;
		else
			data_ = new T[capacity_];
		std::cout << __FUNCTION__ << std::endl;
		dump();
	};

	Vector(const Vector& that)
		: size_(that.size_), capacity_(that.capacity_), data_(new T[that.size_])
	{
		std::cout << __FUNCTION__  << "(copy)" << std::endl;
		dump();
		Vector victim(that.capacity_);
		for (size_t i = 0; i < that.size_; ++i)
			victim.data_[i] = that.data_[i];
		victim.size_ = that.size_;
		std::swap(size_, victim.size_);
		std::swap(capacity_, victim.capacity_);
		std::swap(data_, victim.data_);
		dump();
	};

	~Vector()
	{
		std::cout << __FUNCTION__ << std::endl;
		dump();
		delete[] data_;
		size_ = POISON_VALUE;
		data_ = nullptr;
		dump();
		capacity_ = POISON_VALUE;
		std::cout << "capacity_ = " << capacity_ << std::endl;
	};
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator =
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	const Vector& operator=(const Vector& that);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redeterminations of operator []
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	const T& operator [] (size_t index);
	T& operator [](IteratorForVector iterator);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator ==
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	const bool operator== (Vector& rhs);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redeterminations of operator new
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//void* operator new (size_t size, size_t n, int init);
	//void* T::operator new[](size_t size, size_t n);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks the condition of the object
	//! @return Result
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool ok() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Displays information about the state of vector
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void dump() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns capacity
	//! @return Value of "capacity_"
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t capacity();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returns size
	//! @return Value of "size_"
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t size();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Pushes a value to the end of vector
	//! @param Value is an element to be pushed
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void push_back(T add_elem);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Removed the last element of vector
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void pop_back();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Provides access to an element by index
	//! @param Index of element to access
	//! @return Reference to an element with the index "pos"
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& at(size_t pos);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Provides access to the first element
	//! @return Reference to the first element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& front();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Provides access to the last element
	//! @return Reference to the last element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& back();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks the existence of elements in the vector
	//! @return Result
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool empty() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Moves iterator to the first of array
	//! @return Iterator on the first element
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector begin();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Moves iterator to the end of array
	//! @return Iterator on the element after last
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector end();
private:
	size_t size_;
	size_t capacity_;
	T* data_;
};

#define ASSERT_OK() \
	if (!ok()) \
	{ \
		dump(); \
		assert(!"Imbalance of size of Vector"); \
	}

template <typename T>
const Vector<T>& Vector<T>::operator= (const Vector<T>& that)
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	if (&that == this)
		return *this;
	else
	{
		Vector victim(that);
		dump();
		std::swap(size_, victim.size_);
		std::swap(capacity_, victim.capacity_);
		std::swap(data_, victim.data_);
		dump();
		return *this;
	}
}

template <typename T>
const T& Vector<T>::operator[] (size_t index)
{
	assert(0 <= index && index < capacity_);
	return data_[index];
}

template <typename T>
T& Vector<T>::operator[] (IteratorForVector iterator)
{
	return *iterator.iterator();
}

template <typename T>
const bool Vector<T>::operator== (Vector<T>& that)
{
	int flag = 0;
	if (&that == this)
		return true;
	else if (size_ != that.size_)
		return false;
	for (size_t i = 0; i < size_; ++i)
	{
		if (data_[i] != that.data_[i])
			return false;
	}
	return true;
}

//template <typename T>
//void* Vector<T>::operator new(size_t size, size_t n, int init)
//{
//	std::cout << __FUNCTION__ << std::endl;
//	void * p = malloc(size * n);
//	memset(p, init, size * n);
//	std::cout << "size = " << size << std::endl;
//	std::cout << "n = " << n << std::endl;
//	std::cout << "init = " << init << std::endl;
//	std::cout << "sizeof(Vector<int>) = " << sizeof(Vector<int>) << std::endl;
//	return p;
//}

//template <typename T>
//void* T::operator new[](size_t size, size_t n)
//{
//	std::cout << __FUNCTION__ << std::endl;
//	void * p = malloc(size * n);
//	memset(p, 0, size * n);
//	return p;
//}

template <typename T>
bool Vector<T>::ok() const
{
	return size_ <= capacity_;
}

template <typename T>
void Vector<T>::dump() const
{
	std::cout << "size_ = " << size_ << std::endl;
	std::cout << "capacity_ = " << capacity_ << std::endl;
	std::cout << "Address of vector: " << this << std::endl;
	if (data_ != nullptr)
	{
		for (size_t i = 0; i < capacity_; ++i)
			std::cout << "[ " << i << " ] = " << data_[i] << std::endl;
	}
	//_getwch();
}

template <typename T>
size_t Vector<T>::capacity()
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	return capacity_;
}

template <typename T>
size_t Vector<T>::size()
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	return size_;
}

template <typename T>
void Vector<T>::push_back(T add_elem)
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	if (size_ >= capacity_)
	{
		size_t last_capacity = capacity_;
		T * Temp_Array = 0;
		if (size_ % 10 == 0)
			Temp_Array = new  T[capacity_ += 10];
		else
			Temp_Array = new T[capacity_ += (10 - (size_ % 10))];
		for (size_t i = 0; i < last_capacity; ++i)
			Temp_Array[i] = data_[i];
		Temp_Array[last_capacity] = add_elem;
		++size_;
		delete[] data_;
		data_ = Temp_Array;
	}
	else
	{
		data_[size_] = add_elem;
		++size_;
	}
	std::cout << std::endl;
	dump();
	ASSERT_OK();
}

template <typename T>
void Vector<T>::pop_back()
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	ASSERT_OK();
	data_[--size_] = POISON_VALUE;
	std::cout << std::endl;
	dump();
}

template <typename T>
T& Vector<T>::at(size_t pos)
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	return *(data_ + pos);
}

template <typename T>
T& Vector<T>::front()
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	return *(data_);
}

template <typename T>
T& Vector<T>::back()
{
	std::cout << __FUNCTION__ << std::endl;
	dump();
	return *(data_ + size_ - 1);
}

template <typename T>
bool Vector<T>::empty() const
{
	std::cout << __FUNCTION__ << std::endl;
	//dump();
	return !size_;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Iterator for Vector class
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
template <typename T>
class Vector<T>::IteratorForVector
{
public:
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator !=
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator!= (IteratorForVector& rhs)
	{
		return iterator_ != rhs.iterator_;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator ==
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator== (IteratorForVector& rhs)
	{
		return iterator_ == rhs.iterator_;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator ++
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector& operator++ ();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator --
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector& operator-- ();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator -
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector& operator- (size_t value);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator *
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& operator* ();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Redetermination of operator ->
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T* operator-> ();

	IteratorForVector(Vector<T>* v)
		: iterator_(v->data_), sizeOfVector_(v->size_), counter_(0)
	{
		std::cout << __FUNCTION__ << std::endl;
	};
	~IteratorForVector()
	{
		std::cout << __FUNCTION__ << std::endl;
	};
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Checks the condition of the object
	//! @return Result
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool okForIterator() const;
	T* iterator();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Getter of size of vector
	//! @return Value of sizeOfVector
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t sizeOfVector();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Getter of the counter
	//! @return Value of the counter
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	size_t counter();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Moves the iterator one cell forward
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void increment();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Moves the iterator one cell back
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void decrement();
private:
	T* iterator_;
	size_t sizeOfVector_;
	size_t counter_;
};

template <typename T>
T* Vector<T>::IteratorForVector::iterator()
{
	return iterator_;
}

template <typename T>
size_t Vector<T>::IteratorForVector::sizeOfVector()
{
	return sizeOfVector_;
}

template <typename T>
size_t Vector<T>::IteratorForVector::counter()
{
	return counter_;
}

#define ASSERT_OK_IT() \
if (!okForIterator()) \
{ \
assert(!"Iterator went out of Vector"); \
}

template <typename T>
bool Vector<T>::IteratorForVector::okForIterator() const
{
	return counter_ <= sizeOfVector_;
}

template <typename T>
void Vector<T>::IteratorForVector::increment()
{
	ASSERT_OK_IT();
	++iterator_;
	++counter_;
	ASSERT_OK_IT();
}

template <typename T>
void Vector<T>::IteratorForVector::decrement()
{
	assert(counter_ != 0);
	--iterator_;
	--counter_;
}

template <typename T>
typename Vector<T>::IteratorForVector& Vector<T>::IteratorForVector::operator++ ()
{
	increment();
	return *this;
}

template <typename T>
T& Vector<T>::IteratorForVector::operator* ()
{
	return *iterator_;
}

template <typename T>
typename Vector<T>::IteratorForVector& Vector<T>::IteratorForVector::operator-- ()
{
	decrement();
	return *this;
}

template <typename T>
typename Vector<T>::IteratorForVector& Vector<T>::IteratorForVector::operator- (size_t value)
{
	assert(counter_ != 0 && value < counter_);
	iterator_ -= value;
	counter_ -= value;
	return *this;
}

template <typename T>
T* Vector<T>::IteratorForVector::operator-> ()
{
	return iterator_;
}

template <typename T>
typename Vector<T>::IteratorForVector Vector<T>::begin()
{
	IteratorForVector it(this);
	return it;
}

template <typename T>
typename Vector<T>::IteratorForVector Vector<T>::end()
{
	IteratorForVector it(this);
	while (it.counter() != it.sizeOfVector())
		++it;
	return it;
}