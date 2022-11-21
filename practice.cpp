#include<bits/stdc++.h>
using namespace std;
void Solve(char* ip, char* op, int i, int j)
{
	if(ip[i] == '\0')
	{
		op[j] = '\0';
		cout << op << endl;
		return;
	}
	op[j] = ip[i];
	Solve(ip, op, i + 1, j + 1);
	
	Solve(ip, op, i + 1, j);//want to skip the character
}
int main()
{
	char ip[100]; //char array for input
	char op[100];//char array for output
	cin >> ip;
	Solve(ip, op, 0, 0);//sending the starting of input and output array as 0, 0.
}