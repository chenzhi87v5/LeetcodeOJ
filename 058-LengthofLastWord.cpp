/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

//1-从后往前遍历
//也可以使用STL
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty())
			return 0;
		
		int len = 0, i = s.size() -1;
		
		while (s[i] == ' ') 
			i--;
		
		while (s[i] != ' ' && i >= 0) {
			len++;
			i--;
		}

		return len;
	}
};
