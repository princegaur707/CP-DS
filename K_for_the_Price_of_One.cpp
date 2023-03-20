#include<bits/stdc++.h>
using namespace std;
int cost[200005];
int dp[200005];
int n, p, k;
int Solve() {
	sort(cost, cost + n);//1
	for(int i = 0; i < n; i++) {
		if(i < k - 1)//2 
			dp[i] = cost[i] + (i == 0 ? 0 : dp[i - 1]);//3
		else if(i == k - 1)//4
			dp[i] = cost[i];
		else//5
			dp[i] = cost[i] + dp[i - k];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(dp[i] <= p)
			ans = i + 1;//6 
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> p >> k;
		for(int i = 0; i < n; i++)
			cin >> cost[i];
		cout << Solve() << endl;
	}
}
/*
Explanations: 
1) Sorting is required as we will have to pay maximum of all items chosen till that point.
2) Till k items(k -1 as 0 based indexing) offer not applicable pay complete price.
3) For i = 0 there is no previous value to be added. Extra brackets are added due to the condition- In statement
	 if we apply tertary operator like '? :' As the values are not evaluated earlier arbitary value will be added 
	 to cost[i] and give wrong answer but after applying brackets firstly this thing will be resolved.
4) For i = k - 1(indirectly k no. of items) simply pay for max. of all current items i.e cost[i]
5) For i > k - 1 we will have to pay only for cost[i] and amount totally till 'i - k'(i - k denotes items out of 
	 bound of this current k no. of items), dp[i - k] represent price to be paid for these many items as offer can
	 be availed as many time customer want.
6) If price to be paid is less than equal to p then it is accepted answer 'i'-> denotes no. of items '+1'->because
	 of '0' based indexing.
*/