#include <iostream>
#include "Element.h"

using namespace std;

template<class T>
class SparseMatrix {
private:
	int rows, cols, elements;
	Element<T> *element;

public:
	SparseMatrix(int maxElements, int rows, int cols) {
		if (maxElements < 1) throw "无法小于1";
		elements = maxElements;
		element = new Element<T>[maxElements];

		this->rows = rows;
		this->cols = cols;

		for (int i = 0; i < maxElements; i++) {
			set(0,0,0,i);
		}

	}
	SparseMatrix(const SparseMatrix<T>& sm) {
			cols = sm.getCols();
			rows = sm.getRows();
			element = new T[sm.getElements()];

			for (int i = 0; i < sm.getElements(); i++) {
				element[i] = sm.element[i];
			}
	}

	~SparseMatrix() {
		delete[] element;
	}

	int getRows() const { return rows; }
	int getCols() const { return cols; }
	int getElements() const { return elements; }

	void set(int value ,int row, int col,int i) {
			element[i].setRow(row);
			element[i].setCol(col);
			element[i].setValue(value);
	}

	void transpose() {
		SparseMatrix<T> tmp(getElements(), cols, rows);

		int *colSize = new int[cols +1];
		for (int i = 1; i <= cols; i++) {
			colSize[i] = 0;
		}
		for (int i = 0; i < elements; i++) {
			colSize[element[i].getCol()]++;
		}

		int *rowAfter = new int[cols + 1];
		rowAfter[1] = 0;
		for (int i = 2; i <= cols; i++) {
			rowAfter[i] = rowAfter[i - 1] + colSize[i - 1];
		}

		for (int i = 0; i < elements; i++) {
			int j = rowAfter[element[i].getCol()]++;
			tmp.element[j].setRow(this->element[i].getCol());
			tmp.element[j].setCol(this->element[i].getRow());
			tmp.element[j].setValue(this->element[i].getValue());
		}
		for (int i = 0; i < elements; i++) {
			element[i].setRow(tmp.element[i].getRow());
			element[i].setCol(tmp.element[i].getCol());
			element[i].setValue(tmp.element[i].getValue());
		}

		delete[] colSize;
		delete[] rowAfter;
	}

	friend ostream& operator<<(ostream& out, const SparseMatrix<T>& sm) {
		if (sm.getElements()) {
			for (int i = 0; i < sm.getElements(); i++) {
				out << "M(" << sm.element[i].getRow() << "," << sm.element[i].getCol() << ") = " << sm.element[i].getValue() << endl;
			}
		}
		else {
			out << "There are no elements in sparsematrix." << endl;
		}
		return out;
		
	}

};
