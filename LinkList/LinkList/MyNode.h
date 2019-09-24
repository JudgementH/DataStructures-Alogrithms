template<class T>
class MyNode
{
public:
	MyNode(T data, MyNode  *next, MyNode  *pre) {
		MyNode<T>::data = data;
		MyNode<T>::pre = pre;
		MyNode<T>::next = next;
	}
	~MyNode() {}
	T getData() { return data; }
	MyNode<T>* getNext() {
		return MyNode<T>::next;
	}
	MyNode<T>* getPre() {
		return MyNode<T>::pre;
	}
	void setData(T data) {
		MyNode<T>::data = data;
	}
	void setNext(MyNode *next) {
		MyNode<T>::next = next;
	}
	void setPre(MyNode *pre) {
		MyNode<T>::pre = pre;
	}
private:
	T data;
	MyNode *next, *pre;
};