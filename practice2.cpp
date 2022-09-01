#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int l = s.length();
    for(int i = 0; i < l/2; i++)
    {
        cout <<  s[i] << " " << s[l - i - 1];  
        cout << endl;
    }
}