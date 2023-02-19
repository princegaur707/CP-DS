#include<bits/stdc++.h>
using namespace std;
#define int long long
int fast_power_using_recursion(int a, int b) {
	if (b == 0)
		return 1;
	int x = fast_power_using_recursion(a, b / 2);
	if (b & 1)//will find whether no. is odd or even via last digit operation if odd 
		return a * x * x;
	return x * x;
}
int fast_power_using_bitmask(int a, int b) {
	int result = 1;
	while(b > 0) {
		if (b & 1) {
			result = result * a;
		}
		a = a * a;//increasing place value
		b = b >> 1;//removing last element
	}
	return result;
}
int fast_power_using_bitmask_and_modulous(int a, int b, int m) {
	int result = 1;
	while(b > 0) {
		if(b & 1) {
			result = (((result % m) * (a % m)) % m); 
		}
		a = ((a % m) * (a % m) % m);
		b = b >> 1;
	}
	return result;
}
int32_t main() {
	int a, b;
	cin >> a >> b;
	cout << fast_power_using_recursion(a, b) << endl;
	cout << fast_power_using_bitmask(a, b) << endl;
	cout << fast_power_using_bitmask_and_modulous(a, b, 100);
}
//Every odd no. wil have the last bit as 1