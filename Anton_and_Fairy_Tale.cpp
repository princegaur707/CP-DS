#include <iostream>
#include <cstdint>
#define int long long
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    if (n <= m)
    {
        cout << n << endl;
    }
    else
    {
        n -= m;
        int l = 0, r = 2e9;
        while (l < r)
        {
            int m = (l + r) / 2;
            int val = m * (m+1) / 2;
            if (val >= n) {
                r = m;
            }
            else
            {
                l = m+1;
            }
            //cout << m << " " << l <<" " << r << endl;
        }
        cout << l + m << endl;
    }
    return 0;
}