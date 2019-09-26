#include <iostream>
using namespace std;

template<class T>
class Matrix {
private:
	T *element;
	int rows, cols;
public:
	Matrix(int rows, int cols) {
		element = new T[rows * cols];

		for (int i = 0; i < rows * cols; i++) {
			element[i] = 0;
		}
		this->cols = cols;
		this->rows = rows;
	}
	Matrix(T* array,int rows, int cols) {//把二维数组转化为一维数组来实现；
		int now = 0;
		int pre = 0;
		this->element = new T[rows * cols];

		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++) {
				now++;
				element[i*cols+j] = array[i*cols + j];
			}
			if (i >0 && now != pre) {
				throw "矩阵每行元素数要一致";
			}
			pre = now;
			now = 0;
		}

		this->rows = rows;
		this->cols = cols;
	}
	Matrix(const Matrix<T>& m) {
		cols = m.getCols();
		rows = m.getRows();
		element = new T[cols * rows ];

		for (int i = 0; i < cols * rows; i++) {
			element[i] = m.element[i];
		}

	}
	~Matrix() {
		delete[] element;
	}

	void setRows(T rows) {
		this->rows = rows;
	}

	void setCols(T cols) {
		this->cols = cols;
	}

	int getRows() const {
		return rows;
	}
	int getCols() const {
		return cols;
	}

	T* getElement() const {
		return element;
	}

	void set(T x,int row, int col) {
		if (row > rows || row < 1 || col < 1 || col > cols) throw "无法set，越界";
		element[(row - 1 )*cols + col - 1] = x;
	}

	T get(int row, int col) const {
		if (row > rows || row < 1 || col < 1 || col > cols) throw "无法get，越界";
		return element[(row - 1) * cols + col - 1];
	}

	void transpose(){

		for (int i = 0; i < this->rows; i++) {
			for (int j = i; j < this->cols; j++) {
				T tmp = 0;
				tmp  = element[i * cols + j];
				element[i * cols + j] = element[j * rows + i];
				element[j * rows + i] = tmp;
			}
		}


		int tn;
		tn = cols;
		cols = rows;
		rows = tn;

	}


	Matrix<T> operator+(const Matrix<T>& m)const {
		if (rows != m.getRows() || cols != m.getCols()) throw "矩阵无法相加";

		Matrix<T> tmp(rows, cols);
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= cols; j++) {
				tmp.set(get(i, j) + m.get(i, j), i, j);
			}
		}

		return tmp;
	}

	Matrix<T> operator-(const Matrix<T>& m)const {
		if (rows != m.getRows() || cols != m.getCols()) throw "矩阵无法相减";

		Matrix<T> tmp(rows, cols);
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= cols; j++) {
				tmp.set(get(i, j) - m.get(i, j), i, j);
			}
		}

		return tmp;
	}

	Matrix<T> operator*(const Matrix<T>& m)const {
		if (getCols() != m.getRows()) throw "矩阵无法相乘";

		//a*m m*b =a b

		Matrix<T> tmp(rows, cols);
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= m.getCols(); j++) {
				int sum = 0;
				for (int k = 1; k <= getCols(); k++) {
					sum += get(i,k) * m.get(k,j);
				}
				tmp.set(sum, i, j);
			}
		}

		return tmp;
	}

	T& operator()(int i, int j)const{		
		if (i <1 || i > rows || j < 1 || j > cols) {
			throw "访问超越矩阵边界";
		}

		return element[(i - 1)*cols + (j - 1) ];
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
