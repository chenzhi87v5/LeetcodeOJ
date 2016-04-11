/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

/*1-mySolution:*/
//照搬竖式乘法
class Solution {
public:
	string multiply(string num1, string num2) {
		//反转num num[0]..是最低位
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		if ("0" == num1 || "0" == num2) {
			return "0";
		}

		string result = "";
		int flag = 0, steps = 0;

		//从num1低位依次取一个数与num2相乘
		for (int i = 0; i < num1.length(); i++) {
			int position = steps;
			
			//所取的num1[i]数与num2相乘
			for(int j = 0; j < num2.length(); j++) {
				int v = (num1[i] - '0') * (num2[j] - '0') + flag;

				if (position < result.length()) {
					v += result[position] - '0';
					result[position] = (v % 10) + '0';
				} else {
					result.append(1, (v % 10) + '0');
				}
				
				flag = v / 10;
				++position;
			}

			if (flag > 0) {
				result.append(1, flag + '0');
			}

			flag = 0;
			++steps;
		}

		reverse(result.begin(), result.end());
		return result;
	}
};
