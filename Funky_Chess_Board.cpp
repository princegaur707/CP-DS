//https://hack.codingblocks.com/app/contests/3317/288/problem
//If we do try this question by rat in maze way we will required 8 recursion
//as knight may have 8 choices  which will devastating to implement so will do
//this another way 
//We cannnot use visited array as knight can always revisit that place if choosing
//another path
#include<bits/stdc++.h>
using namespace std;
//create snippet as we will get grid questions later too
int n;
int grid[10][10];//10 is given in question
int Total_places_knight_can_move;
int ans = -1;
int N = 10;

int dx[] = {1, 1, 2, 2, -1, -1, -2 , -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1 , -1};

// single coordinate = (dx[i], dy[i])
void input_grid(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 1){
				Total_places_knight_can_move++;
			}
		}
	}
}
void Knight(int x, int y, int count){
	//once we have to show compiler how knight move
	ans = max(count, ans);//ans for overall count for particular path`
	for(int i = 0; i < 8; i++){
		int x_coordinate = x + dx[i];//one option to move
		int y_coordinate = y + dy[i];
		
		if(x_coordinate >=0 and x_coordinate<N and y_coordinate >=0 and y_coordinate<N
			and grid[x_coordinate][y_coordinate] == 1){
			
			grid[x_coordinate][y_coordinate] = 0;//1 means can travel but making it 0
			//we have marked this that you cannot visit anymore.

			Knight(x_coordinate, y_coordinate, count + 1);

			grid[x_coordinate][y_coordinate] = 1;//as I can visit this place by another path.
			//Backtrack
		}

	}
}//End of Knight here we don't need Knight b/c loop will itself get over similiary could 
//have been done in permute question.
int main(){
	cin >> n;
	input_grid();
	//cout << Knight(x, y, count); 
	//count-> no. of boxes you were able to visit in a single path since you are
	//standing at (0,0) so you can always include (0,0)

	grid[0][0] = 0;//b/c we have intitalized count as 1 in that way we are 
	//already including (0,0) co-ordinates all the time.
	
	Knight(0,0,1);

	//variable ans = stores the maximum no. of boxes you were able to visit 
	//in a single path

	cout << Total_places_knight_can_move - ans << endl;
}