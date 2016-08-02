//翻转字符串中的单词  "hello world" -> world hello  常考面试题
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty()) 
			return;
		vector<string> res;
		string ss;
		reverse(s.begin(), s.end());
		istringstream in(s);
		string val;
		while (getline(in, val, ' ')) {
			reverse(val.begin(), val.end());
			res.push_back(val);
		}
		for (int i = 0; i < res.size(); i++) {
			ss += res[i] + ' ';
		}
		ss.resize(ss.size() - 1);
		s = ss;
	}

};

int main() {
	string str = "hello world";
	Solution A;
	A.reverseWords(str);
	cout << str << endl;
	return 0;
}
