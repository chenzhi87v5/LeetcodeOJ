/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

//1-:动态规划 状态转移方程 f(i) 表示是s[0, i]是否可以分词，则状态转移方程
	//f(i) = any_of(f(j) && s[j + 1, i] E wordList),0<= j <i

//法一：深搜时间复杂度2^n 超时 (即递归法超时不可取)

//法二：动规 时间复杂度n^2 空间复杂度n  （思路有点难）
class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		//长度为n的字符串有n + 1隔板 vector f记录是否可分状态
		vector<bool> f(s.size() + 1, false);
		f[0] = true; //空字符串
		
		for (int i = 1; i <= s.size(); i ++) {    //从第i个字符向前到位置j的substr
			for (int j = i - 1; j >= 0; j--) { 
				if (f[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					f[i] = true;
					break;
				}
			}
		}
	
		return f[s.size()];
	}
};
