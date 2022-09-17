#include<bits/stdc++.h>
using namespace std;
int Solve(int *a, int n)
{
	unordered_set<int>s;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		s.insert(a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		if(s.find(a[i] - 1) != s.end())
		{
			continue;
		}
		else
		{
			//Starting of sequence
			int x = a[i];
			int len = 0;
			while(s.count(x))
			{
				x++;
				len++;
			}
			ans = max(ans,len);
		}	
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << Solve(arr, n) << endl;
	}
}
// find function in map and set will give you the iterater
// or the address of the blocks where the element is found and lets say
// if the element is not found it will give you the last block
// which is .end();

// count function gives or returns true or false i.e boolean
// value if the element exits or not.