//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//Using Recursion

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        if(N == 0 or W == 0)
            return 0;
        int option1 = 0 + knapSack(N - 1, W, val, wt);
        int option2 = INT_MIN;
        if(wt[N - 1] <= W)
            option2 = val[N - 1] + knapSack(N, W - wt[N - 1], val, wt);
        return max(option1, option2);
    }
};