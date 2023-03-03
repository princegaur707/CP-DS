#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	unordered_map<string, int>m;
	for(int i = 0; i < n; i++) {
		string x;
		cin >> x;
		if(!m.count(x)) {
			cout << "OK" << endl;
			m[x] = 0;
		}
		else {
			string temp = x;
			m[x]++;
			temp = temp + to_string(m[x]);
			cout << temp << endl;
		}
	}
}