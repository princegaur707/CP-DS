#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; //no. of trips
    int a; 
    int b;
    int k;
    int f;
    map<pair<string, string>,int>m;
    cin >> n >> a >> b >> k >> f;
    string prev = "";
    int fare = 0;
    for(int i = 0; i < n; i++)
    {
        string start;
        string stop;
        cin >> start >> stop;
        if(start == prev)
        {
            fare = b;
        }
        else
        {
            fare = a;
        }
        prev = stop;
        if(start > stop)
        {
            swap(start, stop);
        }
        if(m.find({start, stop}) != m.end())
        {
            m[{start, stop}] += fare;
        }
        else
        {
            m[{start, stop}] = fare;
        }
    }
    vector<int>arr;
    int total = 0;
    for(auto x : m)
    {
        arr.push_back(x.second);
        total += x.second;
    }
    sort(arr.rbegin(), arr.rend());
    int len = arr.size();
    int i = 0;
    while( i < len and i < k)
    {
        if(arr[i] > f)
        {
            total = total - arr[i] + f;
            i++;
        }
        else
        {
            break;
        }
    }
    cout << total;
}