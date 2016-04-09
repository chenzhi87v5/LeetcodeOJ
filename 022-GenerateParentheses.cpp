/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

/*1-mySolution:不会 知道要递归*/

/*2-Answers:*/
//要点：1.深度优先搜索法 2.递归法(递归思想)
//JiuZhang:递归法
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n > 0)
			generate(n, "", 0, 0, result);
		return result;
	}

	// 递归方程
	// l 表示 '(' 出现的次数，r表示 ')'出现的次数
	void generate(int n, string s, int l, int r, vector<string> &result) {
		if (l == n) {
			result.push_back(s.append(n - r, ')'));
			return;
		}
		generate(n, s + '(', l + 1, r, result);
		if (l > r)
			generate(n, s + ')', l, r + 1, result);
	}
};
