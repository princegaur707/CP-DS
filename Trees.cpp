#include<bits/stdc++.h>
using namespace std;

class node{
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
node* buildTree() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	}
	else {
		node* root = new node(x);
		root->left = buildTree();
		root->right = buildTree();
		return root;//At every point 
		//we must have the referece to the root
	}
}
void Preorder(node* root) {
	if(root == NULL) {//hitting the base case(deepest point)
		return;
	}
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}
void Inorder(node* root) {
	if(root == NULL) {
		return;
	}
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
void Postorder(node* root) {
	if(root == NULL) {
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
	if(root == NULL) {
		return 0;
	}	
	int x = Height(root->left);
	int y = Height(root->right);
	int ans = 1 + max(x, y);
	return ans;
}
void Mirror(node* root) {
	if(root == NULL) {
		return;
	}
	swap(root->left, root->right);
	Mirror(root->left);
	Mirror(root->right);
}
int Diameter(node* root) {
	if(root == NULL) {
		return 0;
	}
	int option1 = Diameter(root->left);
	int option2 = Diameter(root->right);
	int option3 = Height(root->left) + Height(root->right);

	return max(option1, max(option2, option3));
}
int main() {
	node* root = buildTree();
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
	node* root1 = buildTree();
	Mirror(root1);
	cout << "Preorder of root:";
	Preorder(root1);//we can see both preorders are equal
	//signifying we have created correct miror image
	cout << endl << Diameter(root) << endl;
} 