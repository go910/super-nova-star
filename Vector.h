#pragma once
#include "my_utils.h"
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
	const T POISON_VALUE = T();//!< Poison value

	Vector()
		//: size_(0), capacity_(10), 
		//: data_(new T[capacity_])
	{
		PRINTOUT();
	}
	
	explicit Vector(size_t capacity)
	{
		size_ = 0;
		capacity_ = capacity;
		if (capacity_ == 0)
			data_ = nullptr;
		else
			data_ = new T[capacity_];
		PRINTOUT();
	};

	Vector(const Vector& that)
		: size_(that.size_), capacity_(that.capacity_), data_(new T[that.size_])
	{
		PRINTOUT();
		Vector victim(that.capacity_);
		for (size_t i = 0; i < that.size_; ++i)
			victim.data_[i] = that.data_[i];
		victim.size_ = that.size_;
		std::swap(this, victim);
		dump();
	};

	~Vector()
	{
		PRINTOUT();
		delete[] data_;
		size_ = POISON_VALUE;
		data_ = nullptr;
		dump();
		capacity_ = POISON_VALUE;
		std::cout << "capacity_ = " << capacity_ << std::endl;
	};
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator =
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	const Vector& operator=(const Vector& that);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator []
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	const T& operator [] (size_t index);
	T& operator [](IteratorForVector iterator);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator ==
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	const bool operator== (Vector& rhs);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Overrides of operator new
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void* operator new (size_t size, int init);
	void operator delete (void *p);
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
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Nulls Vector (for operator new)
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void setData();
};

template <typename T>
const Vector<T>& Vector<T>::operator= (const Vector<T>& that)
{
	PRINTOUT();
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
	if (index < 0 || index >= capacity_)
		throw std::logic_error("Exception: Index is out of Vector");
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
		if (data_[i] != that.data_[i])
			return false;
	return true;
}

template <typename T>
void* Vector<T>::operator new(size_t size, int init)
{
	if (init != 0)
		throw std::logic_error("Exception: init is not NULL");
	std::cout << __FUNCTION__ << std::endl;
//	std::cout << "init = " << init << std::endl;
//	std::cout << "n = " << n << std::endl;
//	std::cout << "sizeof(Vector<int>) = " << sizeof(Vector<int>) << " " << size << std::endl;
	void * p = malloc(size);
//	std::cout << "size = " << size << std::endl;
	(*(Vector<T> *)p).size_ = init;
	(*(Vector<T> *)p).capacity_ = 10;
	(*(Vector<T> *)p).data_ = new T[10];
//	(*(Vector<T> *)p).dump();
//	std::cout << "Checkpoint" << std::endl;
	(*(Vector<T> *)p).setData();
	return p;
}

template <typename T>
void Vector<T>::operator delete(void *p)
{
	free(p);
}

template <typename T>
void Vector<T>::setData()
{
	for (size_t i = 0; i < 10; ++i)
		data_[i] = 0;
}

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
		for (size_t i = 0; i < capacity_; ++i)
			std::cout << "[ " << i << " ] = " << data_[i] << std::endl;
}

template <typename T>
size_t Vector<T>::capacity()
{
	return capacity_;
}

template <typename T>
size_t Vector<T>::size()
{
	return size_;
}

template <typename T>
void Vector<T>::push_back(T add_elem)
{
	PRINTOUT();
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
	PRINTOUT();
	ASSERT_OK();
	if (size_ != 0)
		data_[--size_] = POISON_VALUE;
	else
		throw std::logic_error("Exception: size_ = 0, pop_back impossible");
	std::cout << std::endl;
	dump();
}

template <typename T>
T& Vector<T>::at(size_t pos)
{
	PRINTOUT();
	if (pos < 0 || pos >= size_)
		throw std::logic_error("Exception: Index is out of Vector");
	return *(data_ + pos);
}

template <typename T>
T& Vector<T>::front()
{
	return *(data_);
}

template <typename T>
T& Vector<T>::back()
{
	return *(data_ + size_ - 1);
}

template <typename T>
bool Vector<T>::empty() const
{
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
	//! Override of operator !=
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator!= (IteratorForVector& rhs)
	{
		return iterator_ != rhs.iterator_;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator ==
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator== (IteratorForVector& rhs)
	{
		return iterator_ == rhs.iterator_;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator ++
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector& operator++ ();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator --
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector& operator-- ();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator -
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	IteratorForVector& operator- (size_t value);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator *
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	T& operator* ();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator ->
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
	throw std::logic_error("Iterator went out of Vector"); \
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
	if (counter_ == 0)
		throw std::logic_error("counter_ = 0, decrement impossible");
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
	if (counter == 0 && value > counter_)
		throw std::logic_error("Exception: Vector has not elements");
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

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Specification of Vector class (for bool)
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
template <>
class Vector <bool>
{
public:
	class Proxy;
	const unsigned char POISON_VALUE = unsigned char();
	Vector()
		: size_(0), capacity_(1), data_(new unsigned char[capacity_])
	{
		std::cout << "It's bool!" << std::endl;
		data_[0] = POISON_VALUE;
		PRINTOUT();
	};
	~Vector()
	{
		delete[] data_;
		data_ = nullptr;
		size_ = POISON_VALUE;
		capacity_ = POISON_VALUE;
//		std::cout << "capacity_ = " << capacity_ << std::endl;
	};
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Overrides of operator []
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool operator [] (int index) const
	{
		int bit = data_[index / 8] & 1 << (7 - index) ? 1 : 0;
		return !!bit;
	}
	Proxy operator [](int index);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Displays information about condition of Vector <bool>
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	void dump();
private:
	size_t size_;
	size_t capacity_;
	unsigned char * data_;
};

void Vector<bool>::dump()
{
	std::cout << "size_ = " << size_ << std::endl;
	std::cout << "capacity_ = " << capacity_ << std::endl;
	std::cout << "Adress of vector<bool>: " << this << std::endl;
	if (data_ != nullptr)
		for (size_t i = 0; i < capacity_; ++i)
		{
			int bit = 0;
			for (int j = 0; j < 8; ++j)
			{
				bit = data_[i] & 1 << j ? 1 : 0;
				std::cout << bit << " ";
			}
			std::cout << std::endl;
		}
	else
		throw std::logic_error("Exception: Pointer points to NULL");
}
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Proxy class (for Vector <bool>)
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
class Vector<bool>::Proxy
{
public:
	Proxy(Vector<bool> * v, int index)
		: data_pointer_(v->data_), index_(index)
	{};
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Overrides of operator =
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	Proxy& operator= (Proxy that)
	{
		std::cout << __FUNCTION__ << " (type is Proxy)" << std::endl;
		bool byte[8] = {};
		bool bit = 0;
		for (int i = 0; i < 8; ++i)
		{
			bit = data_pointer_[index_ / 8] & 1 << i ? 1 : 0;
			byte[i] = bit;
			std::cout << byte[i] << " ";
		}
		std::cout << std::endl;
		bit = that.data_pointer_[that.index_ / 8] & 1 << (that.index_ % 8) ? 1 : 0;
		byte[index_ % 8] = bit;
		double res = 0;
		for (int i = 0; i < 8; ++i)
		{
			if (byte[i])
			{
				res += pow(2, (double)i);
			}
		}
		data_pointer_[index_ / 8] = (unsigned char) res;
		return *this;
	}
	Proxy& operator=(bool value)
	{
		std::cout << __FUNCTION__ << " (type is bool)" << std::endl;
		bool byte[8] = {};
		bool bit = 0;
		for (int i = 0; i < 8; ++i)
		{
			bit = data_pointer_[index_ / 8] & 1 << i ? 1 : 0;
			byte[i] = bit; 
			std::cout << byte[i] << " "; 
		}
		std::cout << std::endl;
		byte[index_ % 8] = value;
		double res = 0;
		for (int i = 0; i < 8; ++i)
		{
			if (byte[i])
			{
				res += pow(2, (double)i);
			}
		}
		data_pointer_[index_ / 8] = (unsigned char) res;
		return *this;
	}
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Override of operator bool
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	operator bool()
	{
		std::cout << __FUNCTION__ << std::endl;
		return (data_pointer_[index_ / 8] & (1 << (index_ % 8))) ? 1 : 0;
	}
private:
	unsigned char * data_pointer_;
	int index_;
};

typename Vector<bool>::Proxy Vector<bool>::operator [](int index)
{
	std::cout << std::endl << __FUNCTION__ << std::endl;
	Vector<bool>::Proxy pr(this, index);
	return pr;
}

