#include<bits/stdc++.h>
using namespace std;
int n, d;
int arr[100005];
void Solve() {
	int total = 0;
	for(int i = 0; i < n; i++) {//for checking whether answer exist or not
		if(arr[i] == 0) {//0 means checking here
			if(total < 0)
				total = 0;//we will only deposit to make balance nearest non -ve i.e zero
		}
		else {
			total += arr[i];
			if(total > d) {
				cout << "-1" << endl;
				return;
			}
		}
	}
	//If we are here it means answer exist
	total = 0;
	int visit = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == 0) {
			if(total < 0) {
				total = d;//depositing max. possible
				visit++;
			}
		}
		else {
			total += arr[i];
			if(total > d)//since we have checked answer exist we will deposit only this much to make balance 'd'
				//this step is compulsory otherwise there will be issues in total, it might not become '0'
				total = d;
		}
	}
	cout << visit << endl;
	return;
}
int main() {
	cin >> n >> d;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	Solve();
}