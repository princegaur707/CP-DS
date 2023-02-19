//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
class Solution {
public:
  int ans = INT_MIN;
    int helper(TreeNode *root) {
      if (root == NULL)
        return 0;
      int maxLeft = helper(root->left);
      int maxRight = helper(root->right);
      ans = max({ans, root->val, maxLeft + root->val, maxRight + root->val, maxLeft + maxRight + root->val});//1
      return max({root->val, maxLeft + root->val, maxRight + root->val});//2
    }
    int maxPathSum(TreeNode* root) {
      helper(root);
      return ans;
    }
};
//Explanation:
//1-> we need to consider all the possibilities ans, root->val(as node alone is also a path),left , right as well as left + right 
//2-> here we will not consider the left + right because left + right + above node will not make any valid path
//1 and 2-> root-> val is considered in all cases as then only path will be continuous or valid