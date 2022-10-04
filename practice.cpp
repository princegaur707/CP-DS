//https://codeforces.com/contest/672/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n; //no. of citizens
bool check1(int arr[], int mid, int k)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > mid)
        {
            sum += arr[i] - mid;
        }
    }
    return sum <= k;
}
bool check2(int arr[], int mid, int k)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < mid)
        {
            sum += mid - arr[i];
        }
    }
    return sum <= k;
}
int32_t main()
{
    int k; //no. of days left for retirement
    cin >> n >> k;
    int arr[n];
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
        sum += arr[i];
    }
    int start = (sum + n - 1) / n;
    //cout << "start: " << start << endl;
    int end = maxi;
    int ans1;
    int ans2;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        //cout << " mid : " << mid;
        if(check1(arr, mid, k))
        {
            //cout << "  check1" << endl;
            ans1 = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    start = mini;
    end = sum / n;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        //cout << " mid : " << mid;
        if(check2(arr, mid, k))
        {
            //cout << "  check2" << endl;
            ans2 = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ans1 - ans2;
}