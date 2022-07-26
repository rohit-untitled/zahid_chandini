#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};
bool IsSubTreeLesser(Node* root, int val) {
	if (root == NULL)
		return true;
	if (root->data <= val
	        && IsSubTreeLesser(root->left, val)
	        && IsSubTreeLesser(root->right, val))

		return true;
	else
		return false;
}
bool IsSubTreeGreater(Node* root, int val) {
	if (root == NULL)
		return true;
	if (root -> data >= val
	        && IsSubTreeGreater(root->left, val)
	        && IsSubTreeGreater(root->right, val))
		return true;
	else
		return false;
}

bool IsBST(Node* root) {
	if (root == NULL)
		return true;
	if (IsSubTreeLesser(root->left, root->data) && IsSubTreeGreater(root->right, root->data) && IsBST(root->left) && IsBST(root->right))
		return true;
	else
		return false;
}


// Better approach
bool IsBSTutil(Node* root, int minvalue, int maxvalue) {
	if (root == NULL)
		return true;
	if (root->data < minvalue && root ->data > maxvalue
	        && IsBSTutil(root->left, minvalue, root->data)
	        && IsBSTutil(root->right, root->data, maxvalue))

		return true;
	else
		return false;
}
bool IsBinarySearchTree(Node* root) {
	return IsBSTutil(root, INT_MIN, INT_MAX);
}
int main()
{

	return 0;
}