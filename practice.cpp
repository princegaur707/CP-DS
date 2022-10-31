#include<bits/stdc++.h>
using namespace std;
int table[105];
void createtable(string p)
{
	int lp = lp.length();
	int i = 0;
	int j = 1;
	while(j < lp)
	{
	   while(i > 0 and p[i] != p[j])
	   {
			i = table[i - 1];
	   }
	   if(p[i] == p[j])
	   {
	   		table[j] = i + 1;
	   		i++;
	   		j++;
	   }
	   else
	   {
	   		j++;
	   }
	}
}
void KMP(string s, string p)
{
	int ls = s.length();
	int lp = p.length();
	int i = 0;
	int j = 0;
	while(i < ls)
	{
		whi
	}
}
int main()
{
	string s = "abcdefghiabcde";
	string p = "cde";
	KMP(s, p);
}