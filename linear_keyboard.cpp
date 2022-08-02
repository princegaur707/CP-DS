//https://codeforces.com/problemset/problem/1607/A
#include<bits/stdc++.h>
using namespace std;
int main(){
 
	int t;
	cin>>t;
 
	while(t--)
	{
		string keyboard, word;
		cin>>keyboard;
		cin>>word;
 
		int map[256]={0}; //Here we need only 26 but 256 works for everwhere as it is consits
		//everything Upper Letters, Lower letters, etc.,
 
		for( int i=0; i<26; i++)
			map[keyboard[i]]=i;
	
		int dist=0;
 
		int l= word.size();
		for (int i=0; i<l-1; i++)
			dist+= abs(map[word[i]]-map[word[i+1]]);
		cout<<dist<<endl;
	}
}