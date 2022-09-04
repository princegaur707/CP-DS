#include<bits/stdc++.h>
using namespace std;
#define int long long
int count1[2][2] = {0};
void CountGoodSubstring(string s)
{
	int len = s.length();
	int odd = 0;
	int even = 0;
	for(int i = 0; i < len; i++)
	{
		odd++;
		if(i % 2 == 0)
		{
			odd += count1[s[i] - 'a'][1];
			even += count1[s[i] - 'a'][0];
			count1[s[i] - 'a'][1]++;
		}
		else
		{
			odd += count1[s[i] - 'a'][0];
			even += count1[s[i] - 'a'][1];
			count1[s[i] - 'a'][0]++;
		}
	}
	cout << even <<" " << odd;
}
int32_t main()
{
	string s;
	cin >> s;
	CountGoodSubstring(s);
}
// #include<bits/stdc++.h>
// using namespace std;
// int even_good = 0;
// int odd_good = 0;
// bool CheckPalindrome(int l, string s)
// {
// 	int i = 0;
// 	int j = l - 1;
// 	while(i <= j)
// 	{
// 		if(s[i] != s[j])
// 		{
// 			return false;
// 		}
// 		else
// 		{
// 			i++;
// 			j--;
// 		}
// 	}
// 	return true;
// }
// void Check(int l, string s)
// {
// 	int t = l;
// 	for(int i = 0; i < l - 1; i++)
// 	{
// 		if(s[i] == s[i+1])
// 		{
// 			s.erase(i,i);
// 			i -= 1;
// 		}
// 	}
// 	if(CheckPalindrome(l, s))
// 	{
// 		if(l % 2 == 0)
// 		{
// 			even_good++;
// 		}
// 		else
// 		{
// 			odd_good++;
// 		}
// 	}
// }
// int main()
// {
// 	string s;
// 	cin >> s;
// 	int l = s.length();
// 	for(int i = 2; i < l; i += 2)
// 	{
// 		for(int j = 0; j <= l - i; j++)
// 		{
// 			Check(i, s.substr(j, i));
// 		}
// 	}
// 	odd_good += l;
// 	for(int i = 3; i <= l; i +=2)
// 	{
// 		for(int j = 0; j <= l - i; j++)
// 		{
// 			//cout << s.substr(j, i - 1) << endl;
// 			Check(i, s.substr(j, i));
// 		}
// 	}
// 	cout << even_good << " " << odd_good;
// }