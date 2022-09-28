#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    cin >> n >> m;
    int arr[n + 1];
    int crr[n + 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int brr[m + 1];
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
    int start = s + m;
    int end = n;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        int temp = 0;
        for(int i = 0; i <= n; i++)
        {
            crr[i] = 0;
        }
        for(int i = mid; i > 0; i--)
        {
            if(arr[i] && !crr[arr[i]] && i > brr[arr[i]])
            {
                temp++;
                crr[arr[i]] = 1;
            }
        }
        if(m == temp)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if(end == n)
    {
        cout << "-1";
    }
    else
    {
        cout << end + 1;
    }
    return 0;
}