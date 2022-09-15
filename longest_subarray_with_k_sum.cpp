#include<bits/stdc++.h>
using namespace std;
int Solve(int *a, int n, int k)
{
    int pre = 0;
    int len = 0;
    unordered_map<int, int>m;
    for(int i = 0; i < n; i++)
    {
        pre += a[i];
        if(pre == k)
        {
            len = max(len, i + 1);
        }
        else if(m.find(pre - k) != m.end())
        {
            len = max(len, i - m[pre - k]);
        }
        else
        {
            m[pre] = i;
        }
    }
    return len;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >>arr[i];
        }
        cout << Solve(arr, n, k) << endl;
    }
}