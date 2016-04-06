/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include<iostream>

using namespace std;

/*1-mySolution：*/
/*c++中负数取10的余数还是负数,与正数的处理类似*/
/*
class Solution {
public:
	int reverse(int x) {
		int i;
		long long int res = 0;
		
		while (x != 0) {
			i = x%10;
			res = res*10 + i;
			x = x/10;
		}
		
		if (res < INT_MIN || res > INT_MAX)
			return 0;
		return res;
	}
};
*/
/*2-短小精悍*/
class Solution {
public:
	int reverse(int x) {
		long long int r = 0;
		
		for (; x ;x /= 10)
			r = r*10 + x%10;
		
		if (r < INT_MIN || r > INT_MAX)
			return 0;
		
		return r;
	}
};


int main()
{
	cout<< -123%10 <<endl;
}
