//Generate Parentheses 生成括号
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

/*
在LeetCode中有关括号的题共有三道，除了这一道的另外两道是 Valid Parentheses 验证括号和 Longest Valid Parentheses 最长有效括号，
这道题给定一个数字n，让生成共有n个括号的所有正确的形式，对于这种列出所有结果的题首先还是考虑用递归Recursion来解，由于字符串只
有左括号和右括号两种字符，而且最终结果必定是左括号3个，右括号3个，所以我们定义两个变量left和right分别表示剩余左右括号的个数，
如果在某次递归时，左括号的个数大于右括号的个数，说明此时生成的字符串中右括号的个数大于左括号的个数，即会出现')('这样的非法串，
所以这种情况直接返回，不继续处理。如果left和right都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存入结
果中后返回。如果以上两种情况都不满足，若此时left大于0，则调用递归函数，注意参数的更新，若right大于0，则调用递归函数，同样要更
新参数。代码如下:
*/
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n > 0) generateDFS(n, n, "", res);
		return res;
	}

	void generateDFS(int left, int right, string out, vector<string> &res) {
		if (left > right) return;
		if (left == 0 && right == 0) res.push_back(out);
		else {
			if (left > 0) generateDFS(left - 1, right, out + '(', res);
			if (right > 0) generateDFS(left, right - 1, out + ')', res);
		}
	}
};
