#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	int r = 0;
	if(n == 0)
		cout << a << endl;
	else {
		for(int i = 0; i < a.size(); i++) {
			int n1 = r * 10 + (a[i] - 48);
			r = n1 % n;
		}
		cout << gcd(n, r) << endl;
	}
	return 0;
}