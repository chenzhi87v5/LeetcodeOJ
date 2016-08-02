//Basic Calculator II 基本计算器之二

/*Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division 
should truncate toward zero.
You may assume that the given expression is always valid.

Some examples:
	"3+2*2" = 7
	" 3/2 " = 1
	" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.*/

//实现简单计算器  栈实现,栈只记录结果值，巧妙算法
class Solution {
public:
	int calculate(string s) {
		if (s.size() == 0)
			return 0;

		stack<int> stk;
		int num = 0;
		char sign = '+';                 //默认加号

		for (int i = 0; i < s.size(); i++) {
			//记录每个连续的数字
			if (isdigit(s[i])) {
				num = num * 10 + s[i] - '0';
			}
			//当不为数字，不为空格，或者只有一个数字时情况                  
			if (!isdigit(s[i]) && ' ' != s[i] || i == s.size() - 1) { 
				if (sign == '-') {
					stk.push(-num);
				}
				if (sign == '+') {
					stk.push(num);
				}
				if (sign == '*') {
					int tmp = stk.top();
					stk.pop();
					stk.push(tmp * num);
				}
				if (sign == '/') {
					int tmp = stk.top();
					stk.pop();
					stk.push(tmp / num);
				}
				sign = s[i];
				num = 0;
			}
		}
		//最终记录结果
		int res = 0;
		while (!stk.empty()) {
			res += stk.top();
			stk.pop();
		}
		return res;
	}
};
