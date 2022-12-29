//https://hack.codingblocks.com/app/contests/3317/11/problem
#include<bits/stdc++.h>
using namespace std;
bool visited[1001][1001];
bool solution[1001][1001];
bool Rat_in_maze(char maze[][1001], int i, int j, int m, int n)
{
	if(i == m and j == n)
	{
		solution[i][j] = 1; //last block also to be marked as answer
		for(int x = 0; x <= m; x++)
		{
			for(int y = 0; y <= n; y++)
			{
				cout << solution[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return false; //return true if want to show only best solution
	}
	if(visited[i][j])
		return false;//already visited or blocked path cannot result to new solution
	visited[i][j] = true;//visiting this block for possible answer
	solution[i][j] = true;//assuming this might result to answer
	if(j + 1 <= n and !visited[i][j + 1])//checking if moving right(most preferable) can result to any solution
	{
		bool step = Rat_in_maze(maze, i, j + 1, m, n);
		if(step == 1)
			return true;
	}
	if(i + 1 <= m and !visited[i + 1][j])//checking if moving downward can result to any solution
	{
		bool step = Rat_in_maze(maze, i + 1, j, m, n);
		if(step == 1)
			return true;
	}
	solution[i][j] = false;//backtracking as this cannot result to answer
	return false;
}
int main()
{
	int m, n;
	cin >> m >> n;
	char maze[1001][1001];
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
			if(maze[i][j] == 'X')
				visited[i][j] = true;
		}
	}
	Rat_in_maze(maze, 0, 0, m - 1 , n - 1);// n and m reduced by 1 as we are following 0 based indexing
}
/*
Approach:
We will be marking the positions which we have visited(may result into solution or not)
as 1 in the visited matrix which will denotes we don't need to visit this pos. anymore
We will be marking the positions which can result into solution as 1 only.
*/