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
	if (x == -1) {
		return NULL;
	}
	else {
		node* root = new node(x);
		root->left = BuildTree();
		root->right = BuildTree();
		return root;//At every point
		//we must have the referece to the root
	}
}
void Preorder(node* root) {
	if (root == NULL) { //hitting the base case(deepest point)
		return;
	}
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}
void Inorder(node* root) {
	if (root == NULL) {
		return;
	}
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
void Postorder(node* root) {
	if (root == NULL) {
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}
int CountNodes(node* root) {
	if (root == NULL) {
		return 0;
	}
	int x = CountNodes(root->left);
	int y = CountNodes(root->right);
	int ans = x + y + 1;
	return ans;
}
int SumOfNodes(node* root) {
	if (root == NULL) {
		return 0;
	}
	int x = SumOfNodes(root->left);
	int y = SumOfNodes(root->right);
	int ans = x + y + root->data;
	return ans;
}
int Height(node* root) {
	if (root == NULL) {
		return 0;
	}
	int x = Height(root->left);
	int y = Height(root->right);
	int ans = 1 + max(x, y);
	return ans;
}
void Mirror(node* root) {
	if (root == NULL) {
		return;
	}
	swap(root->left, root->right);
	Mirror(root->left);
	Mirror(root->right);
}
int Diameter(node* root) {
	if (root == NULL) {
		return 0;
	}
	int option1 = Diameter(root->left);
	int option2 = Diameter(root->right);
	int option3 = Height(root->left) + Height(root->right);

	return max(option1, max(option2, option3));
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

	p.diameter = max(left_subtree.diameter, max(right_subtree.diameter,
	                 left_subtree.height + right_subtree.height));
	return p;
}
class Pair3 {
 public:
	int height;
	bool is_balanced;
};
Pair3 IsHeightBalanced(node* root) {
	Pair3 p;
	if (root == NULL)
	{
		p.height = 0;
		p.is_balanced = true;//single node is always balanced
		return p;
	}
	Pair3 left_subtree = IsHeightBalanced(root->left);
	Pair3 right_subtree = IsHeightBalanced(root->right);

	p.height = max(left_subtree.height, right_subtree.height) + 1;
	if (left_subtree.is_balanced == 1 and right_subtree.is_balanced == 1 and
	        abs(left_subtree.height - right_subtree.height) <= 1) {
		p.is_balanced = true;
	}
	else {
		p.is_balanced = false;
	}
	return p;
}
node * BuildTreeFromArray(int *a, int s, int e) {
	if (s > e) {
		return NULL;
	}
	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root->left = BuildTreeFromArray(a, s, mid - 1);
	root->right = BuildTreeFromArray(a, mid + 1, e);
	return root;
}
int main() {
	node* root = BuildTree();
	cout << "Preorder of root:";
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;
	cout << CountNodes(root) << endl;
	cout << SumOfNodes(root) << endl;
	cout << Height(root) << endl;
	node* root1 = BuildTree();
	Mirror(root1);
	cout << "Preorder of root:";
	Preorder(root1);//we can see both preorders are equal
	//signifying we have created correct miror image
	cout << endl << Diameter(root) << endl;
	Pair p = FastDiameter(root);
	cout << p.diameter << " " << p.height << endl;
	Pair3 p1 = IsHeightBalanced(root);
	cout << p1.is_balanced << " " << p1.height << endl;
	int a[] = {9, 7, 2, 4, 1, 6, 5, 8, 10};
	node* root4 = BuildTreeFromArray(a, 0, 9 );
	Preorder(root4);
	cout << endl << Diameter(root4) << endl;
	cout << Height(root4);
}