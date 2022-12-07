#include<bits/stdc++.h>
using namespace std;
void Permutate(char* ip, int i)
{
	if(ip[i] == '\0')
	{
		cout << ip << endl;
		return;
	}
	for(int j = i; ip[j] != '\0'; j++)
	{
		swap(ip[i], ip[j]);
		Permutate(ip, i + 1);
		swap(ip[i], ip[j]);
	}
}
int main()
{
	char ip[100];
	cin >> ip;
	Permutate(ip, 0);
}