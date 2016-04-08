/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

/*1-mySolution:*/
//2-Answers:暴力枚举法 复杂度3^n
//递归法 -------Good   学会递归思想
//迭代法

/*递归法解题*/
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
			dfs(digits, cur + 1, path + c, result);
		}		
	}

};
