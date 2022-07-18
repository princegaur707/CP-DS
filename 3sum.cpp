//https://codeforces.com/problemset/problem/1692/F

// Sliding window approach is not posible as indexes will not be necessarily consecutive
// e.g. no.'s at position 1,10,25 can also have sum with ending of 3. 
#include<bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin>>t;

	while(t--){
		long long n;
		int freq[10]={0};
		cin>>n;

		for (int i=0; i<n; i++){
			int x;
			cin>>x;
			x=x%10;
			freq[x]++;	//we build frequency array directly..No need for original array
		}

		vector<int>v;

		for (int i=0; i<10; i++){
			for(int j=0; j< min(3,freq[i]);j++)
				v.push_back(i);
		}
		int flag=0;
		int l=v.size();
		for (int i=0; i<l; i++){
			for (int j=i+1; j<l; j++ ){
				for (int k=j+1; k<l; k++){
					if((v[i]+v[j]+v[k])%10==3){
						flag=1;
						break;}
				}
			}
		}
		if (flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

}