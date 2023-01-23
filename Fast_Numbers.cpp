#include<bits/stdc++.h>
using namespace std;
#define int long long

int fast_power_using_recursion(int a, int b)
{
	if(b == 0){
		// cout << "HI" << endl;
		return 1;
	}
	// cout << "Hello" << " b:"  << b << endl;
	int x = fast_power_using_recursion(a, b / 2);

	if(b % 2 == 1){
		// cout << "1" << " "  << a * x * x << endl;
		return a * x * x;
	}
	else{
		// cout << "2" << " " << x * x << endl;
		return x * x;
	}
}
int32_t main()
{
	int x, y;
	cin >> x >> y;
	cout << fast_power_using_recursion(x, y);
}
// Hello b:15
// Hello b:7
// Hello b:3
// Hello b:1
// HI
// 1 2
// 1 8
// 1 128
// 1 32768
// 32768