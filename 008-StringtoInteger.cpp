//String to Integer (atoi) 字符串转为整数
/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below 
and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/

/*各种特殊情况考虑及溢出*/
/*
1. 若字符串开头是空格，则跳过所有空格，到第一个非空格字符，如果没有，则返回0.
2. 若第一个非空格字符是符号+/-，则标记isPositive的真假，这道题还有个局限性，那就是在c++里面，
    +-1和-+1都是认可的，都是-1，而在此题里，则会返回0.
3. 若下一个字符不是数字，则返回0. 完全不考虑小数点和自然数的情况，不过这样也好，起码省事了不少。
4. 如果下一个字符是数字，则转为整形存下来，若接下来再有非数字出现，则返回目前的结果。
5. 还需要考虑边界问题，如果超过了整形数的范围，则用边界值替代当前值。
*/
class Solution {
public:
	int myAtoi(string str) {
		int num = 0, sign = 1 , i = 0;
		const int n = str.size();

		while (str[i] == ' ' && i < n)
			i++;
		if (str[i] == '+')
			i++;
		else if (str[i] == '-') {
			sign = -1;
			i++;
		}
		
		for (; i < n; i++) {
			if (str[i] < '0' || str[i] > '9')
				break;
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
				return sign == -1 ? INT_MIN : INT_MAX;
			}
			num = num*10 + str[i] - '0';
		}
		return num * sign;
	}
};
