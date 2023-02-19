#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int k;
	cin >> n >> k;
	int arr[n];
	int length = 0;
	unordered_set<int>s;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);//why this sorting is necessary
	for(int i = 0; i < n; i++) {
		if(arr[i] % k != 0)
			s.insert(arr[i]);
		else if(s.count(arr[i] / k) == false)
			s.insert(arr[i]);
	}
	cout << s.size();
}