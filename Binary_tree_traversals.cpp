#include<bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	Node *left, *right;
};
Node* get_node(int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = get_node(data);
		return root;
	}
	else if (root->data <= data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;

}
void LevelOrder(Node* root) {
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* current = q.front();
		cout << current->data << " ";
		if (current -> left != NULL) q.push(current->left);
		if (current->right != NULL) q.push(current->right);
		q.pop();
	}
}
void PreOrder(Node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void Inorder(Node* root) {
	if (root == NULL)
		return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
void PostOrder(Node* root) {
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}
int main()
{
	Node* root = NULL;
	root = Insert(root, 'M'); root = Insert(root, 'B');
	root = Insert(root, 'Q'); root = Insert(root, 'Z');
	root = Insert(root, 'A'); root = Insert(root, 'C');
	//Print Nodes in Level Order.
	LevelOrder(root);
	cout << endl;
	PreOrder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	PostOrder(root);

	return 0;
}