/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
   ["aa","b"],
   ["a","a","b"]
  ]
*/

//1-:深度优先搜索
//在每一步都可以判断中间结果是否为合法结果，用回溯法
//一个长度为n 的字符串，有n-1个地方可以砍断，每个地方可断可不断，因此复杂度为 2^(n-1)
//时间复杂度2^n 空间复杂度n
//STL substr()主要功能是复制子字符串，要求从指定位置开始，并具有指定的长度
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		if (s.empty())
			return result;

		vector<string> path;  //一个Patition方案
		dfs(s, path, result, 0);
		return result;
	}
private:
	//搜索必须以s[start] 开头的Patition方案
	void dfs(string &s, vector<string>& path, vector<vector<string>>& result, int start) {
		//一个Patition完成
		if (start == s.size()) {
			result.push_back(path);
			return;
		}
		for (int i = start; i < s.size(); i++) {
			if (isPalindrome(s, start, i)) { 	//从i位置砍一刀		
				path.push_back(s.substr(start, i - start + 1));
				dfs(s, path, result, i + 1); 	//继续砍下去
				path.pop_back(); 		//撤销
			}
		}
	}
	
	//辅助函数判断指定范围字符串是否是回文
	bool isPalindrome(const string &s, int start, int end) {
		while (start < end && s[start] == s[end]) {
			start++;
			end--;
		}
		return start >= end;
	}
};
