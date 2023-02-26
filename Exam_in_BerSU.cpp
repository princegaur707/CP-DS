#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, M;
	cin >> n >> M;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int freq[101] = {0};//for frequency array
	int count = 0;
	int total = 0, x = 0, y;
	for(int i = 0; i < n; i++) {
		x = total - M + arr[i];
		count = 0;
		if(x > 0) {
			for(int j = 100; j > 0; j--) {
				y = freq[j] * j;
				if(x <= y) {
					count += (x + j - 1) / j;
					// cout << count << endl;
					break;
				}
				count += freq[j];
				x = x - y;
			}
		}
		freq[arr[i]]++;
		total += arr[i];
		cout << count << " ";
	}
}
/*Approach: we will be using frequency array it will be the best choice because
second best option priority queue may lead to TLE when the sum we want to find may be 
present in queue at last so additional logn will come in TC. but we want to do it
in O(n) so we can notice here in question max time can student can take for test
is 100 with which we can understand that frequencey array is best suitable here*/
