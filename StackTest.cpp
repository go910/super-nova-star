#include <string>
#include "Stack.h" 
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file StackTest.cpp
//! Implements tests of stack class methods
//!
//! @author Den, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to test
//! @param what is the object to test
//! @param case is what test to run
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
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
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to check a condition and exit if it failes
//! @param Condition to be checked
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#define ASSERT_EQ(condition) \
if (!(condition)) \
{ \
	s.dump(); \
	std::cout << "Test " << CurrentTest << " failed!" << std::endl; \
	assert(! #condition); \
}

std::string CurrentTest = "", CurrentTestingSet = "";

int main()
{
	TEST(Stack, PushSingleNumber)
	{
		Stack s;
		s.push(100);
		ASSERT_EQ(s.pop() == 100);
		ASSERT_EQ(s.size() == 0);
	}

	TEST(Stack, CannotPushMore)
	{
		Stack s;
		for (size_t i = 0; i < s.capacity(); i++)
			s.push(i + 1);
		ASSERT_EQ(s.push(100) == false);
	}

	TEST(Stack, IsStackEmpty)
	{
		Stack s;
		if (s.empty())
			s.push(100);
		ASSERT_EQ(s.empty() == false);
	}

	TEST(Stack, TopTest)
	{
		Stack s;
		s.push(10);
		s.push(20);
		s.push(30);
		ASSERT_EQ(s.top() == 30);
	}
	std::cout << "[" << CurrentTestingSet << "] " << CurrentTest << " finished successfully!" << std::endl;
}

