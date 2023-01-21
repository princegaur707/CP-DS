// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d
#include<bits/stdc++.h>
using namespace std;
void String_equivalence(char* output, int i, int Max_character, int n){
	if(i == n){
		output[i] = '\0';
		cout << output << endl;
		return;
	}
	for(char ch = 'a'; ch <= Max_character; ch++){
		output[i] = ch;
		if(ch == Max_character){
			cout << "1 ";
			cout << Max_character << " ";
			String_equivalence(output, i + 1, Max_character + 1, n);
			//If we are filling Max_character then for next case
			//Max_character will increament by 1.
		}
		else{
			cout << "2 ";
			cout << Max_character << " ";
			String_equivalence(output, i + 1, Max_character, n);
		}
	}
}
int main(){
	int N;
	cin >> N;
	char output[1000];
	String_equivalence(output, 0, 'a', N);
}