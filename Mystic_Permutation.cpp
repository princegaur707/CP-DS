#include <iostream>
#include<algorithm>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int a[1001] = {0}, b[1001] = {0};
	string k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int j = 0; j < n; j++) {
		if (a[j] == b[j])
			swap(b[j], b[j + 1]);
	}
	if (n == 1) {
		cout << -1 << endl;
		return;
	}
	if (b[n - 1] == 0) {//as we have inserted '0' till last so if swapping was done it will have '0'
		//which is not possible in ideal case as 
		b[n - 1] = b[n - 2];
		b[n - 2] = a[n - 1];
	}
	for (int j = 0; j < n; j++) 
		cout << b[j] << " ";
	cout << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}