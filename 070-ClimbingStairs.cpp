/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

//1-:理解题意
//斐波那契数列 f(n) = f(n - 1) + f(n - 2)

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2)
			return n;
		int *step = new int[n];
		int res;

		step[0] = 1;
		step[1] = 2;
		for (int i = 2; i < n; i++)
			step[i] = step[i - 1] + step[i - 2];
		res = step[n - 1];
		delete step;
		return res;
	}
};
