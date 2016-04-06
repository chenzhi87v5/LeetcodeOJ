/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#include<iostream>

using namespace std;

/*寻找数学规律,时间复杂度n，空间复杂度1*/
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1 || s.size() <= 1)
			return s;

		string result;

		for (int i = 0; i < numRows; i++) {
			for (int j = 0, index = i; index < s.size(); j++, index = (2*numRows - 2)*j + i) {
				result.append(1, s[index]); //垂直元素
				if (i == 0 || i == numRows -1)
					continue;
				if (index + (numRows - i - 1)*2 < s.size())//斜对角元素
					result.append(1, s[index + (numRows -i -1)*2]);
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}
