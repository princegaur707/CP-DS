//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while(start < end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] < nums[end])
            {
                end = mid;
            }
            else if(nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end--;
            }
        }
        return nums[start];
    }
};

//We can understand the addition of end-- with the help of test cases
//[1,3,3] and [3,3,1,3]