//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    void Solve(vector<int>candidates, int target, vector<vector<int>>&ans, vector<int>&result,int index, int sum)
    {
       if(sum >= target)
       {
            if(sum == target)
            {
                ans.push_back(result);
            }
            return;
       }
        for(int i = index; i < candidates.size(); i++){
            sum += candidates[i];
            result.push_back(candidates[i]);
            Solve(candidates, target, ans, result, i, sum);
            sum -= candidates[i]; //Backtracking
            result.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>result;
        Solve(candidates, target, ans, result, 0, 0);
        return ans;
    }
};