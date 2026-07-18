#pragma once

//Linked List Based Implementation

#include "node.h"

template<typename T>
class stack{
private:
	node<T>* TOP;
	int n;

	template<typename U>
	friend bool operator==(const stack<U>& s1, const stack<U>& s2);

	template<typename U>
	friend bool operator!=(const stack<U>& s1, const stack<U>& s2);

	template<typename U>
	friend bool operator<(const stack<U>& s1, const stack<U>& s2);
public:

	stack()
	{
		this->TOP = nullptr;
		n = 0;
	}

	stack<T>& operator=(const stack<T>& other)
	{
		node<T>* temp;
		this->TOP = nullptr;
		temp = other->TOP;
		while (temp != nullptr)
		{
			this->push(temp->val);
			temp = temp->next;
		}

		return *this;
	}

	// copy constructor
	stack(const stack<T>& rhs)
	{
		this->TOP = nullptr;
		this->operator=(rhs);
		n = 0;
	}

	~stack()
	{
		while (TOP != nullptr)
		{
			node<T>* temp;
			temp = TOP;
			TOP = temp->next;
			delete temp;
		}
	}

	void push(const T& v)
	{
		node<T>* ptr;
		ptr = new node<T>;
		ptr->val=v;
		ptr->next = TOP;
		TOP = ptr;
		++n;
	}

	void pop()
	{
		node<T>* temp;
		temp = TOP;
		TOP = temp->next;
		delete temp;
		--n;
	}

	T top()const {
		if (TOP == nullptr)
		{
			throw("Stack Underflow!");
		}

		return TOP->val;
	}

	int size()const {
		return n;
	}

	bool empty() const
	{
		return n == 0;
	}

	bool full() const {
		node<T>* temp;
		temp = new node<T>;
		if (temp == nullptr)
		{
			return true;
		}
		else
		{
			delete temp;
			return false;
		}
	}

	// clear function to clear/overwrite existing contents of stack
	void clear()
	{
		while (!empty())
		{
			pop();
		}
	}

};

 //Non-Member Functions
template<typename T>
bool operator==(const stack<T>& s1,const stack<T>& s2)
{
	if (s1.size() != s2.size())
	{
		return false;
	}
	node<T>* st1, *st2;
	st1 = s1.TOP;
	st2 = s2.TOP;
	while (st1!=nullptr && st2!=nullptr)
	{
		//comparing if current values are equal (top values)
		if (st1->val == st2->val)
		{
			st1 = st1->next;
			st2 = st2->next;
		}
		else
		{
			return false;
		}
	}

	return true;
}

template<typename T>
bool operator!=(const stack<T>& s1, const stack<T>& s2)
{
	//opposite of '==' so already implemented
	return !(s1 == s2);
}

template<typename T>
bool operator<(const stack<T>& s1, const stack<T>& s2)
{
	node<T>* st1, * st2;
	st1 = s1.TOP;
	st2 = s2.TOP;
	while (st1 != nullptr && st2 != nullptr)
	{
		if (st1->val < st2->val)
		{
			return true;
		}
		else if (st1->val == st2->val)
		{
			st1 = st1->next;
			st2 = st2->next;
		}
		else
		{
			return false;
		}
	}

	return s1.size() < s2.size();
}




