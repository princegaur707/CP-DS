// https://hack.codingblocks.com/app/contests/3317/543/problem
#include<bits/stdc++.h>
using namespace std;
void Generate_parentheses(int i, int open_count, int close_count, char* op, int n){
	if(i == 2 * n){
		op[i] = '\0';
		cout << op << endl;
		return;
	}
	if(open_count > close_count){
		op[i] = ')';
		//Move ahead 
		Generate_parentheses(i + 1, open_count, close_count + 1, op, n);
	}
	if(open_count < n){//count of open brackets should be less than n
		op[i] = '(';
		Generate_parentheses(i + 1, open_count + 1, close_count, op, n);
	}
}
int main(){
	int n;
	cin >> n;
	char op[1000];
	Generate_parentheses(0, 0, 0, op, n);
}