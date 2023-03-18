#include<bits/stdc++.h>
using namespace std;
#define MAX 3000

int dp[MAX + 1][MAX + 1];
string getLCS(string& s, string& t, int len) {
	string LCS;
	int i = 0, j = 0;
	while (len > 0) {
		if (s[i] == t[j])
		{
			LCS.push_back(s[i]);
			i++;
			j++;
			len--;
		}
		else
		{
			if (dp[i][j + 1] > dp[i + 1][j]) {
				j++;
			}
			else {
				i++;
			}
		}
	}
	return LCS;
}

int lenLCS(string& s, string& t, int i, int j) {
	if (i >= s.length() || j >= t.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return dp[i][j] = 1 + lenLCS(s, t, i + 1, j + 1);
	}
	else {
		return dp[i][j] = max(lenLCS(s, t, i, j + 1), lenLCS(s, t, i + 1, j));
	}
}

string solve(string s, string t) {
	memset(dp, -1, sizeof dp);
	int len = lenLCS(s, t, 0, 0);
	return getLCS(s, t, len);
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << solve(s, t);
}

//Why this is giving TLE is some cases pass by reference should not apply here
//as we are making strings global 
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define Max 3001
// int dp[Max][Max];
// string s, t;
// string ans;
// void GetString(int len) {
// 	int i = 0;
// 	int j = 0;
// 	while(len > 0) {
// 		if(s[i] == t[j]) {
// 			ans.push_back(s[i]);//string also have push_back
// 			i++;
// 			j++;
// 			len--;
// 		}
// 		else {
// 			if(dp[i][j + 1] > dp[i + 1][j]) 
// 				j++;
// 			else
// 				i++;
// 		}
// 	}
// }
// int GetLen(int i, int j) {
// 	if(i >= s.length() || j >= t.length())
// 		return 0;
// 	if(dp[i][j])
// 		return dp[i][j];
// 	if(s[i] == t[j])
// 		return dp[i][j] = 1 + GetLen(i + 1, j + 1);
// 	else
// 		return dp[i][j] = max(GetLen(i, j + 1), GetLen(i + 1, j));
// }
// void Solve(string &s ,string &t) {
// 	// memset(dp, -1, sizeof dp);
// 	int len = GetLen(0, 0);
// 	GetString(len);
// 	cout << ans;
// }
// int32_t main() {
// 	cin >> s >> t;
// 	Solve(s, t);
// }