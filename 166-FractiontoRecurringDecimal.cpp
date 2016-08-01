//Fraction to Recurring Decimal 分数转循环小数
/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

Hint:
	1.No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
	2.Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
	3.Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
*/
//分数转换小数(包括循环小数)
//1、用一个map来记录n除以d的过程中被除数的变化，以及当被除数为n时相应的商在返回结果string中的位置，方便以后添加（
//2、负数变正数的时候会越界，下面的例子2^31 = 2 147 483 648，int表示范围（-2147483648~2147483647），所以要用long long
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res = "";
		//参数检测
		if (numerator == 0)
			return "0";
		if (denominator == 0)
			return res;
		
		long long n = numerator;
		long long d = denominator;
		//正负预处理
		if ((n < 0 && d > 0) || (n > 0 && d < 0))
			res = "-";
		if (n < 0)
			n = -n;
		if (d < 0)
			d = -d;

		res += to_string(n / d);           //to_string(int)  整数转化成string   atoi(string.c_str()); string 转int 
		n = n % d;
		if (n == 0)
			return res;
		res += '.';
		
		int pos = res.size();
		map<long long, int> record;  	//map记录被除数出现的位置方便插入括号
		while (n != 0) { 		//while结束表示是非循环小数即n被除数为0时
						//循环小数情况
			if (record.find(n) != record.end()) {
				res.insert(res.begin() + record[n], '(');
				res += ')';
				return res;
			}

			record[n] = pos;
			res += char(n * 10 / d + '0');
			pos++;
			n = (n * 10) % d;
		}
		return res;
	}
}
