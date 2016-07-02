//Word Search 词语搜索
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
/*
这道题是典型的深度优先遍历DFS的应用，原二维数组就像是一个迷宫，可以上下左右四个方向行走，我们以二维数组中每一个数都作为起点和给定字符串做匹配，我们还需要一个和原数组等大小的visited数组，是bool型的，用来记录当前位置是否已经被访问过，因为题目要求一个cell只能被访问一次。如果二维数组board的当前字符和目标字符串word对应的字符相等，则对其上下左右四个邻字符分别调用DFS的递归函数，只要有一个返回true，那么就表示可以找到对应的字符串，否则就不能找到，具体看代码实现如下： 
*/
//深搜 + 递归 时间复杂度 n^2*m^2, 空间复杂度n^2
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;
		if (board.empty() || board[0].empty()) return false;

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

		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y] || board[x][y] != word[index])  //剪枝
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
