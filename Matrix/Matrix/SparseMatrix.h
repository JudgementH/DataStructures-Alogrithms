#include <iostream>
#include "Element.h"

template<class T>
class SparseMatrix {
private:
	int rows, cols, elements;
	Elements<T> *element;

public:
	SparseMatrix(int maxElements, int rows, int cols) {
		if (maxElements < 1) throw "无法小于1";
		elements = maxElements;
		elements = new element<T>[maxElements];

		this->rows = rows;
		this->cols = cols;
	}
	SparseMatrix(const SparseMatrix<T>& sm)
	~SparseMatrix();

	int getRows() const { return rows; }
	int getCols() const { return cols; }
	int getElements() const { return elements; }
};
