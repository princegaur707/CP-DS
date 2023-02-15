#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *left;
	node *right;

	node(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};
node* BuildTree() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	}
	else {
		node* root = new node(x);
		root->left = BuildTree();
		root->right = BuildTree();
		return root;
	}
}
void Preorder(node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}
void bfs2(node *root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* first = q.front();
		if (first == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty())
				q.push(NULL);
		}
		else {
			cout << first->data << " ";
			q.pop();
			if (first->left != NULL)
				q.push(first->left);
			if (first->right)
				q.push(first->right);
		}
	}
}
//When the eye is positioned at right side of the tree which elements it can see
void PrintRightView(node *root, int level, int &maxlevel)//maxlevel is pass by reference in orderto save the changes everytime
{
	if (root == NULL) {
		return;
	}
	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}
	PrintRightView(root->right, level + 1, maxlevel);
	PrintRightView(root->left, level + 1, maxlevel);
}
void PrintLeftView (node *root, int level, int &maxlevel) {
	if (root == NULL) {
		return;
	}
	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}
	PrintLeftView(root->left, level + 1, maxlevel);
	PrintLeftView(root->right, level + 1, maxlevel);
}
node* InsertInBST(node* &root, int value) {//we are passing by reference so even if
	//we not return root and do not use root->left etc here then even it will work
	if (root == NULL) {
		// cout << "1" << endl;
		root = new node(value);
		return root;
	}
	if (value < root->data) {
		// cout << "2" << endl;
		root->left = InsertInBST(root->left, value);
	}
	if (value > root->data) {
		// cout << "3" << endl;
		root->right = InsertInBST(root->right, value);
	}
	return root;
}
node* BuildBST() {
	int value;
	cin >> value;
	node* root = NULL;
	while (value != -1) {
		// cout << "0" << endl;
		root = InsertInBST(root, value);
		cin >> value;
	}
	return root;
}
bool SearchInBST(node* root, int key) {
	if (root == NULL) {
		return false;
	}
	if (root->data == key) {
		return true;
	}
	else if (root->data < key) {
		return SearchInBST(root->right, key);
	}
	else {
		return SearchInBST(root->left, key);
	}
}
bool IsBST(node *root, int min = INT_MIN, int max = INT_MAX) {
	if (root == NULL) {
		return true;
	}
	if ((root->data) > min and (root->data) < max
	    and IsBST(root->left, min, root->data)
	    and IsBST(root->right, root->data, max)) {
		return true;
	}
	return false;
}
void PrintRange(node *root, int key1, int key2) {
	if (root == NULL)
		return;
	PrintRange(root->left, key1, key2);
	if (root->data >= key1 and root->data <= key2)
		cout << root->data << " ";
	PrintRange(root->right, key1, key2);
}
int main() {
	node *root = BuildTree();
	bfs2(root);
	cout << "Right View: ";
	int maxlevel = -1;//it needs to be one less than level as we need to print that too
	PrintRightView(root, 0, maxlevel);//when we make any variable reference variable we cannot pass the static value
	//we need to pass the variable so we defined maxlevel also.
	int maxlevel1 = -1;
	cout << endl  << "Left View: ";
	PrintLeftView(root, 0, maxlevel1);
	cout << endl;
	node* root2 = BuildBST();
	Preorder(root2);
	cout << endl;
	cout << SearchInBST(root2, 1) << endl;
	cout << SearchInBST(root2, 3) << endl;
	//Check if Tree is BST or NOT
	//Best way: Find inorder check whether inorder is sorted or not
	//Recursive way: For every nod
	cout << "IsBST: " << IsBST(root2) << endl;
	cout << "ISBST: " << IsBST(root) << endl;
	PrintRange(root2, 4, 7);//We want element in array b/w key1 and key2 in sorted order
	
}