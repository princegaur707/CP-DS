#include<bits/stdc++.h>
using namespace std;
int table[1005] = {0};
void CalculateTable(char *p)
{
    int i = 0;
    int j = 1;
    int lp = strlen(p);
    while(j < lp
)    {
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
void KMP(char *s, char *p)
{
    CalculateTable(p);
    int i = 0;
    int j = 0;
    int ls = strlen(s);
    int lp = strlen(p);
    while(i < ls)
    {
        while(i > 0 and s[i] != p[j])
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
            cout << "Pattern found at " << i-lp+1 << " position." << endl;
        }
    }
}
int main()
{
    char s[] = "abcdabcdabcxabcdabcx";
    char p[] = "abcdabcx";
    KMP(s, p);
}