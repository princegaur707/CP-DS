//https://leetcode.com/problems/linked-list-components/description/
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
public:
    
  int numComponents(ListNode* head, vector<int>& nums) {
    int freq[100005] = {0};
    for(int i = 0; i < nums.size(); i++) {
      freq[nums[i]]++;
    }
    int component = 0;
    bool flag = 0;
    ListNode* temp = head;
    while(temp != NULL) {
      if(freq[temp->val] and !flag) {//increase count of component when you don't have the element in num
        //but is the next element in the linked list 
        component++;
        flag = 1;
      }
      if(!freq[temp->val])//since this element in not in nums it means now new component will be formed so let enable
        //it to increase by doing doing flag false
        flag = 0;
      temp = temp->next;
    }
    return count;
  }
};