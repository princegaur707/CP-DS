#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1);

using namespace std;

vector<pair<ll, ll> > v;

int main(){
	int n, m;
	ll c, t, k = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		scanf("%lld %lld", &c, &t);
		v.push_back(make_pair(k, k + c * t));
		k += c * t;
	}
	int j = 1;
	for (int i = 0; i < m; i++){
		ll a;
		scanf("%lld", &a);
		while (j < n && a > v[j].first) j++;//since we can notice moments are in increasing order so, we can 
											//directly do this as soon as total sum increases print 'j' we 
											//don't need to do 'j - 1' as we have choosen 0 based indexng.
		printf("%d\n", j);
	}
    return 0;
}