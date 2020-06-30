#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Stack
{
private:
	T* stackPtr;
	const int size;
	int top;
public:
	Stack(int = 10);
	Stack(const Stack<T>&);
	~Stack();
	void push(const T&);
	T pop();
	void print_stack();
	const T& peek(int) const;
	int get_stack_size() const;
	T* getPtr() const;
	int get_top() const;
	bool is_empty() const;
	void clear();

	Stack<T> operator=(const Stack& other);

	template<typename Type>
	friend ostream& operator<<(ostream& stream, const Stack<Type>& orig);

};

template<typename Type>
ostream& operator <<(ostream& stream, const Stack<Type>& orig)
{
	if (orig.size)
		for (int i = orig.top - 1; i >= 0; i--)
			cout << "|" << orig.stackPtr[i] << endl;

	return stream;
}

#include"stack.cpp"



