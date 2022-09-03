//https://codeforces.com/problemset/problem/59/C
#include<bits/stdc++.h>
using namespace std;
bool freq[30] = {0};

void Title(int k, string s)
{
    int i = 0;
    int j = s.length() - 1;
    while(i < j)
    {
        if(s[i] == '?' and s[j] == '?')
        {
            i++;
            j--;
            continue;
        }
        else if(s[i] != '?' and s[j] == '?')
        {
            s[j] = s[i];
            freq[s[i] - 'a' + 1] = true; //Here we are doing +1 as to make it 1 based indexing
            i++;
            j--;
        }
        else if(s[i] == '?' and s[j] != '?')
        {
            s[i] = s[j];
            freq[s[i] - 'a' + 1] = true;
            i++;
            j--;
        }
        else if (s[i] == s[j])
        {
            freq[s[i] - 'a' + 1] = true;
            i++;
            j--;
        }
        else
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    if(i == j and s[i] != '?')
    {
        freq[s[i] - 'a' + 1] = true;
    }
    while(i >= 0)
    {
        while(k > 1 and freq[k] == true)
        {
            k--;
        }
        if (s[i] == '?' and s[j] == '?')
        {
            s[i] = s[j] = 'a' + k - 1; //Due to 1 based indexing (97(a) + 3 = 100 -1 = 99(c))
            freq[k] = true;
            i--; 
            j++;
        }
        else
        {
            i--;
            j++;
        }
    }
    if(k == 1 and freq[k] == true)
    {
        cout << s;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    Title(k, s);
}