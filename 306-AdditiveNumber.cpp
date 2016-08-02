//Additive Number    加法数    前两个数和生成下一个数   数列

/*Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number 
in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199

Note: 
Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?*/

/*思路:
这道题定义了一种加法数，就是至少含有三个数字，除去前两个数外，每个数字都是前面两个数字的和，题目中给了许多例子，也限定了一
些不合法的情况，比如两位数以上不能以0开头等等，让我们来判断一个数是否是加法数。这题可用Brute Force的思想来解，我们让第一个
数字先从一位开始，第二个数字从一位，两位，往高位开始搜索，前两个数字确定了，相加得到第三位数字，三个数组排列起来形成一个字
符串，和原字符串长度相比，如果小于原长度，那么取出上一次计算的第二个和第三个数，当做新一次计算的前两个数，用相同的方法得到
第三个数，再加入当前字符串，再和原字符串长度相比，以此类推，直到当前字符串长度不小于原字符串长度，比较两者是否相同，相同返
回true，不相同则继续循环。如果所有情况都遍历完了还是没有返回true，则说明不是Additive Number，返回false，参见代码如下：*/
class Solution {
public:
	bool isAdditiveNumber(string num) {
		for (int i = 1; i < num.size(); i++) {
			for (int j = i + 1; j < num.size(); j++) {
				
				string s1 = num.substr(0, i);        //string.substr(i, n);
				string s2 = num.substr(i, j - i);

				////string 转 long long 、string.c _str()、atoll、atoi
				long long d1 = atoll(s1.c_str()), d2 = atoll(s2.c_str());
				
				if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) //不合法情况
					continue;
				
				long long next = d1 + d2;
				string nexts = to_string(next);     //long long 转 string  to_string(数字)
				string now = s1 + s2 + nexts;

				while (now.size() < num.size()) {
					d1 = d2;
					d2 = next;
					next = d1 + d2;
					nexts = to_string(next);
					now += nexts;
				}
				if (now == num)
					return true;
			}
		}
		return false;
	}
};
