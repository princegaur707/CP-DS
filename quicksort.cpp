//Implementation of quick sort by keeping first element as pivot.
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l , int h)
{
	int pivot = arr[l];
	int i =l;
	int j=h;

	while (i<j)
	{
		do
		{
			i++;
		}while(arr[i]<=pivot);

		while(arr[j]>pivot)
			j--;
		if (i<j)
			swap(arr[i],arr[j]);
	}
	swap(pivot,arr[j]);
	return j;
}

void quicksort(int arr[], int l, int h)
{
	if (l>=h)
		return;
	int j= partition(arr,l,h);
	quicksort(arr,l,j-1);
	quicksort(arr,j+1,h);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for (int i=0; i<n; i++)
			cin>>arr[i];
		quicksort(arr,0,n);
		for (int i=0; i<n; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}