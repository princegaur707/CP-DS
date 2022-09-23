class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        long size = maxi - mini + 1;
        vector<int>freq(size, 0);
        for(int x : nums)
        {
            freq[x - mini]++;
        }
        int ans = 0;
        int count = k;
        for(int i = 0; i < freq.size(); i++)
        {
            if(count > 0)
            {
                if(freq[size - i - 1] > 0)
                    count = count - freq[size - i - 1];
            }
            if(count <= 0)
            {
                ans = (size - i - 1) + mini; // location + minimum
                break;
            }
        }
        return ans;
    }
};