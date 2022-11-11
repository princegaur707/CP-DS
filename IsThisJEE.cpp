#include<bits/stdc++.h>
using namespace std;
double Calcualate(double x, double b, double c)
{
    return (x * x + b * x + c) / sin(x);
}
int main()
{
    double t;
    cin >> t;
    while(t--)
    {
        double b;
        double c;
        cin >> b >> c;
        double PI = acos(-1); //this gives the exact value of pi
        double start = 0;
        double end = PI / 2;
        double step = 1e-6;
        double ans = -1;
        int cnt = 0;
        while(start < end)
        {
            double mid = start + (end - start) / 2;
            if(Calcualate(mid, b, c) < Calcualate(mid + step, b, c))
            {
                end = mid - step;
                ans = mid;
            }
            else
            {
                start = mid + step;
            }
        }
        //cout << ans << endl;
        cout << setprecision(10)<< Calcualate(ans, b, c) << endl;//setprecision sets precision upto
                                                                //mentioned decimal pts.
    }
}