#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        int m;
        cin >> n >> m;
        int range1 = m;
        int range2 = m;
        int pt = 0;
        int flag = 1;
        for(int i = 0; i < n; i++)
        {
            int t;
            int l;
            int h;
            cin >> t >> l >> h;
            range1 = max(l, range1 - (t - pt));
            range2 = min(h, range2 + (t - pt));
            if(range1 > range2)
            {
                flag = 0;
            }
            pt = t;
        }
        cout << (flag?"YES\n" : "NO\n");
    }
}