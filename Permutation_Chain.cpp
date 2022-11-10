/*We can go by the approach that we will decrease the fixedness everytime by 1 and in this way we 
will be able to get the the longest permutation length so permutations will be
n-2, n-3(swapping already swapped and next one), n - 4 ,......0 instead of n - 1 we will get 0 so the
total length will be 'n'.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n + 1];
		cout << n << endl;
		for(int i = 1; i <= n; i++)
		{
			cout << i << " ";
			arr[i] = i;
		}
		cout << endl;
		for(int i = 1; i < n; i++)
		{
			swap(arr[i], arr[i + 1]);
			for(int i = 1; i <= n; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
	}
}