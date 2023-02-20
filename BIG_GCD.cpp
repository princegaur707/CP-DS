#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0? a : gcd(b, a % b);//we have written ourselves because 
	//in-built functions will not work for such big numbers
}
int32_t main() {
	int n;
	cin >> n;
	string a;//storing large number in the form of string
	cin >> a;
	int r = 0;
	if (n == 0)
		cout << a << endl; //b==0 print a (comparing with standard gcd approach)
	else {//else calculate a%b first
		for(int i = 0; i < a.size(); i++) {
			int n1 = r * 10 + (a[i] - 48);//char by char making integer from string and taking modulus 
			//with smaller number
			r = n1 % n;
		}
		cout << "n:" << n << endl;
		cout << "r:" << r << endl;
		cout << gcd(n, r);//Now Calculating gcd with standard approach
	}
	return 0;
}
