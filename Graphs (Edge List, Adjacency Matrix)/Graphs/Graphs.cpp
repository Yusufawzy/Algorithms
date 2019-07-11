// Graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
class Graph {
private:

	int arr[10][10] = { {0} };

public:
	vector<vector<int>> g;

	void Add(int x, int y) {
		g[x].push_back(y);
	}

	Graph() {
		g.resize(10);
		
	}
	void print() {
		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < g[i].size(); j++) {
				arr[i] [g[i][j]] = 1;
				arr[g[i][j]][i] = 1;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << arr[i][j] << " ";

			}
			cout << endl;
		}
	}

};
int main()
{
	Graph g1;
	g1.Add(0, 1);
	g1.Add(0, 2);
	g1.Add(0, 3);
	g1.Add(1,3 );
	g1.Add(2, 3);

	g1.print();
}
