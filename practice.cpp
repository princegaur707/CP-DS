#include<bits/stdc++.h>
using namespace std;
int func(int x) {
	int cnt = 0;
	while(x) {
		cnt++;
		x /= 10;
	}
	return cnt;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		multiset<int, greater<int>>s1;
		multiset<int, greater<int>>s2;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s1.insert(x);
		}
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			auto it = s1.find(x);
			if(it != s1.end()) 
				s1.erase(it);
			else
				s2.insert(x);
		}
		int ops = 0;
		int i = 0;
		while(*s1.begin() > 9) {
			ops++;
			s1.insert(func(*s1.begin()));
		}
		while(*s2.begin() > 9){
			ops++;
			s2.insert(func(*s2.begin()));
		}
		for(auto x : s1) {
			if(s2.find(x) != s2.end()) {
				auto it = s1.find(x);
				if(it != s1.end()) 
					s1.erase(it);
				auto it2 = s2.find(x);
				if(it2 != s2.end())
					s2.erase(it2);
			}
		}
		ops = (s1.size() + s2.size()) * 2;
		cout << ops;
	}
}