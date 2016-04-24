/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


//1-:逆波兰式 求值
//递归 时间复杂度n 空间复杂度logn
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int x, y;
		//将vector 当栈处理 末尾元素是栈顶
		auto token = tokens.back();
		tokens.pop_back();
		if (is_operator(token)) {
			y = evalRPN(tokens);
			x = evalRPN(tokens);
			if (token[0] == '+')
				x += y;
			else if (token[0] == '-')
				x -= y;
			else if (token[0] == '*')
				x *= y;
			else
				x /= y;
		} else {
			size_t i;
			x = stoi(token, &i);
		}

		return x;
	}

private:
	//判断是否是算术运算符
	bool is_operator(const string &op) {
		return op.size() == 1 && string("+-*/").find(op) != string::npos;
	}
};
