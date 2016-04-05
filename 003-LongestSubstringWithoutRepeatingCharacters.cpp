/*
 Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

/*1-mySolution:*/
//.......

/*2-Answer-贪心法*/
//贪心法：单个子问题决定父问题
//动规法：单个子问题只能影响父问题不能决定父问题
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const int ASCII_MAX = 256; // ASCII 共有256个
		int last[ASCII_MAX]; //记录字符上次出现的位置
		int start = 0; //记录当前子串的起始位置

		fill(last, last + ASCII_MAX, -1); //所有字符位置初始化为-1
		int max_len = 0;
		for (int i = 0; i < s.size(); i++) {
			if (last[s[i]] >= start) {
				max_len = max (i - start, max_len);
				start = last[s[i]] + 1;
			}
			last[s[i]] = i;
		}
		return max((int)s.size() - start, max_len); //勿忘最后一次取值

	}
};

int main() {

	return 0;
}
