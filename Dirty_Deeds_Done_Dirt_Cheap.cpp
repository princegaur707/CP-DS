#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	std::vector<pair<int, int>>arr,brr;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int y;
		cin >> y;
		if(x < y)
		{
			arr.push_back({-y, i});//to store the inverse
		}
		else
		{
			brr.push_back({y, i});
		}
	}
	for(auto x : arr)
	{
		cout << x.first << " ";
	}
	cout << endl;
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	if(arr.size() < brr.size())
	{
		swap(arr, brr);
	}
	cout << arr.size() << endl;
	for(auto x : arr)
	{
		cout << x.second << " ";
	}
}