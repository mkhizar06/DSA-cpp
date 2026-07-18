#pragma once

#include"node.h"

template<typename T>
class queue
{
	private:
		node<T>* F, * R;
		int n;
	public:
		//simple constructor
		queue()
		{
			this->n = 0;
			this->F = this->R = nullptr;
		}

		//copy constructor
		queue(const queue<T>& other)
		{
			this->F = this->R = nullptr;
			//if already implemented the '=' operator then
			this->operator=(other);
			//temp = other.F;
			//while (temp != nullptr)
			//{
			//	this->push(temp->val);
			//	temp = temp->next;
			//}
			
			

		}

		//Assignment operator
		queue<T>& operator=(const queue<T>& other)
		{
			node<T>* temp;
			this->F = this->R = nullptr;
			temp = other.F;
			while (temp != nullptr)
			{
				this->push(temp->val);
				temp = temp->next;
			}

			return *this;
		}


		//destructor
		~queue()
		{
			while (!empty())
			{
				pop();
			}
		}

		void push(const T& v)
		{
			node<T>* nn;
			nn = new node<T>;
			nn->val = v;
			nn->next = nn;
			if (this->F == nullptr)
			{
				this->F = nn;
			}
			else
			{
				this->R->next = nn;
			}
			this->R = nn;

			++this->n;
		}

		void pop()
		{
			if (this->F == nullptr && this->R == nullptr)
			{
				throw("Queue underflow!");
			}
			node<T>* temp;
			temp = this->F;
			this->F = this->F->next;
			if (this->F == nullptr)
			{
				this->R = nullptr;
			}

			delete temp;

			--this->n;

		}

		T front() const
		{
			if (empty())
			{
				throw("Queue Underflow!");
			}

			return this->F->val;
		}

		T back() const
		{
			if (empty())
			{
				throw("Queue Underflow!");
			}

			return this->R->val;
		}

		int size()const
		{
			return this->n;
		}

		bool empty()const
		{
			return this->n == 0;
			//this->F == nullptr;
			//this->R == nullptr;
			//or both F & R == nullptr;
		}


		template<typename U>
		friend bool operator==(const queue<U>& q1, const queue<U>& q2);

		template<typename U>
		friend bool operator!=(const queue<U>& q1, const queue<U>& q2);

		template<typename U>
		friend bool operator<(const queue<U>& q1, const queue<U>& q2);

};

template<typename U>
bool operator==(const queue<U>& q1, const queue<U>& q2)
{
	node<U>* ptr_q1, * ptr_q2;
	ptr_q1 = q1.F;
	ptr_q2 = q2.F;
	while (ptr_q1 != nullptr && ptr_q2 != nullptr)
	{
		if (ptr_q1->val == ptr_q2->val)
		{
			ptr_q1 = ptr_q1->next;
			ptr_q2 = ptr_q2->next;
		}
		else
		{
			return false;
		}
	}

	return true;
}

template<typename U>
bool operator!=(const queue<U>& q1, const queue<U>& q2)
{
	return !(q1 == q2);
}

template<typename U>
bool operator<(const queue<U>& q1, const queue<U>& q2)
{
	if (q1.size() != q2.size())
	{
		return false;
	}
	node<U>* ptr_q1, * ptr_q2;
	ptr_q1 = q1.F;
	ptr_q2 = q2.F;
	while (ptr_q1 != nullptr && ptr_q2 != nullptr)
	{
		if (ptr_q1->val < ptr_q2->val)
		{
			return true;
		}
		else if(ptr_q1->val == ptr_q2->val)
		{
			ptr_q1 = ptr_q1->next;
			ptr_q2 = ptr_q2->next;
		}
		else
		{
			return false;
		}
	}

	return false;
}