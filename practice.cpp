#include<bits/stdc++.h>
using namespace std;
bool visited[1001][1001];
bool solution[1001][1001];
bool Rat_In_Maze(char maze[][1001], int i, int j, int n, int m)
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
		cout << endl;
		return false;
	}
	if(visited[i][j] == 1)
		return false;
	visited[i][j] = 1;
	solution[i][j] = 1;
	if(j + 1 <= m and visited[i][j + 1] == 0)
	{
		bool step = Rat_In_Maze(maze, i, j + 1, n, m);
		if(step == 1)
			return true;
	}
	if(i + 1 <= n and visited[i + 1][j] == 0)
	{
		bool step = Rat_In_Maze(maze, i + 1, j, n, m);
		if(step == 1)
			return true;
	}
	solution[i][j] = 0;
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	char maze[1001][1001];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> maze[i][j];
			if(maze[i][j] == 'X')
				visited[i][j] = 1;
		}
	}
	n--, m--;//as we are following ZERO based indexing while in question 1 based in given
	Rat_In_Maze(maze, 0, 0, n, m);
}
