#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int freq[100005] = {0};
        int sum = 0;
        freq[0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];//Prefix array ka kaam kar raha hu.

            sum = sum % n;
            sum = (sum + n) % n;//Prefix array ka mod;
            freq[sum]++;//Prefix array elements which are same.
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int value = freq[i];
            ans += (value * (value - 1)) / 2;
        }
        cout << ans << endl;
    }
}