/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

//1-:传统加倍法 超时
//2-: 二分法 类似pow 

class Solution {
public:
	int mySqrt(int x) {
		int left = 1, right = x / 2;
		int last_mid;  //记录最近一次mid

		if(x < 2)
			return x;

		while(left <= right) {
			const int mid = left + (right - left) / 2;
			if (x / mid > mid) {   //注意不要用x > mid * mid 会溢出
				left = mid + 1;
				last_mid = mid;
			} else if (x / mid < mid) {
				right = mid - 1;
			} else {
				return mid;
			}
		}

		return last_mid;
	}
};
