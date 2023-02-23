#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;
		int combine[40005] = {0};
		int pre[40005] = {0};
		for (int i = 0; i < a * b; i++) {
			if (((i % a) % b) != ((i % b) % a))
				combine[i] = 1;
			pre[i] = (i == 0) ? combine[i] : combine[i] + pre[i - 1];
		}
		int count1 = 0;
		int count2 = 0;
		int ans = 0;
		while (q--) {
			int l, r;
			cin >> l >> r;
			int x = r / (a * b);
			int y = r % (a * b);
			l--; // as for prefix sum we find from r to l - 1 so directly doing here l--
			int x1 = l / (a * b);
			int y1 = l % (a * b);

			count1 = ((x * pre[a * b - 1]) + pre[y]);
			count2 = ((x1 * pre[a * b - 1]) + pre[y1]);
			cout << count1 - count2 << " ";
		}
		cout << endl;
	}
	return 0;
}