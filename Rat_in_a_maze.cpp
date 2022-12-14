//https://hack.codingblocks.com/app/contests/3317/11/problem
#include<bits/stdc++.h>
using namespace std;
int visited[1001][1001];
int solution[1001][1001];
bool Rat_in_maze(char maze[][], int i, int j, int n, int m)
{
	if(i == n and j == m)
	{
		solution[i][j] = 1;
		for(int x = 0; x <= n; x++)
		{
			for(int y = 0; y <= m; y++)
			{
				cout << solution[x][y] << " ";
			}
			cout << endl;
		}
		return true;
	}
	if(visited[i][j] == 1)
		return false;
	visited[i][j] = 1;
	solution[i][j] = 1;
	if(i + 1 <= n and visited[i + 1][j] == 0)
	{
		bool step = Rat_in_maze(maze, i + 1, j, n, m);
		return step;
	}
	else if(j + 1 <= m and visited[i][j + 1] == 0)
	{
		bool step = Rat_in_maze(maze, i, j + 1, n, m);
		return step;
	}
	solution[i][j] = 0;//backtrack
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	char maze[n][m];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char temp;
			cin >> maze[i][j]
			if(maze[i][j] == 'X')
				visited[i][j] = 1;
		}
	}
	if(!Rat_in_maze(maze, 0, 0, n - 1 , m - 1))// n and m reduced by 1 as we are following 0 based indexing
		cout << "-1";
}
