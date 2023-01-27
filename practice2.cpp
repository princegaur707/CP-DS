#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;

	node(int newdata){
		data = newdata;
		next = NULL;
	}
};
void InsertAtHead(node*&head, int value){
	node *n = new node(value);
	n->next = head;
	head = n;
}
void Print(node*&head){
	node *temp = head;
	while(temp != NULL){
		cout << temp->data <<"-->";
		temp = temp->next;
	}
}
int main(){
	int n;
	cin >> n;
	node *head = NULL;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		InsertAtHead(head, x);
	}
	Print(head);
}
