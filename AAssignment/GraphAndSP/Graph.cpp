#include <iostream>
#include <stdlib.h>
#include <queue>
#include <list>
#define MAX 10

using namespace std;

class Graph {
public:
	Graph(int numV,int numE):numVertex(numV),numEdge(numE) {
		for (int i = 0; i < numVertex; i++) {
			for (int j = 0; j < numVertex; j++)
			{
				adjMatrix[i][j] = 0;
			}
		}
	}
	void setEdge(int start,int end, int weight) {
		adjMatrix[start - 1][end - 1] = weight;
		adjMatrix[end - 1][start - 1] = weight;
	}

	//广度优先
	void bfs() {
		queue<int> q;
		queue<int> order;
		bool *label = new bool[numVertex];
		for (int i = 0; i < numVertex; i++) {
			label[i] = false; //false 表示未遍历过， true 表示遍历过
		}
		q.push(1);
		label[0] = true;
		while (!q.empty())
		{
			int tmp = q.front();
			order.push(tmp);
			q.pop();
			for (int i = 0; i < numVertex; i++) {
				if ((adjMatrix[tmp - 1][i] != 0) && (label[i] == 0)) {
					q.push(i+1);
					label[i] = true;
				}
			}
		}
		int len = order.size();
		for (int i = 0; i < len - 1; i++) {
			cout << order.front() << ",";
			order.pop();
		}
		cout << order.front();
		order.pop();

	}

	//深度优先
	void dfs() {
		bool *label = new bool[numVertex];
		queue<int> order;
		for (int i = 0; i < numVertex; i++) {
			label[i] = false; //false 表示未遍历过， true 表示遍历过
		}

		for (int i = 0; i < 1; i++) {
			if (!label[i]) {
				order.push(i+1);
				dfs(i, label, &order);
			}
		}

		int len = order.size();
		for (int i = 0; i < len - 1; i++) {
			cout << order.front() << ",";
			order.pop();
		}
		cout << order.front();
		order.pop();
		delete[] label;

	}
	void dfs(int start,bool *label,queue<int> *order) {
		label[start] = true;
		
		int tmp = -1;  //下一个相邻且未走过的的序号
		for (int i = 0; i < numVertex; i++) {
			if (!label[i] && (adjMatrix[start][i] != 0)) {
				tmp = i;
				order->push(tmp + 1);
				break;
			}
		}
		if (tmp == -1) {
			return;
		}
		dfs(tmp,label,order);
		

	}

	int shortestPath() {
		int *d = new int[numVertex];
		int *p = new int[numVertex];
		shortestPath(0, d, p);
		int len = d[numVertex - 1];
		delete[] d;
		delete[] p;
		return len;
	}
	void shortestPath(int s,int *d, int *p) {
		list<int> l;
		list<int>::iterator iter;

		for (int i = 0; i < numVertex;i++) {
			d[i] = adjMatrix[s][i];
			if (d[i] == 0) {
				p[i] = -1;
			}
			else {
				p[i] = s;
				l.push_front(i);
			}
		}


		while (!l.empty())
		{
			//找到所有相邻点中距离s最小的
			int a = *l.begin();
			for (iter = l.begin(); iter != l.end(); iter++) {
				if (d[*iter] < d[a] && d[*iter] != 0) {
					a = *iter;
				}
			}

			int i = a;
			l.remove(a);
			for (int j = 0; j < numVertex; j++) {
				if (adjMatrix[i][j] != 0 && (p[j] == -1 || d[j] > d[i] + adjMatrix[i][j])) {
					d[j] = d[i] + adjMatrix[i][j];
					if (p[j] == -1) {
						l.push_front(i);
					}
					p[j] = i;
				}
			}
		}
	}

	int getNumEdge() {
		return numEdge;
	}

	void print() {
		for (int i = 0; i < numVertex;i++) {
			for (int j = 0; j < numVertex; j++)
			{
				cout << adjMatrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
private:
	int numVertex,numEdge;
	int adjMatrix[MAX][MAX];
};

istream& separator(istream& is)
{
	return is.ignore();
}

int main() {

	cout << "Input" << endl;
	int input1[2];
	cin >> input1[0] >> separator >> input1[1];
	Graph graph(input1[0],input1[1]);

	int numEdge = graph.getNumEdge();
	int input2[3];
	for (int i = 0; i < numEdge;i++) {
		cin >> input2[0] >> separator >> input2[1] >> separator >> input2[2];
		graph.setEdge(input2[0], input2[1], input2[2]);
	}
	cout << "Output" << endl;
	graph.bfs();
	cout << endl;
	graph.dfs();
	cout << endl;
	cout << graph.shortestPath();
	cout << endl;

	
	cout << "End" << endl;

	system("pause");
	return 0;
}