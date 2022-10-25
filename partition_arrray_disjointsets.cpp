/* https://leetcode.com/problems/partition-array-into-disjoint-intervals/
-----------------------------------------------------------------------------------
                            SOLUTION 1
-----------------------------------------------------------------------------------*/
class Solution {
public:
    int partitionDisjoint(vector<int>& a) 
    {
        int left_max=a[0], curr_max=a[0], len=0;
        for (int i=1;i<size(a); i++)
        {
            curr_max= max(a[i],curr_max);
            if (a[i]<left_max)
            {
                len=i;
                left_max=curr_max;           
            }
        }
        return len+1;
    }
};
/*In this we followed approach that if some no. is less than the left_max then it will definitely
required to be added to left side so we needed left_max  but if the no. is greater than left_max
then we cannot say anything about it as there can be any no. after it smaller than the left_max so
we will need curr_max as to have knowledge of current maximum which we will need to consider as left_max
if some number after it is found to be less than left_max.
 
 ------------------------------------------------------------------------------------
                            SOLUTION 2
 ------------------------------------------------------------------------------------*/
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
            arr[i] = max(arr[i - 1], nums[i - 1]); //calculating left maximum
        }
        for(int i = n - 1; i >= 0; i--)
        {
            brr[i] = min(brr[i + 1], nums[i]); //calculating right minimum
        }
        int cnt = 1;
        while(arr[cnt] > brr[cnt]) //Till when the the left max is greater than right min continue
        {
            cnt++;
        }
        return cnt;
    }
};