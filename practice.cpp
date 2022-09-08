#include<bits/stdc++.h>
using namespace std;
int IPC_Trainee()
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
    int Lect_Taken[n] = {0};
    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int trainer_taken = x.second;
        int Start_Date = D[trainer_taken];
        int End_Date = Start_Date + L[trainer_taken] - 1;
        //cout << "1 " << Start_Date << "  " << End_Date << endl;
        for(int i = Start_Date; i <= End_Date; i++)
        {
            auto f = s.lower_bound(i);
            if(f == s.end())
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
    int tot_Sadness = 0;
    for(int i = 0; i < n; i++)
    {
        tot_Sadness += (L[i] - Lect_Taken[i]) * S[i];
    }
    return tot_Sadness;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cout << IPC_Trainee() << endl;
    }
}