#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n;
	cin>>n;
	int arr[n];

	for(i=0;i<n;i++)
		cin>>arr[i];

	int freq[10005]={0};

	for(i=0;i<n;i++){
		freq[arr[i]]++;
	}


	for(i=0; i<15; i++){
		if (freq[i]>0)
			cout<<i<<"-->"<<freq[i]<<endl;
	}
	}
