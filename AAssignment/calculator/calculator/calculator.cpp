#include <iostream>
#include <stdlib.h>
#include <string>


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
		if (top < 0) {
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
			return 0;
		}
	}

	bool push(T x) {
		if (isFull()) {
			expansion();
		}
		top++;
		size++;
		element[top] = x;
		return true;
	}

	T pop() {
		if (isEmpty()) {
			return NULL;
		}
		T tmp = element[top];
		element[top] = 0;
		top--;
		size--;
		return tmp;
	}
};

int main(){
	string s1;
	cout << "Input" << endl;
	cin >> s1;
	 
	//转化为后缀表达式
	string s2;
	Stack<char> stack;
	for (int i = 0; i < s1.length(); i++) {
		char tmp  = s1.at(i);
		if ((tmp > '0' && tmp <= '9')) {
			s2 += tmp;
		}
		if (tmp == '+' || tmp == '-' || tmp == '*' || tmp =='/' || tmp == '(' || tmp == ')') {
			if (stack.isEmpty()) {
				stack.push(tmp);
			}
			else
			{
				if (tmp == ')') {
					while (stack.getTop() != '(' ) {
						s2 += stack.pop();
					}
					stack.pop();
				}
				else if (tmp == '(') {
					stack.push(tmp);
				}
				else if (tmp == '+' || tmp == '-') {
					if (stack.getTop() == '*' || stack.getTop() == '/' || stack.getTop() == '+' || stack.getTop() == '-') {
						while (stack.getTop() == '*' || stack.getTop() == '/' || stack.getTop() == '+' || stack.getTop() == '-') {
							s2 += stack.pop();
						}
						stack.push(tmp);
					}
					else {
						stack.push(tmp);
					}
				}
				else if (tmp == '*' || tmp == '/') {
					stack.push(tmp);
				}
			}
		}
	}
	while (!stack.isEmpty())
	{
		s2 += stack.getTop();
		stack.pop();
	}


	//求解
	Stack<int> sk;
	for (int i = 0; i < s2.length(); i++) {
		char tmp = s2.at(i);
		if ((tmp > '0' && tmp <= '9')) {
			int num = tmp - '0';
			sk.push(num);
		}
		else if (tmp == '+') {
			int t1 = sk.pop();
			int t2 = sk.pop();

			int t3 = t1 + t2;
			sk.push(t3);
		}
		else if (tmp == '-') {
			int t1 = sk.pop();
			int t2 = sk.pop();

			int t3 = t2 - t1;
			sk.push(t3);
		}
		else if (tmp == '*') {
			int t1 = sk.pop();
			int t2 = sk.pop();

			int t3 = t1 * t2 ;
			sk.push(t3);
		}
		else if (tmp == '/') {
			int t1 = sk.pop();
			int t2 = sk.pop();

			int t3 = t2 / t1;
			sk.push(t3);
		}
	}


	cout << "Output"<<endl;
	cout << sk.pop()<<endl;

	cout << "End" << endl;

	
	system("pause");
}