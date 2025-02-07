#include "pch.h"
#include "all.h"
using namespace std;

int search(string inOrder, char c)
{
	int root = -1;
	for (int i = 0; i < inOrder.size(); ++i) {
		if (inOrder[i] == c) {
			root = i;
		}
	}
	return root;
}

void printPostOrder(string pre, string in) {
	int root = search(in, pre[0]);
	if (root != 0) { printPostOrder(pre.substr(1, root), in.substr(0, root)); }
	if (root != in.size() - 1) { printPostOrder(pre.substr(root + 1, string::npos), in.substr(root + 1, string::npos)); }
	cout << pre[0];
}
int main()
{
	string pre("ABFGC"), in("FBGAC");
	printPostOrder(pre, in);
	cout << endl;
	
	return 0;
}
