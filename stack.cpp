#ifndef STACK_CPP
#define STACK_CPP


#include"stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize)
{
	stackPtr = new T[size];
	top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :
	size(otherStack.size) {
	stackPtr = new T[size];
	top = otherStack.top;

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.stackPtr[ix];
}

template <typename T>
Stack<T>::~Stack()
{
	clear();
	delete[] stackPtr;
}

template <typename T>
inline void Stack<T>::push(const T& value)
{
	assert(top < size);

	stackPtr[top++] = value;
}

template <typename T>
T Stack<T>::pop()
{
	assert(top > 0);

	return stackPtr[--top];
}

template <class T>
const T& Stack<T>::peek(int n) const
{
	assert(n <= top);

	return stackPtr[top - n];
}

template <typename T>
void Stack<T>::print_stack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << stackPtr[ix] << endl;
}

template <typename T>
int Stack<T>::get_stack_size() const
{
	return size;
}

template <typename T>
T* Stack<T>::getPtr() const
{
	return stackPtr;
}

template <typename T>
int Stack<T>::get_top() const
{
	return top;
}

template<typename T>
bool Stack<T>::is_empty() const
{
	return !top;
}

template<typename T>
void Stack<T>::clear()
{
	while (top > 0)
	{
		pop();
	}

}

template<class T>
Stack<T> Stack<T>::operator=(const Stack& other)
{
	if (this->stackPtr != nullptr)
		delete[] stackPtr;
	this->stackPtr = new T[other.size];
	for (int i = 0; i < other.size; i++)
		this->stackPtr[i] = other.stackPtr[i];
	return *this;
}




#endif
