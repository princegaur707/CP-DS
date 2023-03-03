#include<bits/stdc++.h>
using namespace std;
int n, d;
int a[100005];
void Solve() {
	int total = 0;
	for(int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (total < 0)
				total = 0;
		}
		else {
			total += a[i];
			if(total > d) {
				cout << "-1";
				return;
			}
		}
	}
	int visit = 0;
	total = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			if(total < 0) {
				total = d;
				visit++;
			}
		}
		else 
			total += a[i];
			if(total > d)
				total = d;
	}
	cout << visit;
}
int main() {
	cin >> n >> d;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	Solve();
}