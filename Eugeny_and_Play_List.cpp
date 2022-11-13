//O(N) or O(M) which ever is bigger N OR M, this can be said linear as we are not initializing the 
//'j' again again in the loop.
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
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
//O(M log (N))
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int32_t main()
// {
// 	int n; //total no. of songs
// 	int m; //no. of moments written
// 	cin >> n >> m;
// 	int prefix_array[n + 1];
// 	prefix_array[0] = 0;
// 	for(int i = 1; i <= n; i++)
// 	{
// 		int c;
// 		int t;
// 		cin >> c >> t;
// 		prefix_array[i] = prefix_array[i - 1] + c * t;
// 	}
// 	int moments[m + 1];
// 	for(int i = 1; i <= m; i++)
// 	{
// 		cin >> moments[i];
// 	}
// 	for(int i = 1; i <= m; i++)
// 	{
// 		int start = 1;
// 		int end = n;
// 		while(start < end)
// 		{
// 			int mid = start + (end - start) / 2;
// 			if(moments[i] <= prefix_array[mid])
// 			{
// 				 end = mid;
// 			}
// 			else
// 			{
// 				start = mid + 1;
// 			}
// 		}
// 		cout << end << endl;
// 	}
// }