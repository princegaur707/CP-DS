#include<bits/stdc++.h>
using namespace std;
int main() {

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout<<"HELLO";

	//Stl:
	int minimum = *min_element(a, a + n);
	//cout << minimum << endl;
	int maximum = *max_element(a, a + n);
	//cout << maximum << endl;

	int freq[maximum - minimum + 1] = {0};

	//Shifting

	for (int i = 0; i < n; i++) {
		freq[a[i] - minimum] = freq[a[i] - minimum] + 1;
	}



	for (int i = 0; i < maximum - minimum + 1; i++) {
		if (freq[i] > 0) {
			cout << i + minimum << "-->" << freq[i] << endl;
		}
	}

}