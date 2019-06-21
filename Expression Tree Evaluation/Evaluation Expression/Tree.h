#pragma once
#include <all.h>
using namespace std;
struct Treenode {
	char info;
	Treenode*right;Treenode*left;
	Treenode() {
		right = left = NULL;
	}
	Treenode(char x) {
		right = left = NULL;
		info = x;
	}
};
class Tree
{
private :
	Treenode * root;
	stack<Treenode*,list<Treenode*>> s;
public:
	Tree() {
		root = NULL;
	}

	double evaluate(Treenode *root)
	{
		if (root->left == NULL && root->right == NULL)
			return (root->info)-'0';
		else
		{
			double left = evaluate(root->left);
			double right = evaluate(root->right);
			char c = root->info;
			switch (c)
			{
			case '+':
				return ( left + right);
			case '-':
				return left - right;
			case '*':
				return left * right;
			case '/':
				return left / right;
			}

		}
	}
	
	void construct(string a) {
		for (int i = a.size() - 1;i >= 0;i--) {
			if (a[i] == '/' || a[i] == '*' || a[i] == '+' || a[i] == '-') {
				Treenode* t = new Treenode(a[i]);
				Treenode *t1 = s.top();s.pop();
				Treenode *t2 = s.top();s.pop();
				t->right = t2;t->left = t1;
				s.push(t);
			}
			else if (a[i] >= '0' && a[i] <= '9') {
				Treenode*t = new Treenode(a[i]); s.push(t);
			}
		}
		root = s.top();
	}
	void printINorder(Treenode*root) {
		if (root) {
			printINorder(root->left);
			cout << root->info << " ";
			printINorder(root->right);
		}
	}
	void printINorder() {
		printINorder(root);
	}
	double evaluate() {
		return evaluate(root);
	}
};

