#include<bits/stdc++.h>
#define pb				 push_back
#define ll				 long long
#define endl			 '\n'
#define pii 			 pair<int, int>
#define vi				 vector<int>
#define mii				 map<int, int>
#define ump				 unordered_map
#define all(a)			 (a).begin(),(a).end()
#define ff				 first
#define ss 			     second
#define sz(x)			 (int)x.size()
#define lbnd			 lower_bound
#define ubnd			 upper_bound
#define bs 				 binary_search
#define lcm				 ((a)*(b)) / gcd((a),(b))
#define hell 			 10000007
#define w(x)			 int x; cin >> x; while(x--)
#define FI0  			 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node() { // simple constructor
		value = 0;
		left  = NULL;
		right = NULL;

	}
	Node(int val) { // parameterized constructor
		value = val;
		left  = NULL;
		right = NULL;
	}
};

class BST {
private:
	Node* root;

public:
	BST() { // parameterized comstructor
		root = NULL;
	}
	BST(int rootValue) {
		root = new Node(rootValue);
	}
	Node* getRoot() {
		return root;
	}
	Node* insert(Node* currentNode, int val) { // helper function
		if (currentNode == NULL) {
			return new Node(val);
		}
		else if (currentNode-> value > val)
			currentNode -> left = insert(currentNode-> left, val);
		else if (currentNode->value < val)
			currentNode-> right = insert(currentNode->right, val);

		return currentNode;
	}

	Node* del(Node* currentNode, int val) {
		if (currentNode == NULL)
			return NULL;

		if (currentNode-> value > val)
			currentNode->left = del(currentNode->left, val);
		else if (currentNode-> value < val)
			currentNode->right = del(currentNode-> right, val);

		else {
			if (currentNode-> left == NULL and currentNode-> right == NULL) {
				delete(currentNode); // 0 child
				return NULL;
			}
			else if (currentNode -> right == NULL) { // only left child
				Node* temp = currentNode-> left;
				free(currentNode);
				return temp;
			}
			else if (currentNode ->left == NULL) { // only left child
				Node* temp = currentNode-> right;
				free(currentNode);
				return temp;
			} else { // both the children
				int nge = find_smallest(currentNode-> right);
				currentNode-> value = nge;
				currentNode-> right = del(currentNode-> right, nge);
				return currentNode;
			}

		}

	}
	int find_smallest(Node* currentNode) {
		if (currentNode-> left == NULL) {
			return currentNode-> value;
		}
		else return find_smallest(currentNode-> left);
	}
	Node* search(Node* currentNode, int val) {
		if (currentNode == NULL)
			return NULL;

		if (currentNode->value == val)
			return currentNode;

		else if (currentNode-> value < val)
			return search(currentNode-> right, val);

		else
			return search(currentNode-> left, val);
	}
	void print(Node* currentNode) {
		if (currentNode == NULL) return;
		print(currentNode-> left);
		cout << currentNode-> value << " ";
		print(currentNode-> right);

	}
};

int main(int argc, char const *argv[]) {
	FI0
	BST bst(10);
	bst.insert(bst.getRoot(), 5);
	bst.insert(bst.getRoot(), 10);
	bst.insert(bst.getRoot(), 50);
	bst.insert(bst.getRoot(), 7);
	bst.insert(bst.getRoot(), 9);
	bst.insert(bst.getRoot(), 1);

	bst.print(bst.getRoot());


	return 0;
}