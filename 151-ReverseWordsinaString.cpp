//Reverse Words in a String 翻转字符串中的单词
/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

For C programmers: Try to solve it in-place in O(1) space.

Clarification:
	1.What constitutes a word?
	     A sequence of non-space characters constitutes a word.
	2.Could the input string contain leading or trailing spaces?
	    Yes. However, your reversed string should not contain leading or trailing spaces.
	3.How about multiple spaces between two words?
	    Reduce them to a single space in the reversed string.
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int i = 0, j = 0, k = 0, wordCount = 0;
		while (true) {
			while (i < s.size() && s[i] == ' ') i++;
			if (i == s.size()) break;
			if (wordCount) s[j++] = ' ';
			k = j;
			while (i < s.size() && s[i] != ' ') {
				s[j] = s[i];
				j++;
				i++;
			}
			reverseWord(s, k, j - 1);
			++wordCount;
		}
		s.resize(j);
		reverseWord(s, 0, j - 1);
	}

	void reverseWord(string &s, int i, int j) {
		while (i < j) {
			swap(s[i++], s[j--]);
		}
	}
};

int main() {
	string str = " the  sky is blue ";
	Solution A;
	A.reverseWords(str);
	cout << str << endl;
	return 0;
}
