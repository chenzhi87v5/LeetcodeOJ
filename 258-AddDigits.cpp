/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

	A naive implementation of the above process is trivial. Could you come up with other methods?
	What are all the possible results?
	How do they occur, periodically or randomly?
	You may find this Wikipedia article useful.
*/

//法一：按照题意给的解题步骤计算

class Solution {
public:
	int addDigits(int num) {
		if (num < 10)
			return num;
		int next = getNext(num);
		while (next >= 10) {
			next = getNext(next);
		}
		return next;
	}
	
	int getNext(int num) {
		stringstream ss;
		string s;
		int sum = 0;
		ss << num;
		ss >> s;
		for (auto ch : s) {
			sum += (ch - '0');
		}

		return sum;
	}
};

//法二：找数学规律
class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;	
	}
};




