#include<bits/stdc++.h>
using namespace std;
int table[1005] = {0};
void CalculateTable(char *p)
{
    int i = 0; //for comparing very first character
    int j = 1; //for matching the second character with first one
    int lp = strlen(p);
    while(j < lp) //while we don't reach till the very end of pattern
    {
        while(i > 0 and p[i] != p[j]) //if we are on i = 0 we cannot move back further
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
    cout << "Table: ";
    for(int i = 0; i < lp; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}
void KMP(char *s, char *p)
{
    CalculateTable(p);
    int i = 0;
    int j = 0;
    int ls = strlen(s);
    int lp = strlen(p);
    while(i < ls) //still we don't compare the whole string
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
        if(j == lp) //strings matched
                    //If j will be lp it means it must have been updated 'j+1' 
            {      //after matching the last character too so we are matching these.
            cout << "i: " << i <<" j: " << j << endl;
            cout << "Pattern found at " << i-lp+1 << " position." << endl; //we now need to go to previous
            //no. as to see from where we need to match it is having same reason as base of KMP approach.
        }
    }
}
int main()
{
    char s[] = "abcdabcdabcxabcdabcx";
    char p[] = "abcdabcx";
    KMP(s, p);
}