#include <stdlib.h>
#include <iostream>

using namespace std;

inline void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

inline void printArr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i];
		if (i == len - 1) {
			cout << endl;
		}
		else
		{
			cout << ",";
		}
	}
}

void bubbleSort(int * arr,int len) {
	for (int i = 0; i < len;  i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j],arr[j+1]);
			}
		}
	}


	printArr(arr, len);
}

void insertSort(int *arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j > 0;j--) {
			if (arr[j] < arr[j -1]) {
				swap(arr[j],arr[j - 1]);
			}
		}
	}


	printArr(arr, len);
}

void radixSort(int *arr, int len) {
	int max = arr[0];
	for(int i = 0; i < len;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	int d = 0;
	while (max > 0 ) {
		d++;
		max = max / 10;
	}

	if (d > 1 ) {
		cout << 0 << endl;
	}
	else {
	int count[10];
	int rank[10];
	int* tmp = new int[len];
	int radix = 1;
	int k;
	for (int i = 0; i < d;i++) {
		for (int j = 0; j < 10;j++) {
			count[j] = 0;
		}

		for (int j = 0; j < len; j++) {
			k = (arr[j] / radix) % 10;
			count[k]++;
		}

		rank[0] = 0;
		for (int j = 1; j < 10; j++) {
			rank[j] = rank[j - 1] + count[j-1];
		}

		for (int j = 0; j < len; j++) {
			k = (arr[j] / radix) % 10;
			tmp[rank[k]] = arr[j];
			rank[k]++;
		}

		for (int j = 0; j < len; j++) {
			arr[j] = tmp[j];
		}
		radix = radix * 10;
	}
	printArr(arr,len);
	}
	
}

int main() {

	cout << "Input" << endl;
	int len = 0;
	int arr[20];
	for (int i = 0; i < 20; i++) {
		int tmp;
		cin >> tmp;
		if (tmp) {
			len++;
			arr[i] = tmp;
		}
		else
		{
			break;
		}
	}

	cout << "1-Bubble Sort,2-Insert Sort,3-Radix Sort" << endl;
	int c = 0;
	cin >> c;

	cout << "Output" << endl;
	switch (c)
	{
	case 1:
		cout << "Bubble Sort" << endl;
		bubbleSort(arr,len);
		break;
	case 2:
		cout << "Insert Sort" << endl;
		insertSort(arr,len);
		break;
	case 3:
		cout << "Radix Sort" << endl;
		radixSort(arr,len);
		break;
	default:
		break;
	}
	
	cout << "End"<<endl;
	system("pause");
	return 0;
}