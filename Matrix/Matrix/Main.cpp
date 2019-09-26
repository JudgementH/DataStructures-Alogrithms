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

	int array2[][3] = { 1,2,3,4,5,6,7,8,9 };
	Matrix<int> m1((int*)array2, 3, 3);
	Matrix<int> m2((int*)array2, 3, 3);
	Matrix<int> m3 = m1 - m2;
	cout << m3 << endl;

	Matrix<int> m4 = m1 * m2;
	cout << m4;
	
	system("pause");
}