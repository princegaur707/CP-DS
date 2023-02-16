//https://leetcode.com/problems/path-sum-ii/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    void FindPath(TreeNode* root, int targetSum) {
      if (root == NULL) {
        return;
      }
      v.push_back(root->val);
      for(auto x : v)
        cout << x << " ";
      cout << endl;
      if(root->val == targetSum and !root->left and !root->right) {//As this is leaf node so no left and right exist
        cout << "c" << endl;
        ans.push_back(v);
      }
      else {
        FindPath(root->left, targetSum - root->val);
        cout << "b" << endl;
        FindPath(root->right, targetSum - root->val);
      }
      cout << "a" << endl;
      v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      FindPath(root, targetSum);
      return ans;
    }
};