#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lenght(int n)
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
        if(flag=0)
        {int cnt=0,n=0;
        while(num)
        {
            n+=9*cnt;
            num/=10;
        }}
        else
        {
            while(num+1)
        {
            n+=1*cnt;
            num/=10;
        }}
        }
    }
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l;
        int n;
        cin>>n;
        int num=number(n);
        if (n==length(num-n))
         cout<<num-n;
        else
        int flag=1;
        int num1=number(n);
        cout<<
        
    }
}