#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; //no. of baloons
	int k; //no. of friends
	cin >> n >> k;
	string s;
	cin >> s;
	bool flag = true;
	unordered_map<char, int>m;
	for(int i = 0; i < n; i++)
	{
		m[s[i]]++;
		if(m[s[i]] > k)
		{
			flag = false;
		}
	}
	cout << (flag?"YES":"NO");
}