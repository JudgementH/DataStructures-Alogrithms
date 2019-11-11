#include<iostream>

using namespace std;
template<class T>
class Stack
{
private:
	int top;
	int size;
	int length;
	T *element;


public:
	Stack(int length = 16) {
		top = -1;
		size = 0;
		this->length = length;
		element = new T[length];
	}
	~Stack() { delete[] element; }

	bool isEmpty() {
		if (top < 0 ) {
			return true;
		}
		else return false;
	}

	bool isFull() {
		if (length == size && size > 0) {
			return true;
		}
		else
		{
			return false;
		}
	}

	void expansion() {
		if (isFull()) {
			T *tmp = new T[2 * length];
			for (int i = 0; i < length; i++) {
				tmp[i] = element[i];
			}
			delete[] element;
			element = tmp;
			length = length * 2;
		}
	}

	T getTop() { 
		if (!isEmpty()) {
			return element[top];
		}
		else
		{
			cout << "stack is empty" << endl;
			return 0;
		}
	}

	bool push(T x) {
		if (isFull()) {
			cout << "stcak is full!" << endl;
			expansion();
		}
		top++;
		size++;
		element[top] = x;
		return true;
	}

	T pop() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return NULL;
		}
		T tmp = element[top];
		element[top] = 0;
		top--;
		size--;
		return tmp;

	}
};