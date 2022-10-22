#include<bits/stdc++.h>
using namespace std;
#define int long long
int k;
int V(int mid)
    {
      return (2 * k - mid - 1) * mid / 2 + 1; //unable to understand this
    }
int32_t main() 
{
    int n;
    int x;
    cin >> n >> k;
    int start = 0;
    int end = k;
    while(start < end)
    {
        int mid = (start + end) / 2;
        //cout << start << " " << mid << " " << end << endl;
        if(n > V(mid))
            start = mid + 1;
        else
            end = mid;
    }
    cout << (start < k? start : -1);
}