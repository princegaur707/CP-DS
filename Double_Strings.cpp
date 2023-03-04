// https://codeforces.com/problemset/problem/1703/D
//string r = s1.substr(3, 2); -> Copy two characters of s1 (starting from position 3)
#include<bits/stdc++.h>
using namespace std;
string a[100005];
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		unordered_map<string, bool>m;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]] = 1;
		}
		for(int i = 0; i < n; i++) {
			bool f = 0;
			for(int j = 1; j < a[i].size(); j++) {//positions from 1 to size of that particular string
				if(m[a[i].substr(0, j)] && m[a[i].substr(j, a[i].size() - j)])
					f = 1;
			}
			cout << f;
		}
		cout << endl;
	}
}