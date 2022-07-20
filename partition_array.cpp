class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        long long int left= -10000;
        long long int right= 10000;
        
        int size = right-left+1;
        vector<int>freq(size,0);
        
        for (int i=0; i<nums.size(); i++)
            freq[nums[i]-left]++;
        
        int total=0;
        int residue =0;
        
        for (int i=left; i<=right; i++)
        {
            if(freq[i-left]>0)
            {
            total+= (freq[i-left]+ 1 -residue)/2 *i;
            residue = (freq[i-left]+residue)%2;
            }
        }
        return total;
    }
};