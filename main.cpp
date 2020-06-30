#include <iostream>
#include<string>
using namespace std;

#include "stack.h"

int main()
{
	setlocale(LC_ALL, "");
	Stack<int> stack(5);
	int cs = 0;
	int stack_elem;

	cout << "¬ведiть стек з цифр." << endl;

	while (cs++ < 5)
	{
		cin >> stack_elem;
		stack.push(stack_elem);
	}
	cout << "=================" << endl;
	cout << stack << endl;




	return 0;
}