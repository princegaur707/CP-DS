//https://leetcode.com/problems/linked-list-cycle-ii/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool HasCycle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast !=NULL and fast->next != NULL) {//fast should be ahead of 
        //fast->next as it will not create error for Test case:[] ans is -1
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if (HasCycle(head) == 0 or head == NULL or head->next == NULL) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
        }
};