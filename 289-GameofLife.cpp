//Game of Life 生命游戏
/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

  Any live cell with fewer than two live neighbors dies, as if caused by under-population.
  Any live cell with two or three live neighbors lives on to the next generation.
  Any live cell with more than three live neighbors dies, as if by over-population..
  Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
  Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
  In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

/*
给定一个由0，1组成的矩阵，每一个元素表示一个细胞的存活，1存活，0死亡，其中下一次更新每个细胞的存活由上、下、左、右、左上、左下、右上、右下，八个细胞决定，存活规则如下：

当前细胞为存活状态时，当周围存活细胞不到2个时， 该细胞变成死亡状态。（模拟生命数量稀少）
当前细胞为存活状态时，当周围有2个或3个存活的细胞时， 该细胞保持原样。
当前细胞为存活状态时，当周围有3个以上的存活细胞时，该细胞变成死亡状态。（模拟生命数量过多）
当前细胞为死亡状态时，当周围恰好有3个存活细胞时，该细胞变成存活状态。 （模拟繁殖）

要求写一个函数，根据矩阵当前的状态，计算这个细胞矩阵的下一个状态。

题目要求in-place操作，考虑到每个元素都受附近8个元素的影响，必须使用一种中间状态来记录元素变化，这种中间状态应该能反应元素变化前和变化后的状态。

好在题目给出了四种变化状态，比较直观地给出了思路：

状态0： 死细胞->死细胞 
状态1： 活细胞->活细胞 
状态2： 活细胞->死细胞 
状态3： 死细胞->活细胞

对每个元素进行判断，根据附近8个元素及本身的状态可得到状态0~4中的一个，而下一个元素依然可根据上一元素的状态0~4，判断上一元素变化之前是什么状态。

而对所有元素标记状态0~4后，再一次遍历矩阵，所有元素的状态对2取余，那么状态0和2就变成死细胞，状态1和3就是活细胞，达成目的。
*/

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int rows = board.size();
		if (rows == 0)
			return;
		int colums = board[0].size();
		if (colums == 0)
			return;
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < colums; j++) {
				int sum = getNeighbor(board, rows, colums, i, j);  //统计周围细胞状态
				if (sum == 2) {
					continue;
				} else if (sum == 3) {
					board[i][j] = board[i][j] == 0 ? 3 : 1;
				} else {
					board[i][j] = board[i][j] == 1 ? 2 : 0;
				}
			}
		}

		//输出下一状态
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < colums; j++) {
				board[i][j] %= 2;
			}
		}
	}

private:
	//统计周围细胞状态
	int getNeighbor(vector<vector<int>> board, int rows, int colums, int x, int y) {
		int sum = 0;
		for (int i = x - 1; i <= x + 1 ;i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i == x && j == y)
					continue;
				if (i >= 0 && i < rows && j >= 0 && j < colums && (board[i][j] == 1 || board[i][j] == 2))
					sum++;
			}
		}

		return sum;
	}
};
