//https://codeforces.com/contest/287/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    int k;
    cin >> n >> k;
    if (n == 1)
    {
    	cout << 0;
    	return 0;
    }
    int sum = 1;
    for (int i = k - 1; i > 0; i--)
    {
 
 
        sum += i;
        if (sum >= n)
        {
        	cout << k - i;
        	return 0;
        }
    }
     cout << -1;
    return 0;
}