#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>pq;
	for(int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		pq.push(x);
	}
	while(!pq.empty()) {
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		if(x < y){
			cout << y;
			return 0; 
		}
	}
	cout << "NO";
}
//Using set
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
// 	int n;
// 	cin >> n;
// 	set<int>s;
// 	for(int i = 0; i < n; i++){
// 		int x;
// 		cin >> x;
// 		s.insert(x);
// 	}
// 	vector<int>arr;
// 	for(auto x : s)
// 		arr.push_back(x);
// 	if(arr.size() < 2) {
// 		cout << "NO";
// 		return 0;
// 	}
// 	if(arr[1] > arr[0])
// 		cout << arr[1];
// 	else
// 		cout << "NO";
// }