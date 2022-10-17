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
        vector<int>res(nums.size(), 0);
        int start = 0;
        int end = nums.size() - 1;
        int cnt = 0;
        if(a >= 0){
            cnt = end;
        }
        while(start <= end) {
            int startNum = getNum(nums[start], a, b, c);
            int endNum = getNum(nums[end], a, b, c);
            if(a >= 0) {
                if(startNum >= endNum) {
                    cout << "1" << endl;
                    res[cnt--] = startNum; //cnt will be updated after operation due to post increment
                    start++;
                }
                else{
                    cout << "2" << endl;
                    res[cnt--] = endNum;
                    end--;
                }
            }
            else{
                if(startNum <= endNum) {
                    cout << "3" << endl;
                    res[cnt++] = startNum;
                    start++;
                }
                else{
                    cout << "4" << endl;
                    res[cnt++] = endNum;
                    end--;
                }
            }
            cout << res[0] << " " << res[1] << " " << res[2] <<" " << res[3] << endl;
        }
        return res;
    }
    int getNum(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};