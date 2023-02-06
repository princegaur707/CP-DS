#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int inputdata) {
		data = inputdata;
		left = NULL;
		right = NULL;
	}
};
node* BuildTree() {
	int x;
	cin >> x;
	if (x == -1)
		return NULL;
	else {
		node * root = new node(x);
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
int Height(node* root) {
	if (root == NULL)
		return 0;
	int option1 = Height(root->left);
	int option2 = Height(root->right);
	int height = max(option1, option2) + 1;
	return height;
}
class Pair {
public:
	int height;
	int diameter;
};
Pair FastDiameter(node* root) {
	Pair p;
	if (root == NULL) {
		p.height = 0;
		p.diameter = 0;
		return p;
	}
	Pair left_subtree = FastDiameter(root->left);
	Pair right_subtree = FastDiameter(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;
	p. diameter = max(left_subtree.diameter, max(right_subtree.diameter,
	                  left_subtree.height + right_subtree.height));
	return p;
}
void PrintKthLevel(node *root, int k) {
	if (root == NULL) //if root is NULL we cannot print anything
		return;
	if (k == 1) //we have reached at requierd depth
	{
		cout << root->data << " ";
		return;
	}
	else
	{
		PrintKthLevel(root->left, k - 1);
		PrintKthLevel(root->right, k - 1);
	}
}
void PrintAllLevel(node *root) {
	int h = Height(root);
	for (int i = 1; i <= h; i++) {
		PrintKthLevel(root, i);
		cout << endl;
	}
}// But the tc here is O(n2)

//for O(n) we will use BFS in which queue is used
//insert and pop's tc in queue is O(1)
void bfs(node *root) {
	queue<node*>q;
	q.push(root);
	while (!q.empty()) {
		node *first = q.front();
		cout << first->data << " ";
		q.pop();
		if (first->left != NULL) {
			q.push(first->left);
		}
		if (first->right) {
			q.push(first->right);
		}
	}
}
//If we want to print level order in hierarchy 
//based on their level like:
//2
//9 10
//4 3
void bfs2(node *root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node *first = q.front();
		if(first == NULL) {
			cout << endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else {//because if element is NULL there can be 
			//left or right of it
			cout << first->data << " ";
			q.pop();
			if(first->left != NULL) {
				q.push(first->left);
			}
			if(first->right) {
				q.push(first->right);
			}
		}
	}
}
int main()
{
	node *root = BuildTree();
	cout << "Preorder: ";
	Preorder(root);
	cout << endl;
	cout << Height(root) << endl;
	Pair p = FastDiameter(root);
	cout << p.diameter << endl;
	PrintKthLevel(root, 2);
	cout << endl;
	PrintAllLevel(root);
	cout << endl;
	bfs(root);
	cout << endl;
	bfs2(root);
	cout << endl;
}