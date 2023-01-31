//https://leetcode.com/problems/reorder-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* MidPoint(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void ReverseLinkedList(ListNode*&head) {
        ListNode* current = head;
        ListNode* temp;
        ListNode* prev = NULL;
        while(current != NULL) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return;
        ListNode* m = MidPoint(head);
        ListNode* h1 = m->next;
        ListNode* h = head;
        ReverseLinkedList(h1);
        m->next = NULL;
        ListNode* x;
        ListNode* y;
        while(h1) {
            x = h->next;
            y = h1->next;
            h->next = h1;
            h = x;
            h1->next = h;
            h1 = y;
        }
    }
};