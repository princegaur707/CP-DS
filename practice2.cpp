#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;

	while(t--){
		//cout<<t<<endl;
		int n;
		cin>>n;
		int freq[10]={0};

		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			x=x%10;
			freq[x]++;			
		}

		vector<int> v;

		for(int i=0; i<10; i++){
			for(int j=0; j<min(3,freq[i]);j++){
				v.push_back(i);
			}
		}
		int l=v.size();
		int flag=0;
		for(int i=0; i<l; i++){
			for (int j=i+1; j<l; j++){
				for(int k=j+1; k<l; k++){
					if((v[i]+v[j]+v[k])%10==3){
						flag=1;
					}
				}
			}
		}
		if (flag==1){
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;

	}
}