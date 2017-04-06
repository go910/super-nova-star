#pragma once
#include <cassert>
#include <string>
#include <iostream>

std::string CurrentTest = "", CurrentTestingSet = "";
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to test
//! @param What is the object to test
//! @param Case is what test to run
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
} 
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to check a condition and exit if it failes
//! @param Condition to be checked
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#define ASSERT_EQ(condition) \
if (!(condition)) \
{ \
	x.dump(); \
	std::cout << "Test " << CurrentTest << " failed!" << std::endl; \
	assert(! #condition); \
}
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to check a condition of container
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#define ASSERT_OK() \
if (!ok()) \
{ \
	dump(); \
	throw std::logic_error("Container in wrong condition!"); \
}
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Macro to make printout
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#define PRINTOUT() \
{ \
	std::cout << __FUNCSIG__ << std::endl; \
	dump(); \
}
