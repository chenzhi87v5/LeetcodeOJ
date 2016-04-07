/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include<iostream>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

/*1 - mySolution: */
/*
class Solution {
public:
	int myAtoi(string str) {
		long long int r = 0;
		int i = 0, key = 1;
		
		if (str.size() <= 0)
			return r;

		while (str[i] == ' ' && i < str.size())
			i++;
		if (i == str.size()) {
			return r;
		}else if (str[i] == '+') {
			i++;
		}else if (str[i] == '-') {
			i++;
			key = -1;
		}

		for (; i < str.size(); i++) {
			if(str[i] < '0' || str[i] > '9')
				break;
			r = r*10 + (int)(str[i] - '0');
			if (r > (long long int)INT_MAX + 1)
				break;
		}
		r *= key;
		if (r < INT_MIN || r > INT_MAX)
			r = 0;
		
		return r;
	}
};
*/

/*2-Answers:*/
class Solution {
public:
	int myAtoi(string str) {
		int num = 0, sign = 1 , i = 0;
		const int n = str.size();

		while (str[i] == ' ' && i < n)
			i++;
		if (str[i] == '+')
			i++;
		else if (str[i] == '-') {
			sign = -1;
			i++;
		}
		
		for (; i < n; i++) {
			if (str[i] < '0' || str[i] > '9')
				break;
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
				return sign == -1 ? INT_MIN : INT_MAX;
			}
			num = num*10 + str[i] - '0';
		}
		return num * sign;
	}
};



int main() 
{
	string str = "  -0012a42";
	Solution ati;
	cout<<ati.myAtoi(str)<<endl;
	return 0;
}
