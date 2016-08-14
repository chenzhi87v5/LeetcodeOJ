/*八皇后问题 -> N皇后问题 / N皇后排列次数*/
class Solution {
public:
	vector<vector<int> > placeQueens(int n) {
		vector<vector<int> > res;
		vector<int> pos(n, -1);
		placeQueensDFS(pos, 0, res);
		return res;
		// res.size();
	}
	
	void placeQueensDFS(vector<int> &pos, int row, vector<vector<int> > &res) {
		int n = pos.size();
		if (row == n) 
			res.push_back(pos);
		else {
			for (int col = 0; col < n; ++col) {
				if (isValid(pos, row, col)) {
					pos[row] = col;
					placeQueensDFS(pos, row + 1, res);
					pos[row] = -1;
				}
			}
		}
	}

	bool isValid(vector<int> &pos, int row, int col) {
		for (int i = 0; i < row; ++i) {
			if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
				return false；
			}
		}
		return true;
	}
}
