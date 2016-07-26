//Different Ways to Add Parentheses 添加括号的不同方式
/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to 
group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
*/

/*
这道题让给我们一个可能含有加减乘的表达式，让我们在任意位置添加括号，求出所有可能表达式的不同值。这道题跟之前的那道
Unique Binary Search Trees II 独一无二的二叉搜索树之二用的方法一样，用递归来解，划分左右子树，递归构造。
*/ 
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> ret;
		//循环
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
				
				vector<int> left = diffWaysToCompute(input.substr(0, i));   //递归
				vector<int> right = diffWaysToCompute(input.substr(i + 1));
			
				for (int j = 0; j < left.size(); j++) {
					for (int k = 0; k < right.size(); k++) {
						if (input[i] == '+') {
							ret.push_back(left[j] + right[k]);
						} else if (input[i] == '-') {
							ret.push_back(left[j] - right[k]);
						} else {
							ret.push_back(left[j] * right[k]);
						}
					}
				}
			}
		}

		//当只有一个数字时
		if (ret.empty()) {
			ret.push_back(atoi(input.c_str()));
		}

		return ret;
	}
};
