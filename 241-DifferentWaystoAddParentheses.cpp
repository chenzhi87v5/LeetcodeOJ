/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

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
与Unique Binary Search Trees II思路类似，可以对照看
本题参考Gcdofree的做法
左右子串分别计算所有可能，然后全排列
*/
//有点难度 理解 
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
