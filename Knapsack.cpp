//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Using Recursion: 
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(n == 0 or W ==0){
           return 0;
       }
       if(wt[n - 1] > W){
           return 0 + knapSack(W, wt, val, n-1);
       }
       int option1 = val[n - 1] + knapSack(W-wt[n -1], wt, val, n - 1);
       int option2 = 0+ knapSack(W, wt, val, n - 1);
       return max(option1, option2);
    }
};