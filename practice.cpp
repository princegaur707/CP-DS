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
			for(int j = 0; j < a[i].size() - 1; j++) {
				cout << "j: " << j << endl;
				if(m[a[i].substr(0, j + 1)] && m[a[i].substr(j + 1, a[i].size() - j)]){
					// cout << "OUT: " << j << " " << a[i].size() - j << endl;
					f = 1;
				}
			}
			// cout << f;
		}
		cout << endl;
	}
}