class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int a[n];
        for(int i = 0; i < n; i++) {
          a[i] = 1;
        }
        //Left to Right comparison:
        for(int i = 1; i < n; i++) {
          if(ratings[i] > ratings[i - 1])
            a[i] = a[i - 1] + 1;
        }
        //Right to Left comparison:
        for(int i = n - 2; i >= 0; i--) {
          if(ratings[i] > ratings[i + 1])
            a[i] = max(a[i], a[i + 1] + 1);
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
          sum += a[i];
        return sum;
    }
};