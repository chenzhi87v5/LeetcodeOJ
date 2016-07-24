//Longest Common Prefix 最长共同前缀
/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/

//2-1 纵向比较 ---
//2-2 横向比较 ---每个字符串与第0个字符串比较

//注意：vector 的使用 类似数组[]或者使用迭代器iterator
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";

		for (int idx = 0; idx < strs[0].size(); idx++) {
			for (int i = 1; i < strs.size(); i++) {
				if (idx >= strs[i].size() || strs[i][idx] != strs[0][idx])
					return strs[0].substr(0, idx);
			}
		}
		
		return strs[0];
	}
};

