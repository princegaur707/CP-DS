#include<bits/stdc++.h>
using namespace std;
template<typename T>//with the help of this we are not type dependent
class Graph {
	map<T, list<T>>l;
public:
	void addEdge(T x, T y, bool bidirectional) {//bidirectional-> helpful in telling bidirectionality present or not
		l[x].push_back(y);
		if (bidirectional == 1)
			l[y].push_back(x);
	}
	void Printlist() {
		for (auto x : l) { //x representing whole row
			T s = x. first;
			cout << s << "-->" << " ";
			list<T> nbr = x.second;
			for (auto t : nbr)
				cout << t << " ";
			cout << endl;
		}
	}
};
int main() {
	Graph<string>g;
	int n, m;
	cin >> n >> m;
	//No. of nodes: n
	//No. of edges: m
	for (int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		g.addEdge(s, t, 1);
	}
	g.Printlist();
}
/*
Only code -->
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
map<T, list<T>>l;
public:
	 void addEdge(T x, T y, bool bidirectional) {
	 	l[x].push_back(y);
	 	if(bidirectional == 1)
	 		l[y].push_back(x);
	 }
	 void Printlist() {
	 	for(auto x : l) {
	 		T s = x. first;
	 		cout << s << "-->" << " ";
	 		list<T> nbr = x.second;
	 		for(auto t : nbr) {
	 			cout << t << " ";
	 		}
	 		cout << endl;
	 	}
	 	cout << endl;
	 }
};
int main() {
	Graph<string>g;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		g.addEdge(s, t, 1);
	}
	g.Printlist();
}
*/