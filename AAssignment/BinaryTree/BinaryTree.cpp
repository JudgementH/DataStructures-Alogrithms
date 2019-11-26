#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>

using namespace std;

template<class T>
class TreeNode {
public:
	T data;
	TreeNode<T> *leftChild, *rightChild;
public:
	TreeNode() :leftChild(nullptr), rightChild(nullptr) {}
	TreeNode(T value, TreeNode<T> *l = nullptr, TreeNode<T> *r = nullptr) :data(value),leftChild(l),rightChild(r){}
};

template<class T>
class BinaryTree {
private:
	TreeNode<T> *root;
	T refValue;
public:
	BinaryTree() :root(nullptr) {}
	BinaryTree(T value) :refValue(value), root(nullptr) {}
	~BinaryTree(){Destory(root);}

	void initBinTreeByLayer(T *str,int num) {
		
		queue<TreeNode<T>*> qt;
		TreeNode<T> *tn;
		tn = new TreeNode<T>(str[0]);
		root = tn;
		for (int i = 1; i < num;) {
			tn->leftChild = new TreeNode<T>(str[i]);
			i++;
			qt.push(tn->leftChild);

			tn->rightChild = new TreeNode<T>(str[i]);
			i++;
			qt.push(tn->rightChild);

			tn = qt.front();
			qt.pop();
		}
	}

	void initBinTreeByPreIn(T *preStr, T *inStr,int length) {
		initBinTreeByPreIn(preStr, inStr, root, length);
	}

	void initBinTreeByPreIn(T *preStr,T *inStr, TreeNode<T> *&current,int cen) {
		if (cen <= 0) {
			current = nullptr;
			return;
		}
		
		int k = 0;
		while (preStr[0] != inStr[k])
		{
			k++;
		}

		current = new TreeNode<T>(inStr[k],nullptr,nullptr);
		initBinTreeByPreIn(preStr+1,inStr,current->leftChild, k);
		initBinTreeByPreIn(preStr+k+1,inStr+k+1,current->rightChild,cen - (k+1));
	}

	void layerOrder() {layerOrder(root);}

	void preOrder() { 
		string str = ""; 
		preOrder(root,str);
		for (int i = 0; i < str.size(); i++) {
			cout << str[i];
			if (i != (str.size() - 1)) {
				cout << ",";
			}
		}
	}

	void inOrder() {
		string str = "";
		inOrder(root,str);
		for (int i = 0; i < str.size();i++) {
			cout << str[i];
			if (i != (str.size() -1)) {
				cout << ",";
			}
		}
	}

	void postOrder() {
		string str = "";
		postOrder(root,str);
		for (int i = 0; i < str.size(); i++) {
			cout << str[i];
			if (i != (str.size() - 1)) {
				cout << ",";
			}
		}
	}

	int size() { return size(root); }

	int height() { return height(root); }

	int size(TreeNode<T> *root) {
		if (root == nullptr) {
			return 0;
		}
		return 1 + size(root->leftChild) + size(root->rightChild);
	}

	int height(TreeNode<T> *root) {
		if (root == nullptr) {
			return 0;
		}
		int lH = height(root->leftChild);
		int rH = height(root->rightChild);
		if (lH >= rH) {
			return 1 + lH;
		}
		else
		{
			return 1 + rH;
		}
	}

private:
	void makeTree(const T &value, TreeNode<T> &l, TreeNode<T> &r) {
		root = new TreeNode<T>(value,l,r);
		l = nullptr;
		r = nullptr;
	}

	void Destory(TreeNode<T> *&treeNode) {
		if (treeNode != NULL) {
			Destory(treeNode->leftChild);
			Destory(treeNode->rightChild);
			delete treeNode;
			treeNode = NULL;
		}
	}

	void layerOrder(TreeNode<T> *root) {
		queue<TreeNode<T>*> q;
		q.push(root);
		TreeNode<T> *tmp;
		while (!q.empty())
		{
			tmp = q.front();
			q.pop();
			if (tmp->leftChild != nullptr) {
				q.push(tmp->leftChild);
			}
			if (tmp->rightChild!=nullptr) {
				q.push(tmp->rightChild);
			}
			cout << tmp->data;
			if (!q.empty()) {
				cout << ",";
			}
		}
	}

	void preOrder(TreeNode<T> *root,string &str) {
		if(root!=nullptr){
			str += root->data;
			preOrder(root->leftChild,str);
			preOrder(root->rightChild,str);
		}
	}

	void inOrder(TreeNode<T> *root,string &str) {
		if (root != nullptr) {
			inOrder(root->leftChild,str);
			str += root->data;
			inOrder(root->rightChild,str);
		}
	}

	void postOrder(TreeNode<T> *root,string &str) {
		if (root != nullptr) {
			postOrder(root->leftChild,str);
			postOrder(root->rightChild,str);
			str += root->data;
		}
	}
};

int main() {
	BinaryTree<char> binaryTree;

	cout << "Input1" << endl;
	string str;
	cin >> str;
	char chars[20];
	strcpy_s(chars,str.c_str());
	binaryTree.initBinTreeByLayer(chars, str.size());

	cout << "Output1" << endl;
	binaryTree.preOrder();
	cout << endl;
	binaryTree.inOrder();
	cout << endl;
	binaryTree.postOrder();
	cout << endl;
	cout << binaryTree.size();
	cout << endl;
	cout << binaryTree.height();
	cout << endl;

	cout << "Input2" << endl;
	string str2;
	cin >> str2;
	char preChars[20];
	strcpy_s(preChars, str2.c_str());

	string str3;
	cin >> str3;
	char inChars[20];
	strcpy_s(inChars, str3.c_str());

	BinaryTree<char> bt2;
	bt2.initBinTreeByPreIn(preChars,inChars,str2.size());

	cout << "Output2" << endl;
	bt2.postOrder();
	cout << endl;
	bt2.layerOrder();
	cout << endl;
	binaryTree.~BinaryTree();
	bt2.~BinaryTree();
	cout << "End" << endl;
	system("pause");
	return 0;
}