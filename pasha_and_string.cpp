//https://codeforces.com/problemset/problem/525/B
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len = s.length();
	int m;
	cin >> m;
	int arr[len + 1] = {0};
	for(int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		arr[x - 1]++; //Frequency Array approach but we don't
					  //need subracting part as we will be 
					  // using only first half to interchange.
	}
	for(int i = 1; i < len / 2 ; i++)
	{
		arr[i] = arr[i - 1] + arr[i];
	}
	for(int i = 0; i < len / 2; i++)
	{
		if(arr[i] % 2 != 0) //If the char is reversed odd no.
							//of times then only swap.
		{
			char temp = s[i];
			s[i] = s[len - i - 1]; //no matter what is the part
							//of string reversed, we will be
							//swapping char with corresponding element
			s[len - i - 1] = temp;
		}
	}
	cout<<s;
}