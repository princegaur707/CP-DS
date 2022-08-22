#include<bits/stdc++.h>
using namespace std;
#define val 100
int main()
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
	int c = 0;
	for(int i = 0 ; recipe[i] != '\0' ; i++)
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
	cout<<b  <<s <<c   <<endl;
	int tot = b * pb + s *ps + c * pc;
	int cnt = -1;
	int start = 0;
	int ans = -1;
	long long e = val;
	int money_have = r + nb * pb + ns * ps + nc * pc;
	cout<<"money_have: "<<money_have<<endl;
	long long end = val;
	while( start <= end )
	{
		int mid = (start + end) / 2;
		cout<<"mid : "<< mid<<endl;
		int money_required = (b * pb + s * ps + c * pc) * mid;
		cout<<"money_required: "<<money_required<<endl;
		if(money_required == money_have)
		{
			cout<<(mid) % tot;
			break;
		}
		else if(money_required < money_have)
		{
			start = mid + 1;
			ans = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	if(ans != -1)
	{
		cout<<endl;
		cout<<"ans: "<<ans / tot;
	}
}