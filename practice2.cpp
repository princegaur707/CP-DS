#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int freq[10]={0};

		for(int i=0; i<n; i++)
		{
			int num;
			cin>>num;
			num%=10;
			freq[num]++;
		}

		vector<int>arr;

		for (int i=0; i<10; i++)
		{
			for (int j=0; j<min(3,freq[i]); j++)
			{
				arr.push_back(i);
			}
		}

		int l=arr.size();
		int flag=0;

		for(int i=0; i<l-2; i++)
		{
			for(int j=i+1; j<l-1; j++)
			{			
				for(int k=j+1; k<l; k++)
				{
					if((arr[i]+arr[j]+arr[k])%10==3)
					{
						flag=1;
						break;
					}
				}
			}
		}
		if (flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}