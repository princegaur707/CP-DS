#include<bits/stdc++.h>
using namespace std;
bool visited[1001][1001];
bool solution[1001][1001];
bool Rat_in_maze(char maze[][1001], int i, int j, int m, int n)
{
	if(i == m and j == n)
	{
		solution[i][j] = 1;
		for(int x = 0; x <= m; x++)
		{
			for(int y = 0; y <=n; y++)
			{
				cout << solution[x][y] << " ";
			}
			cout << endl;
		}
		return true;
	}
	if(visited[i][j])
		return false;
	visited[i][j] = 1;
	solution[i][j] = 1;
	if(j + 1 <= n and !visited[i][j + 1])
	{
		bool step = Rat_in_maze(maze, i, j + 1, m, n);
		if(step)
			return true;
	}
	if(i + 1 <= m and !visited[i + 1][j])
	{
		bool step = Rat_in_maze(maze, i + 1, j, m, n);
		if(step)
			return true;
	}
	solution[i][j] = 0; //backtrack
	return false;
}
int main()
{
	int m;
	int n;
	cin >> m >> n;
	char maze[1001][1001];
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
			if(maze[i][j] == 'X')
				visited[i][j] = 1;
		}
	}
	if(!Rat_in_maze(maze,0, 0, m -1, n -1))
		cout << "-1";
}