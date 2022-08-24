#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; //no. of students 
	int m; //no. of coupons
	int x; //no. of coupons required for 100% off
	int y;//additional coupons we can get
	cin >> n >> m >> x >> y;
	int temp;
	temp = (m + y) / x;
	cout << temp;
}