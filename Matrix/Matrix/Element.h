template<class T>
class Element {
private:
	int row, col;
	T value;
public:
	Element(T &value, int row, int col) {
		this->row = row;
		this->col = col;
		this->value = value;
	}
	int getRow() { return row; }
	int getCol() { return col; }
	T getValue() { return value; }

};
