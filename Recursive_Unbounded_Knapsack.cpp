#include<bits/stdc++.h>
using namespace std;
int knapSack(int N, int W, int val[], int wt[])
{
	if (N == 0 or W == 0) {
		return 0;
	}
	
	int Option1 = 0 + knapSack(N - 1, W, val, wt);//You choose not to pick this item

	//You decide to choose this item:
	int Option2 = INT_MIN;

	if (wt[N - 1] <= W) {
		Option2 = val[N - 1] + knapSack(N, W - wt[N - 1], val, wt);
	}
	return max(Option1, Option2);
}
int main(){
	int wt[] = {4, 5, 1};
	int val[] = {1, 2, 3};
	cout << knapSack(3, 4, val, wt);
}