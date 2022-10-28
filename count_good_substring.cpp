#include<bits/stdc++.h>
using namespace std;
#define int long long
int table[2][2];
int32_t main()
{
    string s;
    cin >> s;
    int l = s.length();
    int odd = 0;
    int even = 0;
    for(int i = 0; i < l; i++)
    {
        odd++;
        if(i % 2 == 0)
        {
            odd += table[s[i] - 'a'][0]; //character on even positions will make odd substring
            even += table[s[i] - 'a'][1]; //character on odd positions will make even substring
            table[s[i] - 'a'][0]++; //updating the count of no. of even occurrence of character
        }
        else
        {
            even += table[s[i] - 'a'][0];
            odd += table[s[i] - 'a'][1];
            table[s[i] - 'a'][1]++; //updating the count of no. of odd occurrence of character
        }
    }
    cout << even << " " << odd;
}

/*
Brute Forece Method: calculate all substrings and then calculate how many are palindromes 
of even length and how many are of odd length
TC : O(n^3)
#include<bits/stdc++.h>
using namespace std;
int even_good = 0;
int odd_good = 0;
bool CheckPalindrome(int l, string s)
{
	int i = 0;
	int j = l - 1;
	while(i <= j)
	{
		if(s[i] != s[j])
		{
			return false;
		}
		else
		{
			i++;
			j--;
		}
	}
	return true;
}
void Check(int l, string s)
{
	int t = l;
	for(int i = 0; i < l - 1; i++)
	{
		if(s[i] == s[i+1])
		{
			s.erase(i,i);
			i -= 1;
		}
	}
	if(CheckPalindrome(l, s))
	{
		if(l % 2 == 0)
		{
			even_good++;
		}
		else
		{
			odd_good++;
		}
	}
}
int main()
{
	string s;
	cin >> s;
	int l = s.length();
	for(int i = 2; i < l; i += 2)
	{
		for(int j = 0; j <= l - i; j++)
		{
			Check(i, s.substr(j, i));
		}
	}
	odd_good += l;
	for(int i = 3; i <= l; i +=2)
	{
		for(int j = 0; j <= l - i; j++)
		{
			//cout << s.substr(j, i - 1) << endl;
			Check(i, s.substr(j, i));
		}
	}
	cout << even_good << " " << odd_good;
}
*/