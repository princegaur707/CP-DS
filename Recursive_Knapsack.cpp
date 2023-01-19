#include<bits/stdc++.h>
using namespace std;
int KnapSack(int W, int wt[], int val[], int N){
	if(N == 0 or W == 0){//BASE case
		return 0; //saying to add zero
	}
	if(wt[N - 1] > W)//weight of current Item is greater than the max. weight
		return 0 + KnapSack(W, wt, val, N - 1);
	int option1 = val[N - 1] + KnapSack(W - wt[N - 1], wt, val, N - 1);//Taking the current element
	int option2 = 0 + KnapSack(W, wt, val, N - 1);//Not taking the current element
	return max(option1, option2);
}
int main(){
	int wt[] = {4, 5, 1};
	int val[] = {1, 2, 3};
	cout << KnapSack(4, wt, val, 3);
}