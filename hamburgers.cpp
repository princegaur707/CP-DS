//https://codeforces.com/problemset/problem/371/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define val 1000000100000
int32_t main() //int can be any size >= 16 bits. At different times, both 16 bits 
              //and 32 bits have been reasonably common (and for a 64-bit implementation, 
              //it should probably be 64 bits).Here we are using 
{
	string recipe;
	cin >> recipe;
	int nb;
	int ns;
	int nc;
	cin >> nb >> ns >> nc;
	int pb;
	int ps;
	int pc;
	cin >> pb >> ps >>pc;
	int r;
	cin >> r;
	int b = 0;
	int s = 0;
	int c = 0
;	for(int i = 0 ; recipe[i] != '\0' ; i++)
	{
		if(recipe[i] == 'B')
		{
			b++;
		}
		else if (recipe[i] == 'S')
		{
			s++;
		}
		else
		{
			c++;
		}
	}
	//cout<<b  <<s <<c   <<endl;
	int tot = b * pb + s * ps + c * pc;
	int start = 0;
	int ans = -1;
	int flag = 0;
	int end = val;
	while( start <= end ) //Applying Binary search and checking for middle element.
	{
		int mid = (start + end) / 2;
		// cout<<"mid : "<< mid<<endl;
		int bread_money = (mid * b - nb) < 0 ? 0 : ((mid * b -nb) * pb);  //If we have quantity of bread more than required 
																		  //then money required for bread is zero.
		int sauce_money = (mid * s - ns) < 0 ? 0 : ((mid * s - ns) * ps);
		int cheese_money = (mid * c - nc) < 0 ? 0 : ((mid * c -nc) * pc);

		int money_required = bread_money + sauce_money + cheese_money;
		// cout<<"money_required: "<<money_required<<endl;
		if(money_required == r)
		{
			cout<<mid;
			flag = 1;
			break;
		}
		else if(money_required < r)
		{
			start = mid + 1;
			ans = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	if(flag == 0)
	{
		cout<<ans;
	}
}