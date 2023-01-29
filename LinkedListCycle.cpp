#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;

	node(int newdata) {
		data = newdata;
		next = NULL;
	}
};
void InsertAtTail(node*&head, int value) {
	if (head == NULL) {
		head = new node(value);
		return;
	}
	node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new node(value);
	return;
}
void CreateCycle(node *head) {
	node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head->next->next;
}

bool IsCycle(node *head){
	node *fast = head;
	node *slow = head;
	while (fast->next != NULL and fast != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			return true;
		}
	}
	return false;
}
void BreakCycle(node *head){
	node *fast = head;
	node *slow = head;
	while (fast != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			break;
		}
	}
	slow = head;//moved slow to the start of LL
	node *prev = head;//
	while(prev->next != fast) {
		prev = prev->next;//to insert NULL to the last we will need to track it
	}
	while(slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}
	prev->next = NULL;
}
void Print (node*&head) {
	node *temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
}

int main() {
	int n;
	cin >> n;
	node *head = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		InsertAtTail(head, x);
	}
	Print(head);
	cout << endl;
	CreateCycle(head);
	cout << IsCycle(head) << endl;
	BreakCycle(head);
	cout << IsCycle(head) << endl;
}
