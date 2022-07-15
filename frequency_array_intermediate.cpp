#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;

	cin>>n;

	int arr[n];

	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout<<arr<<endl; //Depicts the address of very element of array so, arr+n points last

	int maxi= *max_element(arr,arr+n); //STL
	int mini= *min_element(arr,arr+n);

	int freq[maxi-mini+1]={0};

	for (int i=0; i<n; i++)
		freq[arr[i]-mini]++;   //Shifting

	for (int i=0; i< maxi-mini+1; i++)
	{
		if (freq[i]>0)
			cout<<i+mini<<"-->"<<freq[i]<<endl;
	}
}	