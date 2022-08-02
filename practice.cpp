#include<bits/stdc++.h>
using namespace std;
int length(int n)
    {
        int cnt=0;
        while(n)
        {
            cnt++;
            n/=10;
        }
     	return cnt;
    }
    
int number( int num, int flag)
    {
    	int n=0;
        if(flag==0)
        {	
        	while(num)
        	{
            	n+=9*(10^(num-1));
            	num-=1;
            	cout<<n;
        	}
    	}
        else
        {
            while(num)
        	{
            	n+=1*(10^(num-1));
            	num-=1;
        	}
        }
    	return(n);
    }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l;
        cin>>l;
        int n;
        cin>>n;
        int num=number(l,0);
        cout<<num;
        if (l==length(num-n))
         cout<<num-n<<endl;
        else
        {
        	int num1=number(l+1,1);
        	cout<<num1-n<<endl;
        }
        
    }
    return 0;
}