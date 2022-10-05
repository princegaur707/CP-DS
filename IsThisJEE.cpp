#include<bits/stdc++.h>
const double PI=acosl(-1);
using namespace std;
double fun(double m,double b,double c){
    return (m*m+b*m+c)/sin(m);
}
void solve()
{
  double b,c;
  cin>>b>>c;
  double m1=PI/6;
  double m2=PI/2-m1; //What is the intution behind this.
  double l=0,r=PI/2;
  
  while((m2-m1)>0.000001){
      m1=l+((r-l)/3);
      m2=r-((r-l)/3);
      double fm1=fun(m1,b,c);
      double fm2=fun(m2,b,c);
      
      if(fm1>fm2){
          l=m1;
      }
      else if(fm2>fm1){
          r=m2;
      }
      else{
          l=m1;
          r=m2;
      }
  }
  cout<<setprecision(10)<<fun(r,b,c)<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	//	cout<<"Case #"<<i+1<<": ";
		solve();
	}
	
	return 0;
}