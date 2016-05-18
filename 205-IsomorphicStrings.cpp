/* 
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

/*
 返回true需要满足两个条件：

 1、不能出现s中的一个字符对应到t中两个不同的字符
 2、不能出现s中的两个不同字符对应到t中同一个字符  （注意这点容易忽视）
*/
//使用unordered_map 
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		//边界检查
		if (s.size() != t.size())
			return false;
		
		unordered_map<char, char> m1; // s-->t
		unordered_map<char, char> m2; // t-->s
		
		for (int i = 0; i < s.size(); i++) {
			if (m1.find(s[i]) != m1.end() && m1[s[i]] != t[i])
				return false;
			if (m2.find(t[i]) != m2.end() && m2[t[i]] != s[i])
				return false;

			m1[s[i]] = t[i];
			m2[t[i]] = s[i];
		}

		return true;
	}
};
