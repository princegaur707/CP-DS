#include<bits/stdc++.h>
using namespace std;
int IPC_Trainer()
{
    int n;
    int d;
    cin >> n >> d;
    int D[n];
    int L[n];
    int S[n];
    priority_queue<pair<int, int>>pq;
    for(int i = 0; i < n; i++)
    {
        cin >> D[i] >> L[i] >> S[i];
        pq.push({S[i], i});
    }
    set<int>s;
    for(int i = 1; i <= d; i++)
    {
        s.insert(i);
    }
    int Lecture_taken[n] = {0};
    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int trainer_taken = x.second;
        int start_date = D[trainer_taken];
        int stop_date = start_date + L[trainer_taken] - 1;
        for(int i = start_date; i <= stop_date; i++)
        {
            auto t = s.lower_bound(i);
            if(t == s.end())
            {
                break;
            }
            else
            {
                s.erase(t);
                Lecture_taken[trainer_taken]++;
            }
        }
    }
    int total_sadness = 0;
    for(int i = 0; i < n; i++)
    {
        total_sadness += (L[i] - Lecture_taken[i]) * S[i];
    }
    return total_sadness;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cout << IPC_Trainer() << endl;
    }
}