//https://leetcode.com/problems/split-linked-list-in-parts/description/
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
  int LengthLL(ListNode* head) { //Function for calculating length of Linked List
    int length = 0;
    while (head != NULL) {
      length++;
      head = head->next;
    }
    return length;
  }
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = LengthLL(head);
    int parts = n / k;//if length = 3 and k = 5 parts = 0
    int remaining = n % k;
    int elements = n / k;
    vector<ListNode*> ans;
    if (parts == 0) { //In this case every  node will have max one element remaining nodes
      //will have NULL only
      for (int i = 0; i < k; i++) {
        if (head) {
          ListNode *n = head->next;//store address of next node
          head->next = NULL;
          ans.push_back(head);
          head = n;
        }
        else {
          ans.push_back(NULL);
        }
      }
    }
    else {
      while (head) {
        ans.push_back(head);
        int x = remaining > 0 ? 1 : 0;
        remaining--;
        for (int i = 1; i < elements + x; i++) { //i started from 1 as one element(head) is already inserted
          head = head->next;
        }
        ListNode *n = head->next;
        head->next = NULL;
        head = n;
      }
    }
    return ans;
  }
};