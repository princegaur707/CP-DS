// https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;
int Frog1(int arr[], int pos){
	if(pos == 0){
		return 0;
	}
	int option1 = INT_MAX, option2 = INT_MAX;
	if(pos - 1 >= 0)
		option1 = abs(arr[pos] - arr[pos - 1]) + Frog1(arr, pos - 1);
	if(pos - 2 >= 0)
		option2 = abs(arr[pos] - arr[pos - 2]) + Frog1(arr, pos - 2);
	return(min(option1, option2));
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cout << Frog1(arr, n - 1);
}