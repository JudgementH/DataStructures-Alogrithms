#include<iostream>
#include<stdlib.h>
using namespace std;

void fun(int a[], int k, int n) {
	if (k == n) {
		//µ›πÈ÷’µ„
		for (int i = 0; i < n; i++) {
			cout << a[i];
			if (i == n - 1) {
				cout << endl;
			}
			else
			{
				cout << ",";
			}
		}
	}
	else {
		int tmp;
		for (int i = k; i < n; i++) {
			tmp = a[k];
			a[k] = a[i];
			a[i] = tmp;

			int k2 = k + 1;
			fun(a, k2, n);


			tmp = a[k];
			a[k] = a[i];
			a[i] = tmp;
		}
	}
}

int main() {
	cout << "Input" << endl;
	int n = 0;
	int a[20];
	for (int i = 0; i < 20; i++) {
		int tmp;
		cin >> tmp;
		if (tmp) {
			n++;
			a[i] = tmp;
		}
		else
		{
			break;
		}
	}

	cout << "Output" << endl;
	fun(a, 0, n);
	cout << "end" << endl;

	system("pause");
}