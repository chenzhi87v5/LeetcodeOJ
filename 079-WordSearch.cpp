/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
      word = "ABCCED", -> returns true,
      word = "SEE", -> returns true,
      word = "ABCB", -> returns false.
*/

//1-: 有点难度

//2-:深搜 + 递归
//时间复杂度 n^2*m^2, 空间复杂度n^2
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		const int m = board.size();
		const int n = board[0].size();
		
		vector<vector<bool>> visited(m, vector<bool>(n, false)); //记录cell访问标志
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if (dfs(board, word, 0, i, j, visited))   //深度递归
					return true;

		return false;
	}
private:
	static bool dfs(const vector<vector<char>>& board, const string &word, int index, int x, int y, vector<vector<bool>> &visited) {
		if (index == word.size())  //收敛条件
			return true;

		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())  //越界，终止条件
			return false;

		if (visited[x][y])         //已经访问过，剪枝
			return false;

		if (board[x][y] != word[index])  //不相等，剪枝
			return false;

		visited[x][y] = true;
		bool ret = dfs (board, word, index + 1, x - 1, y, visited) || //上
			   dfs (board, word, index + 1, x + 1, y, visited) || //下
			   dfs (board, word, index + 1, x, y - 1, visited) || //左
			   dfs (board, word, index + 1, x, y + 1, visited);   //右
		visited[x][y] = false;
		
		return ret;
	}
};
