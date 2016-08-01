//Sqrt(x) 求平方根
/*
Implement int sqrt(int x).
Compute and return the square root of x.
*/

//这道题要求我们求平方根，我们能想到的方法就是算一个候选值的平方，然后和x比较大小，为了缩短查找时间，
//我们采用二分搜索法来找平方根
class Solution {
public:
	int mySqrt(int x) {
		int left = 1, right = x / 2;
		int last_mid;  //记录最近一次mid

		if(x < 2)
			return x;

		while(left <= right) {
			const int mid = left + (right - left) / 2;

			if (x / mid > mid) {                          //精辟：注意不要用x > mid * mid 会溢出
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
