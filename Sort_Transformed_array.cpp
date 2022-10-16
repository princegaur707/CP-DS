//https://www.lintcode.com/problem/906/description
class Solution {
public:
    /**
     * @param nums: a sorted array
     * @param a: 
     * @param b: 
     * @param c: 
     * @return: a sorted array
     */
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        // Write your code here
        vector<int> res(nums.size(), 0);
        int start = 0;
        int end = nums.size() - 1;
        int cnt = 0;
        if(a >= 0)
        {
            cnt = end;
        }
        while(start <= end) {
            int startNum = getNum(nums[start], a, b, c);
            int endNum = getNum(nums[end], a, b, c);
            if(a >= 0) {
                if(startNum >= endNum) {
                    res[cnt--] = startNum;
                    start++;
                }
                else{
                    res[cnt--] = endNum;
                    end--;
                }
            }
            else{
                if(startNum <= endNum) {
                    res[cnt++] = startNum;
                    start++;
                }
                else{
                    res[cnt++] = endNum;
                    end--;
                }
            }
            cout << 
        }
        return res;
    }
    int getNum(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};