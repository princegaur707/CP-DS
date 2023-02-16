//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
class Solution {
  unordered_map<TreeNode*, TreeNode*>m;
  unordered_set<TreeNode*>visited;
  vector<int>v;
  void Connect(TreeNode *root, TreeNode* parent) {
    if (root == NULL)
      return;
    m[root] = parent;
    Connect(root->left, root);
    Connect(root->right, root);
  }
  void dfs(TreeNode* target, int k) {
    if (target == NULL or visited.count(target) == 1)
      return;
    visited.insert(target);
    if (k == 0)
      v.push_back(target->val);
    dfs(target->left, k - 1);
    dfs(target->right, k - 1);
    dfs(m[target], k - 1);
  }
public:
  vector<int>ans;
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    Connect(root, NULL);
    dfs(target, k);
    return v;
  }
};