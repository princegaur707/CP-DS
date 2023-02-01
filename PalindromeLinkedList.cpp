//https://leetcode.com/problems/palindrome-linked-list/description/
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
        // ListNode* fast = head; This gives first mid point which will create in tc [1,2]
        ListNode* fast = head->next;//so to overcome above issue we need this second mid point
        while (fast and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void ReverseLinkedList(ListNode*&head) {
        ListNode* current = head;
        ListNode* temp;
        ListNode* prev = NULL;
        while (current != NULL) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL or head->next == NULL)
            return true;
        ListNode* mid = MidPoint(head);
        ListNode* h = head;
        ListNode* h1 = mid->next;
        ReverseLinkedList(h1);
        mid->next = NULL;
        while (h and h1) {
            if (h->val != h1->val)
                return false;
            h = h->next;
            h1 = h1->next;
        }
        return true;
    }
};