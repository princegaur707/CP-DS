class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) return true;
            if(nums[start] == nums[mid] and nums[mid] == nums[end])
            {
            	start++;
            	end --;
            }
            else if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target and nums[mid] > target)
                {
                    	end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if(nums[mid] < target and nums[end] >= target)
                {
                	start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
