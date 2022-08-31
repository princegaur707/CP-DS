//https://codeforces.com/problemset/problem/59/C
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int flag = 0;
    int ls = s.length();
    int freq[256] = {0};
    for(int i = 0; i < 26; i++)
    {
        freq[s[i] - 'a']++;
    }
    int left = 0;
    int right = ls-1;
    while(left <= right)
    {
        // cout << endl;
        // cout<<"left: " << left <<"  right: " << right;
        if ( k > (ls+1)/2)
        {
            cout << "IMPOSSIBLE";
            break;
        }
        if(s[left] != '?' and s[right] != '?')
        {
            if(s[left] != s[right])
            {
                cout <<"IMPOSSIBLE";
                break;
            }
            else
            {
                left++;
                right--;
                continue;
            }
        }
        if(s[left] != '?' and s[right] == '?')
        {
            // cout<<"hello1";
            s[right] = s[left];
            left++;
            right--;
            // cout <<s;
        }
        if(s[left] == '?' and s[right] != '?')
        {
            // cout << "Hello";
            s[left] = s[right];
            left++;
            right--;
        }
        if(s[left] == '?' and s[right] == '?')
        {
            int t = min(k, 26);
            for(int i = 0; i < t; i++)
            {
 
                if(freq[i] == 0)
                {
                    flag = 1;
                    s[left] = 'a' + i;
                    s[right] = 'a' + i;
                    left++;
                    right--;
                    freq[i]++;
                    break;
                }
            }
            if(flag == 0)
            {
                cout << "IMPOSSIBLE";
                break;
            }
        }
        if (left >= right)
        {
            cout << s;
        }
    }
}