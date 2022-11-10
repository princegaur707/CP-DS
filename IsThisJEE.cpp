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
  cout << r << endl;
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
// #include<bits/stdc++.h>
// using namespace std;
// double Calcualate(double x, double b, double c)
// {
//     return (x * x + b * x + c) / sin(x);
// }
// int main()
// {
//     double t;
//     cin >> t;
//     while(t--)
//     {
//         double b;
//         double c;
//         cin >> b >> c;
//         double PI = acos(-1);
//         double start = 0;
//         double end = PI/ 2;
//         double step = 1e-6;
//         while(start < end)
//         {
//             double mid = start + (end - start) / 2;
//             if(Calcualate(mid, b, c) < Calcualate(mid + step, b, c))
//             {
//                 end = mid;
//             }
//             else
//             {
//                 start = mid;
//             }
//         }
//         cout << end << endl;
//         cout << Calcualate(end, b, c) << endl;
//     }
// }