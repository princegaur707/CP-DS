#include<bits/stdc++.h>
using namespace std;
#define int long long
int x, y, GCD;

void EED(int a, int b) {
	//BASE CASE
	if(b == 0) {
		x = 1, y = 0;
		GCD = a;
		return;
	}
	EED(b, a % b);
	int current_x = y;
	int current_y = x - ((a / b) * y);
	x = current_x;
	y = current_y;
}
int inverseModulo(int a, int m) {
	// if(__gcd(a, m) != 1) {
	// 	return 0;
	// }
	EED(a, m);
	return (x + m) % m;//to make sure positive value is returned
}
int32_t main() {
	int n;
	int p;
	int w;
	int d;
	cin >> n >> p >> w >> d;
	int x, y, z;
	int g = __gcd(w, d);
	if(p % g != 0) {//we know this from Diophantine equation
		cout << "-1" << endl;
		return 0;
	}
	if(n * w < p) {//if point are greater if even winning every match it is not possible
		cout << "-1" << endl;
		return 0;
	}
	p = p / g; //p = p' from now
	w = w / g; //w = w' from now
	d = d / g; //d = d' from now
	//now for y we know y = (p'' / d''), p'' = p'/w', d'' = d'/w'
	y = ((p % w) * inverseModulo(d, w)) % w;
	x = (p - y * d) / w;
	if(x + y > n) {
		cout << "-1" << endl;
		return 0;
	}
	if(x < 0) {
		cout << "-1" << endl;
		return 0;
	}
	z = n - (x + y);
	cout << x << " " << y << " " << z << " " << endl;

}