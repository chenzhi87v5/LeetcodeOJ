//Letter Combinations of a Phone Number 电话号码的字母组合
/*
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
		Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
//递归法 -------Good   学会递归思想
/*
这道题让我们求电话号码的字母组合，即数字2到9中每个数字可以代表若干个字母，然后给一串数字，求出所有可能的组合，相类似的题目有 
Path Sum II 二叉树路径之和之二，Subsets II 子集合之二，Permutations 全排列，Permutations II 全排列之二，Combinations 组合项， 
Combination Sum 组合之和和 Combination Sum II 组合之和之二等等。我们用递归Recursion来解，我们需要建立一个字典，用来保存每个
数字所代表的字符串，然后我们还需要一个变量cur，记录当前生成的字符串的字符个数，实现套路和上述那些题十分类似，代码如下： 
*/
class Solution {
public:

	// 0 1 2 3 ...
	const vector<string> keyboard { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	//实现具体函数
	vector<string> letterCombinations(string digits) {
		if (digits == "")
			return {};

		vector<string> result;
		dfs(digits, 0, "", result);
		return result;
	}

	//递归函数
	void dfs(const string &digits, size_t cur, string path, vector<string> &result) {
		//递归终点
		if (cur == digits.size()) {
			result.push_back(path);
			return;
		}

		//继续递归，但是参数变化了
		for (auto c : keyboard[digits[cur] - '0']) {
			path.push_back(c);
			dfs(digits, cur + 1, path, result);
			path.pop_back();
		}		
	}
};
