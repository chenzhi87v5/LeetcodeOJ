//翻转字符串中的单词  "hello world" -> world hello  常考面试题
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty()) 
			return;
		
		int i = 0, j = 0, k = 0, wordCount = 0;
		while (true) {
			while (i < s.size() && s[i] == ' ') 
				i++;
			if (i == s.size()) 
				break;

			if (wordCount) 
				s[j++] = ' ';
			
			k = j;
			while (i < s.size() && s[i] != ' ')
				s[j++] = s[i++];
			
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
	string str = "hello world";
	Solution A;
	A.reverseWords(str);
	cout << str << endl;
	return 0;
}
