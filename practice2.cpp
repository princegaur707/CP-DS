#include<bits/stdc++.h>
using namespace std;
int LongestSubWithZeroSum(int *arr, int n)
{
    int pre = 0;
    int len = 0;
    unordered_map<int,int>m;
    for(int i = 0; i < n; i++)
    {
        pre += arr[i];
        if(pre == 0)
        {
            len = max(len, i + 1);
        }
        else if(m.find(pre) != m.end())
        {
            len = max(len, i - m[pre]);
        }
        else
        {
            m[pre] = i;
        }
        // for (auto x: m)
        //     cout << " pre: " << x.first << " index: " << x.second << endl;
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
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << LongestSubWithZeroSum(arr, n) << endl;
    }   
}