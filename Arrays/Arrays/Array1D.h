template<class T>
class Array1D
{
public:
	Array1D(int size = 0);
	Array1D(const Array1D<T> &v);
	~Array1D();
	T& operator[](int i) const;
	int Size() { return size; }
	Array1D<T>& operator=(const Array1D<T>& v);
	Array1D<T> operator+() const;
	Array1D<T> operator+(const Array1D<T>& v) const;
	Array1D<T> operator-() const;
	Array1D<T> operator-(const Array1D<T>& v)const;
	Array1D<T>& operator+=(const T& x);
	Array1D<T> operator*(const Array1D<T>& c) const;


private:
	int size;
	T *ellement;

};
