template<class T>
class Element {
private:
	int row, col;
	T value;
public:
	Element() {
	}
	Element(T &value, int row, int col) {
		this->row = row;
		this->col = col;
		this->value = value;
	}
	int getRow() { return row; }
	void setRow(int row) { this->row = row; }
	int getCol() { return col; }
	void setCol(int col) { this->col = col; }
	T getValue() { return value; }
	void setValue(T value) { this->value = value; }

};
