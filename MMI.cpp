#include<bits/stdc++.h>
using namespace std;
#define int long long
int x, y, GCD;

void EED(int a, int b) {
	//BASE CASE
	if(b == 0) {
		x = 1, y = 0;//values we found when b became zero
		GCD = a;
		return;
	}
	EED(b, a % b);
	int current_x = y;
	int current_y = x - ((a / b) * y);//By default we get a/b as floor value

	x = current_x;
	y = current_y;
}
int inverseModulo(int a, int m) {
	if(__gcd(a, m) != 1)//STL function gcd for checking whether such number exists or not
		return 0;//returning 0 to show NOT POSSIBLE
	EED(a, m);
	return (x + m) % m;//as we may get negative number too
}
int32_t main() {
	int a = 30;
	int b = 18;
	EED(a, b);
	cout << x << " " << y << endl;
	cout << inverseModulo(6, 7) << endl;
}
//ax + by = gcd(a, b)