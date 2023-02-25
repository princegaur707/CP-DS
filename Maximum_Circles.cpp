#include<bits/stdc++.h>
using namespace std;
#define int long long
class Pair{
public:
	int start;
	int end;
};
bool compare(Pair p, Pair q) {
	if(p.end == q.end)
		return p.start < q.start;
	return p.end < q.end;
}
Pair p[100005];
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p[i].start = x - y;
		p[i].end = x + y;
	}
	sort(p, p + n, compare);
	int ans = 0;
	int prev = p[0].end;
	for(int i = 1; i < n; i++) {
		if(p[i].start >= prev)
			prev = p[i].end;
		else
			ans++;
	}
	cout << ans;
}
//Approach: Sorting of the circles in order: 
//firstly circles with earlier the end point
//if end point is same circle with early start point should come first
//While checking the collision of circles
//If starting of the next circle is greater or equal to previous circle
//then no collision and update the end point
//other update the circles to be removed.