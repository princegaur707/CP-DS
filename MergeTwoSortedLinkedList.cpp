// https://leetcode.com/problems/merge-two-sorted-lists/
//This one is better as this do not requires creation of another linked list
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        if(head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        if(head1->val > head2->val) {
            head2->next = mergeTwoLists(head1, head2->next);
                return head2;
        }
        return NULL;
    }
};
//Normal Method->By creating new LinkedList
class Solution {
    void Insert(ListNode*&head, int value) {
        if (head == NULL) {
            head = new ListNode(value);
            return;
        }
        ListNode *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        } 
        temp->next = new ListNode(value);
        return;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode *temp1 = list1;
     ListNode *temp2 = list2;
     ListNode *head = NULL;
     while (temp1 != NULL or temp2 != NULL) {
         if(temp1 == NULL and temp2 != NULL) {
             Insert(head, temp2->val);
             temp2 = temp2->next;
             continue;
         }
         if(temp2 == NULL and temp1 != NULL) {
             Insert(head, temp1->val);
             temp1 = temp1->next;
             continue;
         }
         if (temp1->val < temp2->val) {
            Insert(head, temp1->val);
            temp1 = temp1->next;
         }
         else if(temp1->val > temp2->val) {
             Insert(head, temp2->val);
             temp2 = temp2->next;
         }
         else {
             Insert(head, temp1->val);
             Insert(head, temp2->val);
             temp1 = temp1->next;
             temp2 = temp2->next;
         }
     }
     return head;
    }
};