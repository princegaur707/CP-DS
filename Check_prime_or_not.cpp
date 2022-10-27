#include<bits/stdc++.h>
using namespace std;
bool IsPrime(int n)
{
	if(n == 1)
		return false;
	if(n == 2 or n == 3)
		return true;
	if(n % 2 == 0 or n % 3 == 0)
		return false;
	for(int i = 5; i * i <= n; i += 6)//6 as we are already checking for 2 and 3 above
	{
		if(n % i == 0 or n % (i + 2) == 0) //checks for divison of 5,7 then 11,13.....
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	if(IsPrime(n))
	{
		cout << "YES, it is a prime no.";
	}
	else
	{
		cout << "NOT a prime no.";
	}
}
//T.C: O(sqrt(n))
//S.C: O(1)