//Euclidean algorithm by subtraction
//It is a process of repeat subtraction, carrying the result forward each time until the result is equal to any one number being subtracted.
//If the answer is greater than 1, there is a GCD (besides 1). If the answer is 1, there is no common divisor (besides 1), and so both numbers are coprime
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a == 0)
        return b; //Everything divides zero.
    if(b == 0)
        return a; //Everything divides zero.
    if(a == b) //BASE CASE
    {
        return a;
    }
    if(a > b) //a is greater
        return gcd(a - b, b);
    return gcd(a, b - a);
}
int main()
{
    int a;
    int b;
    a = 10;
    b = 15;
    cout << gcd(a, b);
}