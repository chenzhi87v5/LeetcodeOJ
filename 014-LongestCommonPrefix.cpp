/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/

/*1-mySolution:*/

/*2-Answers: */
//2-1 纵向比较 ---实现
//2-2 横向比较 --- 每个字符串与第0个字符串比较

//注意：vector 的使用 类似数组[]或者使用迭代器iterator
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		for (int idx = 0; idx < strs[0].size(); idx++) {
			for (int i = 1; i < strs.size(); i++) {
				if (strs[i][idx] != strs[0][idx])
					return strs[0].substr(0, idx);
			}
		}
		return strs[0];
	}
};

int main()
{
	return 0;
}
