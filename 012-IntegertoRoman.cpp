/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include<iostream>

using namespace std;

/*1-mySolution: 简单 冗余代码*/
/*
class Solution {
public:
	string intToRoman(int num) {
		string result;
		int d1, d2, d3, d4;
		
		d1 = num /1000;
		for (int i = 0; i < d1 ; i++)
			result.append("M");
		
		num = num % 1000;
		d2 = num /100;
		if (d2 <= 3){
			result.append(d2, 'C');
		}else if (d2 == 4) {
			result.append("CD");
		}else if (d2 <= 8) {
			result.append("D");
			result.append(d2 - 5, 'C');
		}else if (d2 == 9) {
			result.append("CM");
		}

		num = num % 100;
		d3 = num / 10;
		if (d3 <= 3){
			result.append(d3, 'X');
		}else if (d3 == 4) {
			result.append("XL");
		}else if (d3 <= 8) {
			result.append("L");
			result.append(d3 - 5, 'X');
		}else if (d3 == 9) {
			result.append("XC");
		}

		d4 = num % 10;	
		if (d4 <= 3){
			result.append(d4, 'I');
		}else if (d4 == 4) {
			result.append("IV");
		}else if (d4 <= 8) {
			result.append("V");
			result.append(d4 - 5, 'I');
		}else if (d4 == 9) {
			result.append("IX");
		}
		
		return result;
	}
};
*/

/*2-Answers: 简洁代码*/

class Solution {
public:
	string intToRoman(int num) {
		const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40 ,10, 9, 5 ,4 ,1};
		const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

		string roman;
		for (size_t i = 0; num > 0; i++) {
			int count = num / radix[i];
			num %= radix[i];
			for (; count > 0; count--)
				roman += symbol[i];
		}
		return roman;
	}
};

int main()
{
	return 0;
}
