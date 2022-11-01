#include<bits/stdc++.h>
using namespace std;
int table[105];
void createtable(string p)
{
	int lp = p.length();
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
	cout << "Table: ";
    for(int i = 0; i < lp; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}
void KMP(string s, string p)
{
	createtable(p);
	int ls = s.length();
	int lp = p.length();
	int i = 0;
	int j = 0;
	while(i < ls)
	{
		while(j > 0 and s[i] != p[j])
		{
			j = table[j - 1];
		}
		if(s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i++;
		}
		if(j == lp)
		{
			cout << "Element found at: " << i - lp + 1 << " pos\n";
		}
	}
}
int main()
{
	string s = "abcdabcdabcxabcdabcx";
	string p = "abcdabcx";
	KMP(s, p);
}