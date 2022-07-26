#include<stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* left, *right;
};
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
int search(int arr[], int start, int end, int value) {
	for (int i = start; i <= end; i++) {
		if (arr[i] == value)
			return i;
	}
}
struct Node* createBT(int in[], int pre[], int start, int end) {
	static int preIndex = 0;
	if (start > end)
		return NULL;

	struct Node* temp = newNode(pre[preIndex++]);
	if (start == end)
		return temp;

	int inIndex = search(in, start, end, temp->data);
	temp->left = createBT(in, pre, start, inIndex - 1);
	temp->right = createBT(in, pre, inIndex + 1, end);
	return temp;
}
void postOrder(struct Node* root) {
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

int main() {
	int in[10] = {3, 12, 6, 4, 7, 10, 11, 5, 2, 8};
	int pre[10] = {10, 12, 3, 4, 6, 7, 5, 11, 2, 8};
	struct Node* root = createBT(in, pre, 0, 9);
	postOrder(root);
	return 0;
}