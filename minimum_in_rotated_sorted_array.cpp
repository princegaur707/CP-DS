//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=size(nums)-1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if (nums[mid]<nums[h])
            {
            	h=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return(nums[l]);
    }
};