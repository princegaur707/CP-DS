#include<bits/stdc++.h>
using namespace std;
int table[1005] = {0};
void CalcuateTable(string p)
{
    int i = 0;
    int j = 1;
    int lp = p.length();
    while(j < lp)
    {
        while(i > 0 and p[i] != p[j])
        {
            i = table[i - 1];
        }
        if(p[i] == p[j])
        {
            table[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
}
void KMP(string s, string p)
{
    CalcuateTable(p);
    int i = 0;
    int j = 0;
    int ls = s.length();
    int lp = p.length();
    while(i < ls)
    {
        while(j > 0 and s[i] != p[j])
        {
            j = table[j - 1];
        }
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
        if(j == lp)
        {
            cout <<i - j << endl;
        }
    }
}
int main()
{
    int n;
    while(cin >> n)
    {
        string s;
        string p;
        cin >> p >> s;
        KMP(s, p);
        cout << endl;
    }
}