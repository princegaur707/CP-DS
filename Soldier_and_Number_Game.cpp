#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin >> n;
	vector<int>arr;
	int pow2[62];
	pow2[0] = 1;
	for(int i = 1; i < 62; i++)
	{
		pow2[i] = pow2[i - 1] * 2; 
	}
	for(int d = 0; d < 62; d++)
	{
		int start = 1;
		int end = 1e10;
		int p = pow2[d] - 1;
		while(start <= end)
		{
			int no_of_matches;
			int mid = start + (end - start) / 2;
			int g = (mid * (mid - 1)) / 2;
			if(p != 0 and mid > LLONG_MAX / p)
			{
				no_of_matches = LLONG_MAX;
			}
			else
			{
				no_of_matches = p * mid + g;
			}

			if(no_of_matches == n)
			{
				if(mid & 1)
					arr.push_back(mid * (p + 1));
				break;
			}
			if(no_of_matches < n)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	if(arr.size() == 0)
	{
		cout << "-1";
	}
	else
	{
		sort(arr.begin(), arr.end());
		for(auto x : arr)
		{
			cout << x << endl;
		}
	}
	}