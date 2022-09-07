//https://www.codechef.com/problems/IPCTRAIN
#include<bits/stdc++.h>
using namespace std;
#define int long long
int IPC_Trainers()
{
	int n;
	int d;
	cin >> n >> d;
	int D[n];
	int L[n];
	int S[n];
	for(int i = 0; i < n; i++)
	{
		cin >> D[i] >> L[i] >> S[i];
	}
	priority_queue<pair<int, int>>pq;
	for(int i = 0; i < n; i++)
	{
		pq.push({S[i], i});
	}
	int Lect_Taken[n] = {0};
	set<int>s;
	for(int i = 1; i <= d; i++)
	{
		s.insert(i);
	}
	while(!pq.empty())
	{
		auto x = pq.top(); // Pair with highest sadness in priority queue.
		pq.pop();

		int trainer_taken = x.second;
		int start_date = D[trainer_taken];
		int end_date = start_date + L[trainer_taken] - 1; // -1 required as start date is also included in no. of lectures.
		for(int i = start_date; i <= end_date; i++)
		{
			auto f = s.lower_bound(i);
			if(f == s. end())
			{
				break;
			}
			else
			{
				Lect_Taken[trainer_taken]++;
				s.erase(f);
			}
		}
	}
	int total_sadness = 0;
	for(int i = 0; i < n; i++)
	{
		total_sadness += (L[i] - Lect_Taken[i]) * S[i];
	}
	return total_sadness;
}
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cout << IPC_Trainers() << endl;
	}
}