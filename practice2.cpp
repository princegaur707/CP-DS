#include<bits/stdc++.h>
using namespace std;
int n;
int grid[10][10];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int total_count;
int ans = -1;

void input(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 1){
				total_count++;
			}
		}
	}
}
void Knight(int x, int y, int count){
	ans = max(ans, count);
	for(int i = 0; i < 8; i++){
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if(x1 >= 0 and x1 < n and y1 >=0 and y1 < n and grid[x1][y1] == 1){
			grid[x1][y1] = 0;
			Knight(x1, y1, count + 1);
			grid[x1][y1] = 1;//Backtrack
		}
	}
}
int main(){
	cin >> n;
	input();
	grid[0][0] = 0;
	Knight(0, 0, 1);
	cout << total_count - ans << endl;
}