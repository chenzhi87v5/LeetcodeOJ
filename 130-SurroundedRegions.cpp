//Surrounded Regions 包围区域
/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

*///从上下左右四个边界往里走，凡是能碰到的'O'，都是跟边界接壤的，应该保留设置为 'E'
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;

		int m = board.size();
		int n = board[0].size();
		
		if (m <= 2 || n <= 2 )
			return;
		
		//第0列 与 n - 1列
		for (int i = 0; i < m; i++) {
			if (board[i][0] == 'O')
				process(i, 0, board);
			if (board[i][n - 1] == 'O')
				process(i, n - 1,board);
		}

		//第0排 与 第 m - 1排
		for (int j = 0; j < n; j++) {
			if (board[0][j] == 'O')
				process(0, j, board);
			if (board[m - 1][j] == 'O')
				process(m - 1, j, board);
		}

		//剩余的O全是被包围的 置为 X ;同时将 E 置为 O
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				} else if (board[i][j] == 'E') {
					board[i][j] = 'O';
				}
			}
		}
	}

private:
	void process(int i, int j, vector<vector<char>>& board) {
		int m = board.size();
		int n = board[0].size();

		typedef pair<int, int> point;    	//使用pair 以及typedef
		queue<point> Q;                  	//队列
		Q.push(point(i, j));
		board[i][j] = 'E';
		while (!Q.empty()) {
			point tmp = Q.front();
			Q.pop();

			int x = tmp.first;         	//pair取值方法
			int y = tmp.second;

			//扩展 point(x, y)节点上下左右进行
			//上
			if (x != 0 && board[x - 1][y] == 'O') {
				Q.push(point(x - 1, y));
				board[x - 1][y] = 'E';
			}
			//下
			if (x != m - 1 && board[x + 1][y] == 'O') {
				Q.push(point(x + 1, y));
				board[x + 1][y] = 'E';
			}
			//左
			if (y != 0 && board[x][y - 1] == 'O') {
				Q.push(point(x, y - 1));
				board[x][y - 1] = 'E';
			}
			//右
			if (y != n - 1 && board[x][y + 1] == 'O') {
				Q.push(point(x, y + 1));
				board[x][y + 1] = 'E';
			}
		}
	}
};
