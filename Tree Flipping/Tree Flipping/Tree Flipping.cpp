#include "pch.h"
#include "all.h"
using namespace std;
template <class T>
struct Tnode {
	T info;
	Tnode*right;
	Tnode*left;
	Tnode() {
		right = left = 0;
	}
	Tnode(T x) {
		info = x;
		right = left = 0;
	}
};
template <class T>
class Tree {
public:
	Tnode<T> * root;
	Tree() {
		root = NULL;
	}
	Tnode<T> *insert(Tnode<T>*root, T x) {
		if (root == NULL) {
			return new Tnode(x, idx);
		}
		if (root->info == x) {
			return root;
		}
		if (root->info < x) {
			root->right = insert(root->right, x, idx);
		}
		else {
			root->left = insert(root->left, x, idx);
		}
		return root;
	}
	void insert(T x) {
		root = insert(root, x);
	}
	void printINorder(Tnode<T>*root) {
		if (root) {
			printINorder(root->left);
			cout << root->info << " ";
			printINorder(root->right);
		}
	}
	void printINorder() {
		printINorder(root);
	}
	void Flip(Tnode<T>* current) {
		if (current) {
			Flip(current->left); Flip(current->right);
			Tnode<T> *temp = current->left; current->left = current->right; current->right = temp;
		}
	}
	void Flip() {
		Flip(root);
	}

};
int main()
{
	Tree<int> t;
	t.root = new Tnode<int>(1);
	t.root->left = new Tnode<int>(2);
	t.root->left->left = new Tnode<int>(4);
	t.root->left->right = new Tnode<int>(5);
	t.root->right = new Tnode<int>(3);
	t.printINorder();
	t.Flip();
	cout << endl;
	t.printINorder();
	system("pause");
	return 0;
}

