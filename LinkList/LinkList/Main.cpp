#include <iostream>
#include <stdlib.h>
#include "Chain.h"

using namespace std;

int main() {
	cout << "Hello World!" << endl;
	Chain<int> chain;
	chain.insert(0, 1);
	chain.insert(0, 2);
	chain.insert(0, 3);
	chain.insert(0, 4);
	chain.insert(0, 5);
	chain.insert(3,9);

	cout << chain << endl;

	chain.remove(0);
	chain.remove(0);
	chain.remove(0);
	chain.remove(1);

	cout << chain << endl;

	system("pause");
}