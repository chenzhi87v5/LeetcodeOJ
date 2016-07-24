//Valid Parentheses 验证括号
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*
这道题让我们验证输入的字符串是否为括号字符串，包括大括号，中括号和小括号。这里我们需要用一个栈，我们开始遍历输入字符串，
如果当前字符为左半边括号时，则将其压入栈中，如果遇到右半边括号时，若此时栈为空，则直接返回false，如不为空，
则取出栈顶元素，若为对应的左半边括号，则继续循环，反之返回false，代码如下： 
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;

		for (auto c : s) {
			if (c == '(' || c == '[' || c == '{') stk.push(c);
			else {
				if (stk.empty()) return false;
				if (c == ')' && stk.top() != '(') return false;
				if (c == ']' && stk.top() != '[') return false;
				if (c == '}' && stk.top() != '{') return false;
				stk.pop();
			}
		}
		return stk.empty();
	}
};
