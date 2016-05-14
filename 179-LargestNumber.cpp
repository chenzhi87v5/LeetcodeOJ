/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

//理解题意，注意考虑边界特殊情况比如数字最前面的0
//转换成数字转换为string比大小（自定义比较函数，排序排序），注意特殊情况

#include<sstream>   //stream

//自定义比较函数
bool cmp(const string s1, const string s2) {
	return (s1 + s2) > (s2 + s1);
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> s_num(nums.size());      //vector初始化
		stringstream stream;			//stringstream的使用
		
		for (int i = 0; i < nums.size(); i++) {
			stream << nums[i];              //stringstream << >> .clear()
			stream >> s_num[i];
			stream.clear();
		}	
		
		sort(s_num.begin(), s_num.end(), cmp);   //STL算法sort排序
		
		string tmp_res; //中间结果
		for (int i = 0; i < s_num.size(); i++) {
			tmp_res += s_num[i];
		}

		string res; //要排除tmp_res最前面的0
		bool flag = false;
		for (int i = 0; i < tmp_res.size(); i++) {
			if (tmp_res[i] != '0') {
				res.push_back(tmp_res[i]);
				flag = true;
			} else if (flag){
				res.push_back(tmp_res[i]);
			}
		}
		
		//考虑全为0的情况
		if (!flag) {
			res.push_back('0');
		}

		return res;
	}
};
