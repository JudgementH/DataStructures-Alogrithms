#include <iostream>
using namespace std;

template<class T>
class Matrix {
private:
	T *element;
	int rows, cols;
public:
	Matrix(T* array,int rows, int cols) {//�Ѷ�ά����ת��Ϊһά������ʵ�֣�
		int now = 0;
		int pre = 0;
		this->element = new T[rows * cols];

		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++) {
				now++;
				element[i*cols+j] = array[i*cols + j];
			}
			if (i >0 && now != pre) {
				throw "����ÿ��Ԫ����Ҫһ��";
			}
			pre = now;
			now = 0;
		}

		this->rows = rows;
		this->cols = cols;
	}
	
	

	Matrix(const Matrix<T>& m) {}
	~Matrix() {}

	int getRows() const {
		return rows;
	}
	int getCols() const {
		return cols;
	}


	friend ostream& operator<<(ostream &out, const Matrix<T> &t) {
		for (int i = 0; i < t.getRows(); i++) {
			for (int j = 0; j < t.getCols(); j++) {
				out << t.element[t.cols * i + j]<<"\t";
			}
			out << endl;
		}
		out << endl;

		return out;
	}
};
