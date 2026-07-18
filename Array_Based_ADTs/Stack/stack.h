#pragma once

//Array Based Implementation of stack

template<typename T>
class stack {
private:
	T* data;
	int TOP,SIZE, n;
public:
	stack(int s=100)
	{
		this->SIZE = s;
		this->data = new T[this->SIZE];
		this->TOP = -1;
		this->n = 0;
	}

	//Destructor: 
	~stack()
	{
		delete this->data ;
	}

	//push function
	void push(const T& val)
	{
		++TOP;
		this->data[this->TOP] = val;
		++n;
	}

	//top function

	T top()const {
		if (TOP != -1)
		{
			return this->data[this->TOP];
		}
		else
		{
			throw("Stack Underflow!");
		}
			
	}

	//size function
	int size() const {
		return n;
	}
	 
	//empty function
	bool empty()const {
		return n == 0;
	}

	//pop function
	void pop()
	{
		--TOP;
		--n;
	}

	//Extra function:
	bool full()const {
		return n == SIZE;
	}


};