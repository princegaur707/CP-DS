/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int pivot(MountainArray &a, int n)
    {
        int left = 0;
        int right = n-1;
        int ans = -1;
        int mid = 0;
        while(left < right)
        {
            mid = (left + right)/2;
            if(a.get(mid) < a.get(mid+1))
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
    
    int BSAO(MountainArray &a, int mid, int target, int n)
    {
        int left = 0;
        int right = mid;
        int ans = -1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(a.get(mid) == target)
            {
                ans = mid;
                break;
            }
            else if (a.get(mid) < target)
            {
                 left = mid + 1;  
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
    int BSDO(MountainArray &a, int mid, int target, int n)
    {
        int left = mid;
        int right = a.length();
        int ans = -1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (a.get(mid) == target)
            {
                ans = mid;
                break;
            }
            else if (a.get(mid) < target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
public:
    int findInMountainArray(int target, MountainArray &arr)
    {
        int n =  arr.length();
        int k = pivot(arr, n);
        int ans = BSAO(arr, k, target, n);
        if(ans > -1)
        {
            ans = BSDO(arr, k, target, n);
        }
        return ans;
    }
};