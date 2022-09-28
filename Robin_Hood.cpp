// Time Complexity: O(log N)
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	int n;
// 	int k;
// 	cin >> n >> k;
// 	int arr[n];
// 	for(int i = 0; i < n; i++)
// 	{
// 		cin >> arr[i];
// 	}
// 	while (k > 0)
// 	{
// 		int maxi = *max_element(arr, arr + n);
// 		int index1 = find(arr, arr + n, maxi) - arr;
// 		int mini = *min_element(arr, arr + n);
// 		int index2 = find(arr, arr + n, mini) - arr;
// 		arr[index1] -= 1;
// 		arr[index2] += 1;
// 		k--;
// 	}
// 	int maxi = *max_element(arr, arr + n);
// 	int mini = *min_element(arr, arr + n);
// 	cout << maxi - mini;
// }
