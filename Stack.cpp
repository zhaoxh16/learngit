#include "Stack.h"
template<typename T> void Stack<T>::_expand()
{
	T *B = _A;
	_maxSize *= 2;
	_A = new T[_maxSize];
	for (int i = 0; i < _size; i++)
		_A[i] = B[i];
	delete[] B;
}

template<typename T> Stack<T>::Stack(const int n) :
	_size(0), _maxSize(n), _A(new T[_maxSize])
{
	cout << "	执行构造函数" << endl;
}

template<typename T> Stack<T>::Stack(const Stack<T>& otherStack) :
	_maxSize(otherStack._maxSize), _size(otherStack._size), _A(new T[_maxSize])
{
	for (int i = 0; i < _size; i++)
		_A[i] = otherStack._A[i];
	cout << "	执行拷贝构造函数" << endl;
}

template<typename T> Stack<T>::Stack(Stack<T>&& otherStack) :
	_size(otherStack._size), _maxSize(otherStack._maxSize), _A(otherStack._A)
{
	otherStack._A = nullptr;
	cout << "	执行移动构造函数" << endl;
}

template<typename T> Stack<T>::~Stack()
{
	cout << "	执行析构函数" << endl;
	delete[] _A;
}

template<typename T> T Stack<T>::push(const T a)
{
	if (full()) _expand();
	_A[_size] = a;
	++_size;
	return a;
}

template<typename T> T Stack<T>::pop()
{
	try
	{
		if (_size == 0)
			throw out_of_range("栈为空");
		else
		{
			T b = _A[_size - 1];
			_size--;
			return b;
		}
	}
	catch (out_of_range& oor)
	{
		cerr << "Out of range error: " << oor.what() << " Line: " << __LINE__ << " File: " << __FILE__ << endl;
	}
}

template<typename T> T& Stack<T>::operator[](const int k)
{
	try
	{
		if (k < 0 || k >= _size)
			throw out_of_range("越界访问");
		return _A[k];
	}
	catch (out_of_range& oor)
	{
		cerr << "Out of range error: " << oor.what() << " Line: " << __LINE__ << " File: " << __FILE__ << endl;
	}
}

template<typename T> Stack<T>& Stack<T>::operator= (const Stack<T>& otherStack)
{
	cout << "	执行赋值运算符" << endl;
	if (this == &otherStack)
		return *this;
	else
	{
		T *B = _A;
		_maxSize = otherStack._maxSize;
		_A = new T[_maxSize];
		_size = otherStack._size;
		for (int i = 0; i < _size; i++)
			_A[i] = otherStack._A[i];
		delete[] B;
		return *this;
	}
}

template<typename T> Stack<T>& Stack<T>::operator= (Stack<T>&& otherStack)
{
	cout << "	执行移动赋值运算符" << endl;
	_size = otherStack._size;
	_maxSize = otherStack._maxSize;
	delete[] _A;
	_A = otherStack._A;
	otherStack._A = nullptr;
	return *this;
}

template<typename T> bool Stack<T>::operator== (const Stack<T>& otherStack)const
{
	if (_size != otherStack._size)
		return false;
	else if (_maxSize != otherStack._maxSize)
		return false;
	else
	{
		for (int i = 0; i < _size; i++)
			if (_A[i] != otherStack._A[i])
				return false;
		return true;
	}
}

template <typename T> bool Stack<T>::empty()const
{
	return !_size;
}

template <typename T> bool Stack<T>::full()const
{
	return _size == _maxSize;
}

template<typename T> int Stack<T>::size()const
{
	return _size;
}

template<typename T> int Stack<T>::maxSize()const
{
	return _maxSize;
}

template<typename T> bool Stack<T>::expand(const int n)
{
	if (n <= _maxSize)
		return false;
	else
	{
		T *B = _A;
		_maxSize = n;
		_A = new T[_maxSize];
		for (int i = 0; i < _size; i++)
			_A[i] = B[i];
		delete[] B;
		return true;
	}
}

template<typename T> bool Stack<T>::shrink(const int n)
{
	if (n >= _maxSize)
		return false;
	else
	{
		if (_size > n)
		{
			cerr << "Warning: Shrink操作中会有数据丢失" << " Line: " << __LINE__ << " File: " << __FILE__ << endl;
			_size = n;
		}
		T *B = _A;
		_maxSize = n;
		_A = new T[_maxSize];
		for (int i = 0; i < _size&&i < _maxSize; i++)
			_A[i] = B[i];
		delete[] B;
		return true;
	}
}

template<typename T> T Stack<T>::get()const
{
	try
	{
		if (_size == 0)
			throw out_of_range("栈为空");
		return _A[_size - 1];
	}
	catch (out_of_range& oor)
	{
		cerr << "Out of range error: " << oor.what() << " Line: " << __LINE__ << " File: " << __FILE__ << endl;
	}
}

template<typename T> T Stack<T>::get(const int k)const
{
	try
	{
		if (k < 0 || k >= _size)
			throw out_of_range("越界访问");
		return _A[k];
	}
	catch (out_of_range& oor)
	{
		cerr << "Out of range error: " << oor.what() << " Line: " << __LINE__ << " File: " << __FILE__ << endl;
	}
}

template<typename T> void Stack<T>::clear()
{
	_size = 0;
}

template<typename T> bool Stack<T>::copyFrom(const Stack<T>& otherStack, const int length, const int myHead, const int otherHead)
{
	try
	{
		if (myHead > _size || myHead < 0 || otherHead<0 || otherHead + length>otherStack.size())
			throw out_of_range("越界访问");
		if (this == &otherStack)//如果自赋值，则返回false
			return false;
		else if (_maxSize - myHead < length)//如果栈中无法装下则扩容至myHead+2*length
			expand(myHead + 2 * length);
		for (int i = 0; i < length; i++)//执行拷贝操作，返回true
			_A[myHead + i] = otherStack._A[otherHead + i];
		_size = myHead + length;
		return true;
	}
	catch (out_of_range& oor)
	{
		cerr << "Out of range error: " << oor.what() << " Line: " << __LINE__ << " File: " << __FILE__ << endl;
	}
}

template<typename T> int Stack<T>::find(const T& a)const
{
	for (int i = 0; i < _size; i++)
		if (_A[i] == a)
			return i;
	return -1;
}

template<typename T> int Stack<T>::find(const T& a, const int head, const int tail)const
{
	try
	{
		if (head<0 || head >= _size || tail <= 0 || tail>_size)
			throw out_of_range("查找范围不合法");
		else
		{
			for (int i = head; i < tail; i++)
				if (_A[i] == a)
					return i;
			return -1;
		}
	}
	catch (out_of_range& oor)
	{
		cerr << "Out of range error: " << oor.what() << " Line: " << __LINE__ << " File: " << __FILE__ << endl;
	}
}




