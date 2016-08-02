//翻转字符串中的单词  "hello world" -> world hello  常考面试题
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty()) 
			return;
		reverseWord(s, 0, s.size() - 1);
		for (int i = 0, j = 0; i < s.size(); i++) {
			if (i == s.size() - 1) {
				reverseWord(s, j, i);
			}
			if (s[i] == ' ') {
				reverseWord(s, j, i - 1);
				j = i + 1;
			}
		}
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
