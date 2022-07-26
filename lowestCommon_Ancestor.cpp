//problem link -> https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
};
node* lca(node* root, int n1, int n2) {
	if (root == NULL)
		return NULL;
	if (root->data > n1 and root->data > n2)
		return lca(root->left, n1, n2);
	if (root->data < n1 and root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}
node* new_node(int data) {
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return Node;
}
int main() {
	node *root = new_node(20);
	root->left = new_node(8);
	root->right = new_node(22);
	root->left->left = new_node(4);
	root->left->right = new_node(12);
	root->left->right->left = new_node(10);
	root->left->right->right = new_node(14);

	int n1 = 10, n2 = 14;
	node *t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
	return 0;
}