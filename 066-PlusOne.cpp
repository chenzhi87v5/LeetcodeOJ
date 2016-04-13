/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

//1-:
//高精度加法
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		add(digits, 1);
		return digits;
	}
private:
	//0 <= digit <=9
	void add(vector<int>& digits, int digit) {
		int c = digit; //进位

		for (auto it = digits.rbegin(); it != digits.rend(); it++) {
			*it += c;
			c = *it / 10;
			*it %= 10;
		}

		if (c > 0)
			digits.insert(digits.begin(), 1);
	}
};
