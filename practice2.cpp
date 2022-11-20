#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int freq[1007] = {0};
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			for(int i = 2; i <= n; i++)
			{
				if(x % i == 0)
					freq[i]++;
			}
		}
	}
}