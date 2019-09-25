#include <iostream>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;


int main() {
	int array[][3] = {1,2,3,4,5,6,7,8,9};
	
	Matrix<int> matrix((int*)array,3,3);
	cout << matrix;

	cout << matrix(2, 2) << endl;
	cout << endl;
	
	matrix.transpose();
	cout << matrix;
	
	system("pause");
}