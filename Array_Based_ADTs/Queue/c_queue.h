#pragma once


//Array based implentation of Queue  (circular queue)
// circular queue is a logical theory based concept


template<typename T>
class queue
{
	private:
		T* data;
		int n, F, R, SIZE;
	public:
		queue(int s = 100)
		{
			this->SIZE = s+1; // this indicates circular property of queue as leaving a space in queue
			this->data = new T [SIZE];
			this->n = 0;
			this->F = this->R = 0;
		}

		void push(const T& val)
		{
			this->data[R] = val;
			this->R = (this->R + 1) % this->SIZE; // for circular traversal
			++this->n;
		}

		void pop()
		{
			if (empty())
			{
				throw("queue underflow!");
			}

			this->F = (this->F + 1) % this->SIZE;
			--this->n;
		}

		T front()const
		{
			if (empty())
			{
				throw("Queue Underflow!");
			}

			return this->data[F];
		}

		T back()const
		{
			if (empty())
			{
				throw("Queue Undeflow!");
			}

			if (this->R == 0)
			{
				return this->data[this->SIZE - 1];
			}
			else
			{
				return this->data[this->R - 1];
			}
		}

		bool empty()const
		{
			return this->n == 0;
			//return this->F == this->R;
		}

		int size()const
		{
			return this->n;
		}

		bool full()const
		{
			return this->n == (this->SIZE - 1);
			// return (R+1)%SIZE == F;
		}
};