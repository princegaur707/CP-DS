//https://codeforces.com/problemset/problem/847/K
#include<bits/stdc++.h>
using namespace std;
#define int long long
int TravelCard()
{
	int n;
	int a;
	int b;
	int k;
	int f;
	cin >> n >> a >> b >> k >> f;
	int total = 0;
	string prev = "";
	map<pair<string, string>, int>m;
	for(int i = 0; i < n; i++)
	{
		int cost;
		string start;
		string end;
		cin >> start >> end;
		if(prev == start)
		{
			cost = b;
		}
		else 
		{
			cost = a;
		}
		prev = end; //must update prev here otherwise position may change
		if(start > end)
		{
			swap(start, end);//swapping to store pairs in map
		}
		if(m.find({start, end}) != m.end())
		{
			m[make_pair(start, end)] += cost;
		}
		else
		{
			m[make_pair(start, end)] = cost;
		}
	}
	vector<int>v;
	for(auto x	: m)
	{
		v.push_back(x.second);
		total += x.second;
	}
	int len = v.size();
	sort(v.rbegin(), v.rend());//reverse sorting so as to take the pass for maximum fare route
	int t = 0;
	while(t < len and t < k)
	{
		if (v[t] > f)
		{
			total = total - v[t] + f;
			t++;
		}
		else
		{
			break; //no need to move ahead as array is reverse sorted remaining will be already less than these
		}
	}
	return total;
}
int32_t main()
{
	cout << TravelCard() << endl;
}