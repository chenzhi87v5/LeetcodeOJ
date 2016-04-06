/*
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

/*1-mySolution:？*/
//1:暴力枚举
//2:记忆搜索：递归方程

//3:动规法:列出方程 复杂度 n^2 -------------------Good
//4:Manacher' s Algorithm 复杂度 n --------------------Best Good -待定
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*3-动规法：Answers:*/
class Solution {
public:
	string longestPalindrome(string s) {
		const int n = s.size();
		bool f[n][n];
		fill_n(&f[0][0], n*n, false );
		
		//用vector 会超时
		//vector<vector<bool>> f(n, vector<bool>(n, false));

		size_t max_len = 1, start = 0; //最长回文子串长度, 起点

		for (size_t i = 0; i < s.size(); i++ ) {
			f[i][i] = true;
			for (size_t j = 0; j < i; j++) {
				f[j][i] = (s[j] == s[i] && (i -j < 2 || f[j + 1][i - 1]));
				if (f[j][i] && max_len < (i - j + 1)) {
					max_len = i - j + 1;
					start = j;
				}
			}
		}
		return s.substr(start, max_len);
	}
};

/*4-Manacher' s Algorithm*/
class Solution {
public:
	string longestPalindrome(string s) {
				

	}
}


int main() {

	return 0;
}
