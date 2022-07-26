#include<bits/stdc++.h>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};
// BSTNode* root; // root pointer
// root = NULL;//setting tree as empty
BSTNode* get_node(int data) {
	BSTNode* new_node = new BSTNode();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
BSTNode* insert(BSTNode* root, int data) {
	if (root == NULL) {
		root = get_node(data);
		return root;
	}
	else if (data <= root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	return root;
}
bool search(BSTNode* root, int data) {
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return search(root->left, data);
	else
		return search(root->right, data);

	return root;
}

BSTNode* find_min(BSTNode* root) {
	if (root == NULL)
		return -1;
	else if (root->left == NULL)
		return root->data;
	return find_min(root->left);
}
BSTNode* find_max(BSTNode* root) {
	if (root == NULL)
		return -1;
	else if (root->right == NULL)
		return root->data;
	return find_max(root->right);
}
int find_height() {
	if (root == NULL)
		return -1;
	else
		return max(find_height(root->left), find_height(root->right)) + 1;
}
int main()
{
	BSTNode* root = NULL;// Creating an empty tree
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 11);
	root = insert(root, 17);
	root = insert(root, 9);
	root = insert(root, 12);
	int num;
	cin >> num;
	if (search(root, num) == true)
		cout << "Found" << endl;
	else
		cout << "Not found" << endl;
	return 0;
}