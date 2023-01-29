#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;//self referencing pointer -> type of pointer is dictated by the type of data it
	//is storing as we know it is storing address to the next node it's type is node.

	node(int inputdata) { //creating constructor
		data = inputdata;
		next = NULL;
	}
};
void InsertAtHead(node*&head, int value)//pass by reference:changes will be reflected
{
	node *n = new node(value); //creating dynamic node prefer this in LL
	//this is also a way of calling constructor
	n->next = head;
	head = n;
}
void PrintLL(node*&head)//it is usually passed by reference in question so we keep it like this
{
	node *temp = head;//If we will iterate directly by head we will lost it
	while (temp != NULL)
	{
		if (temp->next == NULL) { //for not getting "-->" at last
			cout << temp->data;
			return;
		}
		cout << (*temp).data << "-->";//temp->data is short form for this
		temp = temp->next;
	}
}
void InsertAtTail(node*&head, int value) {
	if (head == NULL) { //If LL is empty make node as head
		head = new node(value);
		return;
	}
	node *temp = head;//since there already exist some LL so go to last then insert
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new node(value);
	return;
}
int len(node *head) {
	int length = 0;
	node *temp = head;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}
	return length;
}
int midPoint(node *head) {
	int mid = len(head) / 2;
	node *temp = head;
	while (mid > 0)
	{
		temp = temp->next;
		mid--;
	}
	return temp->data;
}
node* midPoint1(node *head) { //returning mid node
	int mid = len(head) / 2;
	node *temp = head;
	while (mid > 0)
	{
		temp = temp->next;
		mid--;
	}
	return temp;
}
//In Above we did 2 iterations firstly found length and
//then again iterated for finding the mid
//for finding mid in one iteration->
//slow = x;
//fast = 2x;--when this one will be exhausted
node* midPoint2(node *head) {
	node* slow = head;
	node* fast = head;
	//for odd length	for even length
	while (fast->next->next != NULL and fast != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

bool SearchIterative(node* head, int key) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool SearchRecursive(node* head, int key) {
	node* temp = head;
	if (temp == NULL) {
		return false;
	}
	if (temp->data == key) {
		return true;
	}
	else
	{
		return SearchRecursive(head->next, key);
	}
}
void ReverseLinkedList(node*&head) {
	node* current = head;
	node* temp;
	node* prev = NULL;
	while (current != NULL) {
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
}
node* RecursiveReverseLinkedList(node* head) {//I am returning node 
	//so no need to call by reference
	if(head == NULL or head->next == NULL) {//Either LL is of  
		//zero length or one length
		return head;
	}
	node* next_head = RecursiveReverseLinkedList(head->next);
	//I said to move one step ahead
	node* current = head;
	current->next->next = current;
	current->next = NULL;
	return next_head;	
}
int main()
{
	int n;
	cin >> n;
	node *head = NULL;
	node *head1 = NULL;//creating new LL for InsertAtTail
	//head name's node block is there which is storing NULL
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		InsertAtHead(head, x);
		InsertAtTail(head1, x);
	}
	PrintLL(head);
	cout << endl;
	cout << "a " << len(head) << endl;
	PrintLL(head1);
	cout << endl;
	cout << SearchIterative(head, 4) << endl;
	cout << SearchRecursive(head, 3) << endl;
	cout << "b " << midPoint(head) << endl;
	// cout << "c " << midPoint1(head) << endl;//will print address
	node *x = midPoint1(head);
	cout << "d " << x->data << endl;
	node *y = midPoint2(head);
	cout << "e " << y->data;
	cout << endl;
	ReverseLinkedList(head);
	PrintLL(head);//printing after reversing;
	cout << endl;
	node* head2 = RecursiveReverseLinkedList(head);
	PrintLL(head2);
}
