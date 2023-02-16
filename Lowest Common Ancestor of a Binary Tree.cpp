//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
//Approach: We will get the root(equal to p or q) if it is there in either of left or right branch
//otherwise it will return NULL which can be treated accordingly in 3 situations.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(root == NULL)
      return NULL;
    if(root == p or root == q)
      return root;
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    TreeNode *r = lowestCommonAncestor(root->right, p, q);
    if (l != NULL and r != NULL)
      return root;
    if(l != NULL)
      return l;
    else
      return r;
    }
};