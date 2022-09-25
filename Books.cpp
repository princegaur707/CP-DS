#include<bits/stdc++.h>
using namespace std;
long s[100005],m,r;
int main()
{
	int n;
	int t;
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
		if(s[i] - s[m] > t)
		{
			m++;
		}
		r = max(r, i - m);
	}
	cout << r;
}
/* Intution
When the prefix sum will get greater than time(t) store current length(r) and move ahead by neglecting element from front
and go for the maximum length possible by proceding in the same way till last.
*/
