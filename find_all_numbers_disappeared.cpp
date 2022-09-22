//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            res[nums[i]] = 1;
        }
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            if(res[i] == 0)
            {
                res[count++] = i;//Post increament so it will work too.
            }
        }
        res.erase(res.begin() + count, res.end());
        return res;
    }
};