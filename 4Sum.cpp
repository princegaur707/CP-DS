//https://leetcode.com/problems/4sum/
//TC : O(N^3)
//Approach: Set the first two numbers and then use 2 pointer approach to get the other two numbers
//EXP 1: Not to forget the elimination of duplicates which can be done easily with the help of matching the next element of array
//EXP 2: We need to do the eliination of duplicates of that numbers once the use of that loop is ended.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //sort to get the idea where to move forward of backward
        vector<vector<int>>ans; // In this data type we have to return the answer
        for(auto x:nums)cout << x << " ";
        cout << endl;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int num1 = nums[i];
            for(int j = i + 1; j < n; j++)
            {
                int num2 = nums[j];
                long long int target1 = nums[i] + nums[j];
                long long int target2 = target - target1;
                int start = j + 1;
                int end = n - 1;
                while(start < end)
                {
                    long long int total = nums[start] + nums[end];
                    if(total < target2)
                    {
                        //As array is sorted we will get higher total if we moved ahead in array
                        start++;
                    }
                    else if(total > target2)
                    {
                        //As array is sorted we will get lower total if we moved back in array
                        end--;
                    }
                    else
                    {
                        //means total is equal to required target 2
                        //now push these elements to the vector array
                        vector<int>quad;
                        quad.push_back(num1);
                        quad.push_back(num2);
                        quad.push_back(nums[start]);
                        quad.push_back(nums[end]);
                        ans.push_back(quad);
                        while(start < end and nums[start] == quad[2]) //EXP 1
                        {
                            start++;
                        }
                        while(start < end and nums[end] == quad[3])
                        {
                            end--;
                        }
                    }
                }
                while(j + 1 < n and nums[j + 1] == nums[j]) //EXP 2
                {
                    j++;
                }
            }
            while(i + 1 < n and nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return ans;        
    }
};