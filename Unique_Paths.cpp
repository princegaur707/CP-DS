//------------Top Down method---------------------
class Solution {
  int dp[101][101];
  int uniquePaths2(int m, int n) {
    if(m == 0 and n == 0)
      return 1;//return 1 denoting we found one valid unique path from start to end.
    if(m < 0 or n < 0)
      return 0;//cell outside the grid's boundary, we can return 0 denoting no valid path was found
    if(dp[m][n] != -1)
      return dp[m][n];
    return dp[m][n] = uniquePaths2(m - 1, n) + uniquePaths2(m, n - 1);
  }
public:
    int uniquePaths(int m, int n) {
      //dp[i][j]-> stores total no. of ways to reach (i, j)
      memset(dp, -1, sizeof(dp));
      return uniquePaths2(m - 1, n - 1);
    }
};
/*
--------------Bottom Up or iterative way------------------
In this we don't say to recursion to do we do ourselves
Taking 1 based indexing as it is simpler in iterative way
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        if(m == 1 and n == 1)
          return 1;
        for(int i = 1; i <= m; i++) {
          for(int j = 1; j <= n; j++) {
            if(i == 1 or j == 1)//1
              dp[i][j] = 1;
            else
              dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
          }
        }
        return dp[m][n];
    }
};
/*
Approach for iterative way:
I can reach (i, j) via (i - 1, j) or (i, j - 1) only
so, I need to find answer for these two firstly
1-> When we are at the top or left line pos there is
only one way to reach at this position either by left,
upward respectively
*/