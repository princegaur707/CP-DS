//https://codeforces.com/contest/325/problem/B
//Other's answer at bottom
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin >> n;
	vector<int>arr;
	int cnt = 0;
	for(int i = 1; i <= 2 * n; i++)
	{
		int flag = 0;
		int match_count = 0;
		int mid = i;
		int team_count = mid;
		while(mid % 2 == 0)
		{
			flag++;
			mid = mid / 2;
			match_count += mid;
		}
		match_count += (mid * (mid - 1)) / 2;
		if(match_count == n)
		{
			arr.push_back(team_count);
		}
	}
	if(arr.size())
	{
		for(auto x : arr)
		{
			cout << x << endl;
		}
	}
	else
	{
		cout << "-1";
	}
}
/*#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
typedef long long LL;
const int N = 1005;
const LL INF = 1e18;
const LL R = 3*1e9;
 
LL S[N];
int cnt;
 
void Binary_Search(LL n)
{
    for(int k=0;k<63;k++)
    {
        LL l = 1;
        LL r = R;
        if(k >= 30) r = INF >> k;
        while(l <= r)
        {
            LL m = (l + r) >> 1;
            LL ans = (((LL)1 << k) - 1) * m * 2 + m * (m - 1);
            if(ans > 2*n) r = m - 1;
            else if(ans < 2*n) l = m + 1;
            else
            {
                if(m&1) S[cnt++] = m * ((LL)1 << k);
                break;
            }
        }
    }
}
 
int main()
{
    LL n;
    cin>>n;
    cnt = 0;
    Binary_Search(n);
    sort(S,S+cnt);
    if(cnt == 0) puts("-1");
    else
    {
        for(int i=0;i<cnt;i++)
           cout<<S[i]<<endl;
    }
    return 0;
}*/