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
int32_t main() {
	int a = 30;
	int b = 18;
	EED(a, b);
	cout << x << " " << y << endl;
}
//ax + by = gcd(a, b)