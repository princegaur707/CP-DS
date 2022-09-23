//https://leetcode.com/problems/non-decreasing-array/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i + 1] - nums[i] < 0)
            {
                //If order is gettting disturbed more than 1 times then say not possible directly by returning false
                if(count != 0)
                {
                    return false;
                }
                count++; //If we find anomaly in our order
                if(i > 0 and i != n - 2)
                {
                    if(nums[i - 1] > nums[i + 1] and nums[i] > nums[i + 2])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


//The simple approach of calculating maximum and then increment decreament_counter is failing because by seeing
//[3,4,2,3] only 4, I cannot decide decreament_counter, first 3 also matters while taking decision.

/* Approach:
We have excluded the cases the in which it is not possible to replace so , following exclusion approach.
[-1,4,2,3] In this we can replace '4' by '0,1,2' but we need to check if nums[i - 1] > nums[i + 1] then it is impossible
to replace it by any number by maintaining order.
[5,7,1,8] In this we can replace '1' by 7 so we neede to check if nums[i] > nums[i + 2] then it is impossible to 
replace by any number by maintaining order.
*/ 