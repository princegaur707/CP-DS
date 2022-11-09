class Solution {
public:
    int partitionDisjoint(vector<int>& nums)
    {
        int n = nums.size();
        int arr[n + 1];
        int brr[n + 1];
        arr[0] = INT_MIN;
        brr[n] = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            arr[i] = max(arr[i - 1], nums[i - 1]);
        }
        for(int i = n - 1; i >= 0; i--)
        {
            brr[i] = min(brr[i + 1], nums[i]);
        }
        int cnt = 1;
        while(arr[cnt] > brr[cnt])
        {
            cnt++;
        }
        return cnt;
    }
};