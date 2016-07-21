//Evaluate Reverse Polish Notation 计算逆波兰表达式                         逆波兰式求解
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

/*
逆波兰表达式就是把操作数放前面，把操作符后置的一种写法，我们通过观察可以发现，第一个出现的运算符，其前面必有两个数字，当这个运算符和之前两个数字完成运算后从原数组中删去，把得到一个新的数字插入到原来的位置，继续做相同运算，直至整个数组变为一个数字 

这道题果然应该是栈的完美应用啊，从前往后遍历数组，遇到数字则压入栈中，遇到符号，则把栈顶的两个数字拿出来运算，把结果再压入栈中，直到遍历完整个数组，栈顶数字即为最终答案。代码如下: 

*/
class Solution {
public:
	bool inValid = false;
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty()) {
			inValid = true;
			return 0;
		}
		if (tokens.size() == 1)
			return atoi(tokens[0].c_str());
		stack<int> s;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
				s.push(atoi(tokens[i].c_str()));
			} else {
				int m = s.top();
				s.pop();
				int n = s.top();
				s.pop();
				if (tokens[i] == "+") s.push(n + m);
				if (tokens[i] == "-") s.push(n - m);
				if (tokens[i] == "*") s.push(n * m);
				if (tokens[i] == "/") s.push(n / m);
			}
		}
		return s.top();
	}
};
