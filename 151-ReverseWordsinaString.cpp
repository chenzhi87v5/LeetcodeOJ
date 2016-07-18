//Reverse Words in a String 翻转字符串中的单词
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

Clarification:
	1.What constitutes a word?
	  A sequence of non-space characters constitutes a word.
	2.Could the input string contain leading or trailing spaces?
	  Yes. However, your reversed string should not contain leading or trailing spaces.
	3.How about multiple spaces between two words?
	  Reduce them to a single space in the reversed string.
*/

//从后往前遍历
class Solution {
public:
	void reverseWords(string &s) {
		string ss;
		int i = s.length() - 1;
		while (i >= 0) {
			//遇到非空字符停止
			while (i >= 0 && s[i] == ' ')
				i--;
			if (i < 0)
				break;
			//加上 ' '
			if (ss.length() != 0)
				ss.push_back(' ');
			//存储word于temp
			string temp;
			for (;i >= 0 && s[i] != ' '; i--)
				temp.push_back(s[i]);
			reverse(temp.begin(), temp.end());
			//加入结果集
			ss.append(temp);
		}

		s = ss;
		return;
	}
};

