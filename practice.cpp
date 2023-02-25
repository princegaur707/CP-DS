#include<bits/stdc++.h>
using namespace std;
#define int long long
class Activity {
public:
	int start_time;
	int end_time;
};
bool Compare(Activity a, Activity b) {
	if(a.end_time == b.end_time)
		return a.start_time <= b.start_time;
	return a.end_time < b.end_time;
}
Activity a[100005];
int32_t main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i].start_time >> a[i].end_time;
		sort(a, a + n, Compare);
		int ans = 1;
		int prev_time = a[0].end_time;
		for(int i = 1; i < n; i++) {
			if(a[i].start_time >= prev_time) {
				ans++;
				prev_time = a[i].end_time;
			}
		}
		cout << ans << endl;
	}
}