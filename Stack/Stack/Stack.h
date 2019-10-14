#include<iostream>

using namespace std;
template<class T>
class Stack
{
private:
	int top;
	int size;
	T *element;


public:
	Stack() {
		top = -1;
		size = 0;
		element = T[16];
	}

	Stack(int length) {
		top = -1;
		size = 0;
		element = T[length];
	}
	~Stack() { delete[] element; }

	bool isEmpty() {
		if (top < 1) {
			return true;
		}
		else return false;
	}

	bool isFull() {
		if (top == (size -1) && size > 0) {
			return true;
		}
		else
		{
			return false;
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
			return false;
		}
		top++;
		element[top] = x;
		return true;
	}

	T pop() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return NULL;
		}
		int tmp = element[top];
		element[top] = 0;
		top--;
		return tmp;

	}


};