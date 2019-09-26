#include <iostream>
#include <stdlib.h>
#include "Matrix.h"
#include "TridiagonalMatrix.h"
using namespace std;


int main() {
	int array[][3] = {1,2,3,4,5,6,7,8,9};
	
	Matrix<int> matrix((int*)array,3,3);
	cout << matrix << endl;

	cout << matrix(2, 2) << endl;
	cout << endl;
	
	matrix.transpose();
	cout << matrix << endl;

	int array2[][3] = { 1,2,3,4,5,6,7,8,9 };
	Matrix<int> m1((int*)array2, 3, 3);
	Matrix<int> m2((int*)array2, 3, 3);
	Matrix<int> m3 = m1 - m2;
	cout << m3 << endl;

	Matrix<int> m4 = m1 * m2;
	cout << m4 << endl;;

	TridiagonalMatrix<int> tm(4);
	cout << tm << endl;

	tm.set(2, 1, 1);
	tm.set(1, 1, 2);
	tm.set(3, 2, 1);
	tm.set(1, 2, 2);
	tm.set(3, 2, 3);
	tm.set(5, 3, 2);
	tm.set(2, 3, 3);
	tm.set(7, 3, 4);
	tm.set(9, 4, 3);
	tm.set(0, 4, 4);

	cout << tm << endl;

	system("pause");
}