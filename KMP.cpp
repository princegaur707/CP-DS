#include<bits/stdc++.h>
using namespace std;
int table[105] = {0};
void CalculateTable(char *p)
{
	int i = 0;
	int j = 1;
	int lp = strlen(p);
	while(i < lp)
	{
		while(j > 0 and p[i] != p[j])
		{
			j = table[j - 1]
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