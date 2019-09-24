#include <iostream>
#include "MyNode.h"

using namespace std;

template<class T>
class Chain
{
public:
	Chain() {
		head = new MyNode<T>(NULL,head,head);
		head->setPre(head);
		head->setNext(head);
		length = 1;
	}

	~Chain() {}

	MyNode<T>* getByIndex(int i) {
		if (i > length - 1) {
			throw "ÐòºÅ³ö½ç";
		}
		MyNode<T> *tmp = head;
		int t = 0;
		if (i <= length -1) {
			while (tmp->getNext() != head && t!= i)
			{
				tmp = tmp->getNext();
				t++;
			}
		}
		else {
			while (tmp->getPre() != head && t!= i)
			{
				tmp = tmp->getPre();
				if (t == 0) {
					t = length - 1;
				}
				t--;

			}
		}
		if (tmp->getNext() == head && t != i) {
			return nullptr;
		}
		else return tmp;
	}

	void insert(int index, T data) {
		MyNode<T>* tar = getByIndex(index);
		if (tar != nullptr) {
			MyNode<T>* x = new MyNode<T>(data, nullptr, nullptr);
			if (length == 1) {
				head->setNext(x);
				head->setPre(x);
				x->setNext(head);
				x->setPre(head);
				length++;
			}
			else {
				if (x != nullptr) {
					x->setNext(tar);
					x->setPre(tar->getPre());
					tar->setPre(x);
					x->getPre()->setNext(x);
					length++;
				}
			}
		}
	}

	void remove(int index) {
		MyNode<T> *tar = getByIndex(index);
		if (tar != nullptr) {
			if (length > 1) {
				if (tar == head) {
					head = tar->getNext();
				}
				tar->getPre()->setNext(tar->getNext());
				tar->getNext()->setPre(tar->getPre());
				length--;
				delete tar;
			}
		}
	}

	void output(const Chain<T> &chain) const;

private:
	MyNode<T> *head;
	int length;

};
template<class	T>
void Chain<T>::output(const Chain<T> &chain)const {
	MyNode<T> *tmp = head;
	for (int i = 0; i < Chain<T>::length; i++) {
		cout << tmp->getData() << "\t";
		tmp = tmp->getNext();
	}
}
template<class	T>
ostream &operator<<(ostream &out, const Chain<T> &chain) {
	chain.output(chain);
	return out;
}