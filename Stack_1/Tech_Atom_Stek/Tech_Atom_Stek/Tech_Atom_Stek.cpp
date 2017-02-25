// Tech_Atom_Stek.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include<stack>
#include <iostream>	
#include <string>
using namespace std;


class Stek
{
public:
	typedef double  Stek_type;
	Stek();
	Stek_type top();
	Stek_type pop();
	bool push(Stek_type elem_stek);
	size_t get_size();
	bool empty_test();
	Stek_type get_capacity();
	~Stek();
	bool ok() const;//верифекатор
	bool dump() const;
	void ASSERT_OK();
private:
	size_t size;
	static const size_t capacity=10;
	Stek_type Array_data[capacity];
	//const size_t  POISON_INT = 100;

};


//верификатор
bool Stek::ok() const
{
	return(size <= capacity);
}

bool Stek::dump() const
{
	cout << "Stack()";
	cout << endl;
	cout << "     {";
	cout << endl;
	cout << "     size =";
	cout << size;
	cout << endl;
	cout << "     capacity =";
	cout << capacity;
	cout << endl;
	cout << endl;
	cout << "     data[";
	cout << capacity;
	cout << "]";
	cout << endl;
	cout << "        {";
	cout << endl;
	for (int i = 0; i < capacity; i++)
	{
		if (i < size)
		{
			
			cout << "*";
			cout << "[";
			cout << i;
			cout << "] =";
			cout << Array_data[i];
			cout << endl;
		}
		else
		{
			cout << " [";
			cout << i;
			cout << "] =";
			cout << Array_data[i];
			cout << " ";
			cout << "POISON_INT";
			cout << endl;
		}
	}
	cout << "        }";
	cout << endl;
	cout << "     }";
	return true;
}






bool Stek::empty_test()
{
	if (size == 0)
		return false;	
	else
		return true;
	
}

size_t Stek::get_size()
{
	return size;
}


Stek::Stek_type Stek::get_capacity()
{
	return capacity;
}


/*#define ASSERT_OK()   †           \
if†(!ok())                      \
{                               \
	dump();                     \
	assert†(!УObject†is†OKФ);   \
}                          \
*/
void Stek::ASSERT_OK()
{
	if(! ok())                      
	{                               
		dump();                     
 		//assert †(! УObject†is†OKФ);   
	}
}


Stek::Stek_type Stek::pop()
{
	ASSERT_OK();
	if (empty_test())
	{
		size = size - 1;
		ASSERT_OK();
		return Array_data[size];
	}	
	else
	{
		throw string("stek is empty");
	}
}



bool Stek::push(Stek_type new_elem_stek)
{
	ASSERT_OK();
	if (size >= capacity )
	return false;
	else
	{
		Array_data[size++] = new_elem_stek;
		ASSERT_OK();
		return true;
	}
	
}




Stek::Stek_type Stek::top()
{
	ASSERT_OK();
	if(empty_test())
	return Array_data[size-1];
	else
	{
		throw string("stek is empty");
	}
}


Stek::~Stek()
{

}


Stek::Stek() :size(0)
{

	for (int i = 0; i < capacity; i++)
	{
		Array_data[i] = 0;
	}
}

     





int main()
{
	Stek s; bool k;
    k=s.push(10);
	k = s.push(20);
	k = s.push(30);
	k = s.dump(); 
	/*size_t x = s.get_size();
	cout << x;
	Stek::Stek_type t;
	try {
		cout << s.pop();
	}
	catch (string error)
	{
		cout << error;
	}*/
	int p;

	cin >> p;
	
    return 0;
}

