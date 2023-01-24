//https://leetcode.com/problems/sudoku-solver/description/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char ch ='1'; ch <= '9'; ch++)
                    {
                        if(isValid(board, ch, i, j))
                        {
                            board[i][j] = ch;
                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';//there is no character that can be filled here so backtrack
                        }
                    }
                    return false;//if we are unable to fill this empty location with any character 
                    //that means answer is not possible from this recursion call.
                }
            }
        }
        return true;//if till here nothing is returned it means all boxes are filled now
    }
    int isValid(vector<vector<char>>& board, char ch, int row, int col){
        for(int i = 0; i < 9; i++)
        {
            int ans = i;
            if(board[row][i] == ch)
                return false;
            if(board[i][col] == ch)
                return false;
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;   
        }
        return true;
    }
};