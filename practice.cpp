#include<bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
    int n;  //no. of days
    int m;  //no. of exams
    cin >> n >> m;
    int arr[n + 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int brr[n + 1];
    int s = 0;
    for(int i = 1; i <= m; i++)
    {
        cin >> brr[i];
        s += brr[i];
    }
    if(n < s + m)
    {
        cout << "-1";
        return 0;
    }
    int left = s + m;
    int right = n;
    int ans = -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int k = 0;
        for(int i = 1; i <= n; i++)
        {
            v[i] = 0;
        }
        for(int i = mid; i > 0; i--)
        {
            if(arr[i] && !v[arr[i]] && i > brr[arr[i]])
            {
                k++;
                v[arr[i]] = 1;
            }
        }
        if(k == m)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(right == n)
    {
        cout << "-1";
    }
    else
    {
        cout << right + 1;
    }
}