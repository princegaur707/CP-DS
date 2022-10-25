#include<bits/stdc++.h>
using namespace std;
int Compare(string X, string Y)
{
	string XY = X.append(Y);
	string YX = Y.append(X);
	return XY > YX;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<string>arr;
		for(int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			string t1 = to_string(t);
			arr.push_back(t1);
		}
		sort(arr.begin(), arr.end(), Compare);

		for (int i = 0; i < arr.size(); i++)
			cout << arr[i];
		cout << endl;
	}
	return 0;
}