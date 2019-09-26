#include <iostream>

template<class T>
class TridiagonalMatrix {
private:
	int n;
	T *element;
public:
	TridiagonalMatrix(int n) {
		element = new T[3 * n - 2];
		for (int i = 0; i < 3 * n - 2;i++) {
			element[i] = 0;
		}
		this->n = n;
	}
	
	~TridiagonalMatrix() {
		delete [] element;
	}

	

	T get(int i, int j)const {
		if (i < 1 || j < 1 || i > n || j >n) "无法get，越界";

		switch (i - j) {
		case 1:return element[i - 2];
		case 0:return element[n + i - 2];
		case -1:return element[2 * n + i - 2];
		default:return 0;
		}
	}

	void set(T x, int i, int j) {
		if (i < 1 || j < 1 || i > n || j >n) "无法set，越界";

		switch (i - j) {
		case 1:{
			element[i - 2] = x;
			break;
		}
		case 0: {
			element[n + i - 2] = x;
			break;
		}
		case -1: {
			element[2 * n + i - 2] = x;
			break;
		}
		default: throw "无法set,非三对角矩阵";
		}
	}

	friend ostream& operator<<(ostream& out, const TridiagonalMatrix<T>& t) {
		for (int i = 1; i <= t.n; i++) {
			for (int j = 1; j <= t.n; j++) {
				out << t.get(i, j) << "\t";
			}
			out << endl;
		}
		return out;
	}

};
