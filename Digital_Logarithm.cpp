#include<bits/stdc++.h>
using namespace std;
int func(int x) {
	int k = 0;
	while(x > 0) {//finding length of a number 
		k++;				//or can do log(n) + 1;
		x /= 10;
	}
	return k;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		multiset<int, greater<int>>s1(a, a + n);//inserting all elements of 'a' into multiset, multiset: it is similar to set except it can have multiple occurrences of element
		multiset<int, greater<int>>s2;
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			auto it = s1.find(b[i]);
			if(it != s1.end())//will delete only one occurence by this iterator way
				s1.erase(it);//and in s2 we are not inserting that also indirecly is deleting
			else
				s2.insert(b[i]);
		}
		int cnt = 0;
		while(!s1.empty() and !s2.empty()) {
			int p = *s1.begin();
			int q = *s2.begin();
			if(p < q) {
				s2.erase(s2.begin());
				cnt++;
				q = func(q);//func define above
				if(s1.find(q) != s1.end())
					s1.erase(s1.find(q));
				else
					s2.insert(q);
			}
			else if(p > q) {
				s1.erase(s1.begin());
				cnt++;
				p = func(p);
				if(s2.find(p) != s2.end())
					s2.erase(s2.find(p));
				else
					s1.insert(p);
			}
			else {
				s1.erase(s1.begin());
				s2.erase(s2.begin());
			}
		}
		cout << cnt << endl;
	}
	return 0;
}