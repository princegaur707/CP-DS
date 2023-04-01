#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
int s = 0;
string a;
int k;
int sum[1000005];

int Solve() {
  sum[0] = 1;
  for(int i = 0; i < a.length(); i++) {
    s += a[i] - '0';
    if(s >= k)
      ans += sum[s - k];
    cout << s << endl;
    sum[s]++;
  }
  return ans;
}
int32_t main() {
  cin >> k;
  cin >> a;
  cout << Solve();
}