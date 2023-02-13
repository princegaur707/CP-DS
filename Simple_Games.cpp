#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int m;
	cin >> n >> m;
	if(n - m > m - 1) {
		cout << m + 1;
	}
	else if(n - m < m - 1) {
		cout << m - 1;
	}
	else {
		if(m - 1 != 0) {
			cout << m - 1;
		}
		else {
			cout << m;
		}
	}
}
//Approach: 'm' is the point choosen from 1 2 3 4 5 ..... n
//so, 'm-1' represent left half and 'n-m' represents right half
//if right half is bigger go for 'm+1' left half is bigger go for 'm-1'
//if both the halves are equal and 'm-1' exists go for it as it is said 
//to choose smaller otherwise 'm' is the solution