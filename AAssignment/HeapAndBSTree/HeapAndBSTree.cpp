#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

template<class T>
class MaxHeap
{
public:
	MaxHeap(int maxHeapSize = 20):maxSize(maxHeapSize) {
		heap = new T[maxSize + 1];
		size = 0;
	}
	int getSize() const {
		return size;
	}

	T top() {
		if (size == 0) {
			return 0;
		}
		return heap[1];
	}

	MaxHeap<T>& push(const T& x) {
		if (size == maxSize) {
			return 0;
		}
		int i = size + 1;
		while (i!=1 && x > heap[i/2])
		{
			heap[i] = heap[i / 2];
			i = i / 2;
		}
		heap[i] = x;
		size++;
		return *this;
	}

	void pop() {
		if (size == 0) {
			return;
		}

		T last = heap[size];
		size--;

		T x = heap[1];
		int i = 1;
		int son = 2;
		while (son <= size)
		{
			if (son < size && heap[son] < heap[son + 1]) {
				son++;
			}
			if (last >= heap[son]) {
				break;
			}

			heap[i] = heap[son];
			i = son;
			son *= 2;
		}

		heap[i] = last;

		return;

	}

	void init(T a[], int size, int maxSize = 20) {
		delete[] heap;
		heap = a;
		this->size = size;
		this->maxSize = maxSize;

		for (int i = size / 2; i >= 1;i--) {
			int son = 2*i;

			T tmp = heap[i];
			while (son <= size)
			{
				if (son < size && heap[son] < heap[son + 1]) {
					son++;
				}

				if (tmp >= heap[son]) {
					break;
				}

				heap[son / 2] = heap[son];
				son *= 2;
			}

			heap[son / 2] = tmp;
		}
	}

	void out() {
		for (int i = 1; i <= size - 1;i++) {
			cout << heap[i] << ",";
		}
		cout << heap[size] << endl;
	}

private:
	int size, maxSize;
	T *heap;
};

template<class T>
class BSNode {
public:
	BSNode():leftChild(nullptr), rightChild(nullptr) {}
	BSNode(T value, BSNode<T> *left = nullptr, BSNode<T> *right = nullptr) :data(value), leftChild(left), rightChild(right){}

	BSNode<T> *leftChild, *rightChild;
	T data;
};

template<class T>
class BSTree {
public:
	BSTree(): root(nullptr),size(0) {
	}
	void push(T value) {
		BSNode<T> *p = root;
		if (root == nullptr) {
			root = new BSNode<T>(value);
			size++;
			return;
		}

		BSNode<T> *pp = nullptr;

		while (p != nullptr)
		{
			pp = p;
			if (value < p->data) {
				p = p->leftChild;
			}else if (value > p->data) {
				p = p->rightChild;
			}
			else {
				return;
			}
		}

		BSNode<T> *tmp = new BSNode<T>(value);
		if (value < pp->data) {
			pp->leftChild = tmp;
			size++;
		}else if (value > pp->data) {
			pp->rightChild = tmp;
			size++;
		}

		return;
	}

	void preOrder() {
		preOrder(root);
		
		int num = datas.size();
		for (int i = 0; i < num; i++) {
			cout << datas.front();
			datas.pop();
			if (i != (num - 1)) {
				cout << ",";
			}
		}
	}

	void preOrder(BSNode<T> *root) {
		if (root != nullptr) {
			datas.push(root->data);
			preOrder(root->leftChild);
			preOrder(root->rightChild);
		}
	}

	void inOrder() {
		inOrder(root);
		
		int num = datas.size();
		for (int i = 0; i < num; i++) {
			cout << datas.front();
			datas.pop();
			if (i != (num - 1)) {
				cout << ",";
			}
		}
	}

	void inOrder(BSNode<T> *root) {
		if (root != nullptr) {
			inOrder(root->leftChild);
			datas.push(root->data);
			inOrder(root->rightChild);
		}
	}

private:
	BSNode<T> *root;
	int size;
	queue<T> datas;
};

int main() {

	cout << "Input" << endl;
	int arr[20];
	int arr3[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = -1;
	}
	int i = 1;
	while (i < 20)
	{
		cin >> arr[i];
		arr3[i] = arr[i];
		if (arr[i] == 0) {
			break;
		}
		i++;
	}

	MaxHeap<int> heap;
	heap.init(arr,i - 1);

	cout << "Output" << endl;
	heap.out();

	int length = heap.getSize();
	int *arr2 = new int[length];
	for (int i = length - 1;i >= 0 ; i--)
	{
		arr2[i] = heap.top();
		heap.pop();
	}

	for (int i = 0; i < length - 1;i++) {
		cout << arr2[i] << ",";
	}
	cout << arr2[length - 1] << endl;

	BSTree<int>  bs;
	for (int i = 1; i <= 20;i++) {
		if (arr[i]==0) {
			break;
		}
		bs.push(arr3[i]);
	}
	bs.preOrder();
	cout << endl;
	bs.inOrder();
	cout << endl;
	


	cout << "End" << endl;
	

	system("pause");
	return 0;
}