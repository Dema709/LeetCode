#include "test_runner.h"

using namespace std;

class Solution  {
public:
	bool isValidSudoku(vector<vector<char>> & board){
		//Проверка по рядам и столбцам
		for (int i=0;i<9;i++){
			set<int> s1, s2;
			
			for (int j=0;j<9;j++){

				if (board[i][j]>'0'){
					if (s1.count(board[i][j]-'0')){
						//cout<<"R[1]";
						return false;
					}
					s1.insert(board[i][j]-'0');
				}
				if (board[j][i]>'0'){
					if (s2.count(board[j][i]-'0')){
						//cout<<"R[2]";
						return false;
					}
					s2.insert(board[j][i]-'0');
				}
			}
		}
		
		//Проверка по квадратам 3х3
		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				set<int> s;
				for (int k=0;k<3;k++){
					for (int l=0;l<3;l++){
						//cout<<"ijkl["<<i<<j<<k<<l<<']'<<endl;
						if (board[i*3+k][j*3+l]>'0'){
							if (s.count(board[i*3+k][j*3+l]-'0')){
								//cout<<"R[3]["<<i<<j<<k<<l<<"]"<<endl;
								return false;
							}
							s.insert(board[i*3+k][j*3+l]-'0');
						}
					}
				}
			}
		}
		
		return true;
	}
};


int main() {
	
	{
		vector<vector<char>> sudoku_board = {
			{'5','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'}
		};
		//cout<<Solution().isValidSudoku(sudoku_board);
		ASSERT(Solution().isValidSudoku(sudoku_board));
	}
	
	{
		vector<vector<char>> sudoku_board = {
			{'8','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'}
		};
		//cout<<Solution().isValidSudoku(sudoku_board);
		ASSERT(!Solution().isValidSudoku(sudoku_board));
	}
	
	{
		vector<vector<char>> sudoku_board = {
			{'.','.','4','.','.','.','6','3','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'5','.','.','.','.','.','.','9','.'},
			{'.','.','.','5','6','.','.','.','.'},
			{'4','.','3','.','.','.','.','.','1'},
			{'.','.','.','7','.','.','.','.','.'},
			{'.','.','.','5','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'},
			{'.','.','.','.','.','.','.','.','.'}
		};
		//cout<<Solution().isValidSudoku(sudoku_board);
		ASSERT(!Solution().isValidSudoku(sudoku_board));
	}
	
	cout<<endl<<"TESTS OK!"<<endl;
	
	return 0;
}

/*
Valid Sudoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
	
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/