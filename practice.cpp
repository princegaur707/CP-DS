#include<bits/stdc++.h>
using namespace std;
void Permute(char* ip, int i){
	if(ip[i] == '\0'){
		cout << ip << endl;
		return;
	}
	for(int j = i; ip[j]!='\0'; j++){
		swap(ip[i], ip[j]);
		Permute(ip, i + 1);
		swap(ip[i], ip[j]);
	}
}
int main(){
	char ip[1000];
	cin >> ip;
	Permute(ip, 0);
}