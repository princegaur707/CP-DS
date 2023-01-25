#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;//self refrencing pointer -> type of pointer is dictated by the type of data is 
	//storing as we know it is storing address to the next node it's 
	//type is node.

	node(int inputdata){ //creating constructor
		data = inputdata;
		next = NULL;
	}
};
void InsertAtHead(node*&head, int value)//pass by reference
{
	node *n = new node(value); //creating dynamic node prefer this in LL
	//this is also a way of calling constructor
	n->next = head;
	head = n;
}
void Print(node*&head)//it is usually passed by reference in question so we keep it like this
{
	node*temp = head;//If we will iterate directly by head we will lost it
	while(temp!=NULL)
	{
		cout << (*temp).data << "-->";
		temp = temp->next;
	}
}
int main()
{
	int n;
	cin >> n;
	node * head = NULL;
	//head name's node block is there which is storing NULL
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		InsertAtHead(head, x);
	}
	Print(head);
	cout << endl;
	Print(head);
}

//50->40->30->20->10