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
        //cout << flag << "\t";
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
                break;	//this break is causing issue but don't know why
                		//eventhough flag is updated for next test case
            }
            pt = t;
        }
        cout << (flag?"YES\n" : "NO\n");
    }
}
/*
5
2 9
12 -1 10
15 -1 10
2 7
5 -10 -8
17 -1 5
2 10
8 -8 7
16 -10 -5
2 -8
6 -6 7
18 -10 6
2 5
13 -10 -8
16 0 0

Answer getting :
YES	
NO
NO --------*Here we should get yes due to break this issue is coming but why
YES
NO

*/
