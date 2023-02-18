class Solution {
public:
    int count = 0; 
    unordered_map<long, int>map;
    void CountPathSum(TreeNode* root, int TargetSum, long CurrentSum) {
      if(root == NULL)
        return;
      CurrentSum += root->val;
      if(TargetSum == CurrentSum)
        count++;
      if(map.count(CurrentSum - TargetSum))
        count += map[CurrentSum - TargetSum];
      map[CurrentSum]++;
      CountPathSum(root->left, TargetSum, CurrentSum);
      CountPathSum(root->right, TargetSum, CurrentSum);
      map[CurrentSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
      CountPathSum(root, targetSum, 0);
      return count;
    }
};
//count += map[CurrentSum - Targetsum] explantion:
//As we cannot rely on "count++" because once we create entry in map like map[-1] = 1
//will remain in it because we decrementing it while backtracking not deleting so there will
//still be entry in it as a result count++ will give wrong answer like in case of test case Tree: 1 -2 -3 
//target = -1 it will consider as - 1 available even when we will be at -3 so that's why map[sum-target] to get the real time value.

//map[CurrentSum]-- -> Backtracking