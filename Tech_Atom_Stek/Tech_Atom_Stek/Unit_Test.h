#pragma once
void Unit_Test_Stack()
{
	Stek stack; bool return_stack_push;
	Stek::Stek_type return_stack_pop;
	
	int k = 3;
	//�������� �� ���������� ��������
	for (int i = 0; i < k; i++)
	{
		return_stack_push = stack.push(i);
	}
	
	if (stack.get_size() == 3)
		cout << "OK";
	else
		cout << "ERROR";

	cout << endl;

	//�������� �� ������� �������
	if(stack.top()==2)
		cout << "OK";
	else
		cout << "ERROR";

	cout << endl;

	//�������� �� �������� ��������
	for (int i = 0; i < k; i++)
	{
		return_stack_pop = stack.pop();

	}

	if (stack.get_size() == 0)
		cout << "OK";
	else
		cout << "ERROR";

	cout << endl;




}