//Reverse String 翻转字符串                  注意反转字符串中的单词题 151

/*Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".*/

//简单
class Solution {
public:
	string reverseString(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			swap(s[left++], s[right--]);
		}
		return s;
	}
};
