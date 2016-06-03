/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

//动态规划
//初始化时令dp[i * i] = 1，状态转移方程为dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
//有点难
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		for (int i = 0; i * i <= n; i++) {
			dp[i * i] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; i + j * j <= n; j++) {
				dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
			}
		}

		return dp[n];
	}
};
