https://leetcode.com/problems/find-in-mountain-array/
class Solution {
    int pivot(MountainArray &arr, int start, int end)
    {   
        int ans = -1;
        while(start < end)
        {
            int mid = (start + end) / 2;
            if(arr.get(mid) < arr.get(mid + 1))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
    
    int BSAO(MountainArray &arr, int start, int end, int target
)    {
        int ans = -1;
        while(start < end)
        {
            int mid = (start + end) / 2;
            if(arr.get(mid) == target)
            {
                return mid;   
            }
            else if(arr.get(mid) < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        } 
        return ans;
    }
    
    int BSDO (MountainArray &arr, int start, int end, int target)
    {
        int ans = -1;
        while(start < end)
        {
            int mid = (start + end) / 2;
            if(arr.get(mid) == target)
            {
                return mid;
            }
            else if(arr.get(mid) < target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
     
        int n = mountainArr.length();
        int k = pivot(mountainArr, 0, n-1);
        int ans = BSAO(mountainArr, 0, k, target);
        if ( ans == -1)
        {
            return BSDO(mountainArr, k, n, target);
        }
        return ans;
    }
};