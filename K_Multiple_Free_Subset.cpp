//Approach: 
//firstly check if no. is divisible by k or not
//if Not divisible? directly insert no issue in set as it can never have k multiple
//if Yes, divisible? check whether it's corresponding no. is present in set or not
//if Not present? Insert this no. too into the set no issues 
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
	for(int x : s)
		cout << x << " ";
	cout << endl;
	cout << s.size();
}