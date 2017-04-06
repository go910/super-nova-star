#include <iostream>
#include <string>
#include "Vector.h"
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file VectorTest.cpp
//! Unit-tests for Vector class
//!
//! @author Denis & Ilya, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

std::string CurrentTest = "", CurrentTestingSet = "";

#define TEST(NameOfTestingSet, NameOfTest) \
	if (CurrentTest == "" || CurrentTestingSet == "") \
	{ \
		CurrentTest = #NameOfTest; \
		CurrentTestingSet = #NameOfTestingSet; \
	} \
	else if (CurrentTest != #NameOfTest || CurrentTestingSet != #NameOfTestingSet) \
	{ \
		std::cout << "[" << CurrentTestingSet << "] " << CurrentTest << " finished successfully!" << std::endl; \
		CurrentTest = #NameOfTest; \
		CurrentTestingSet = #NameOfTestingSet; \
	} \

#define ASSERT_EQ(condition) \
	if (!(condition)) \
	{ \
		v.dump(); \
		std::cout << "Test " << CurrentTest << " failed!" << std::endl; \
		assert(! #condition); \
	}

int main()
{
	TEST(Vector, Push&PopBackTest)
	{
		Vector <double> v;
		v.push_back(100);
		v.push_back(200);
		ASSERT_EQ(v.at(0) == 100 && v.at(1) == 200);
		v.pop_back();
		v.pop_back();
		ASSERT_EQ(v.size() == 0);
	}
	TEST(Vector, ClearCopyConstructorTest)
	{
		Vector <double> w;
		w.push_back(10);
		w.push_back(10);
		w.push_back(10);
		Vector <double> v(w);
		ASSERT_EQ(v == w);
	}
	TEST(Vector, ImplicitCopyConstructorTest)
	{
		Vector <double> w;
		w.push_back(10);
		w.push_back(10);
		w.push_back(10);
		Vector <double>  v = w;
		ASSERT_EQ(v == w);
	}
	TEST(Vector, AppropriationTest)
	{
		Vector <double> w;
		w.push_back(10);
		w.push_back(10);
		w.push_back(10);
		Vector <double> x = w;
		Vector <double> v(w);
		v = x;
		ASSERT_EQ(v == x);
	}
TEST(Vector, IteratorOnFirstElementTest)
	{
		Vector <double> v;
		v.push_back(100);
		ASSERT_EQ(v[v.begin()] == 100);
	}
TEST(Vector, IteratorOnLastElementTest)
	{
		Vector <double> v(2);
		v.push_back(100);
		v.push_back(200);
		//for (Vector<double>::IteratorForVector it = v.begin(); it != v.end(); ++it)
		//	std::cout << v[it] << std::endl;
		ASSERT_EQ(v[v.end() - 1] == 200);
	}
TEST(Vector, VectorIsEmptyTest)
	{
		Vector <double> v;
		ASSERT_EQ(v.empty());
	}
TEST(Vector, Front&BackTest)
	{
		Vector <double> v;
		v.push_back(10);
		v.push_back(10);
		v.push_back(10);
		v.front() = 0;
		v.back() = 0;
		ASSERT_EQ(v[v.begin()] == 0);
		ASSERT_EQ(v[v.end() - 1] == 0);
	}
TEST(Vector, AtTest)
	{
		Vector <double> v;
		v.push_back(10);
		v.push_back(10);
		ASSERT_EQ(v.at(1) == 10);
	}
	std::cout << "[" << CurrentTestingSet << "] " << CurrentTest << " finished successfully!" << std::endl;
	return 0;
}
