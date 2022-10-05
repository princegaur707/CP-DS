//https://codeforces.com/contest/1251/problem/A
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string check;
		cin >> check;
		set<char>s; //Cannot take unordered as we will be matching string
		int n = check.length();
		for(int i = 0; i < n; i++)
		{
			if(check[i] == check[i + 1]) //why it is not throwing error for last element
			{
				i++;
			}
			else
			{
				s.insert(check[i]);
			}
		}
		for(auto x : s)
		{
			cout << x;
		}
		cout << endl;
	}
}
// Test Case:
// 4
// a
// zzaaz
// ccff
// cbddbb
