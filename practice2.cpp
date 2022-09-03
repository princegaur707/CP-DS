#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    str = "abcdefghijklmnopqrstuvwxyz";
    cout <<" Before Erase: " << str << endl;
    str.erase(1,1);
    cout<< "After Erase: "  << str << endl;
}