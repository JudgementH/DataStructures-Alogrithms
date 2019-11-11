#include<iostream>
#include<stdlib.h>
#include"Stack.h"

using namespace std;

int main() {

	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	for (int i = 0; i < 4;i++) {
		cout << stack.pop() << endl;
	}
	
	system("pause");
}