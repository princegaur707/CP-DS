#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	char ch;
	cin >> n >> m >> ch;
	char a[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	unordered_set<char>s;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == ch) {
				if(i > 0 and a[i - 1][j] != '.' and a[i - 1][j] != ch)
					s.insert(a[i - 1][j]);
				if(i + 1 < n and a[i + 1][j] != '.' and a[i + 1][j] != ch)
					s.insert(a[i + 1][j]);
				if(j > 0 and a[i][j - 1] != '.' and a[i][j - 1] != ch)
					s.insert(a[i][j - 1]);
				if(j + 1 < m and a[i][j + 1] != '.' and a[i][j + 1] != ch)
					s.insert(a[i][j + 1]);
			}
		}
	}
	cout << s.size();
}