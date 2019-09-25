#include <iostream>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;


void f(int *p, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << p[i*col + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main() {
	int array[][3] = {1,2,3,4,5,6,7,8,9};
	
	Matrix<int> matrix((int*)array,3,3);
	cout << matrix;



	system("pause");
}