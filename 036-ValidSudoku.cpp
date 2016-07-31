//Valid Sudoku 验证数独
/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
..
Sudoku board
..
A partially filled sudoku which is valid.
*//*
There are just 3 rules to Sudoku.
1.Each row must have the numbers 1-9 occuring just once.
2.Each column must have the numbers 1-9 occuring just once.
3.And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool used[9];
		for (int i = 0; i < 9; i++) {	
			fill(used, used + 9, false);
			for (int j = 0; j < 9; j++)      //检查行 
				if (!check(board[i][j], used))
					return false;

			fill(used, used + 9, false);
			for (int j = 0; j < 9; j++ )     //检查列
				if (!check(board[j][i], used))
					return false;
		}	

		for (int r = 0; r < 3; r++)  //检查9个子格子
			for (int c = 0; c < 3; c++) {
				fill(used, used + 9, false);

				for (int i = r * 3; i < r * 3 + 3; i++)
					for (int j = c * 3; j < c * 3 + 3; j++)
						if (!check(board[i][j], used))
							return false;
			}
		return true;
	}
	//检查数字是否已经出现:1.已经出现返回false; 2.未出现返回true并将出现标示位置为true
	//注意参数是数组传递的是数组的地址
	bool check(char ch, bool used[9]) {
		if (ch == '.')
			return true;
		if (used[ch - '1'])
			return false;
		return used[ch - '1'] = true;
	}
};
