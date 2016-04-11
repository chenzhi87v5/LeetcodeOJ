/*
Implement pow(x, n). 
*/

//1-超时
/*
class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
	
		if (n == 0) {
			return 1;
		}
		else if (n > 0) {
			while(n--){
				res *= x;
			}
			return res;
		} else {
			n = -n;
			while(n--){
				res *= x;
			}
			return 1.0 / res;
		}
	}
};
*/

//2-分治法 加速 
//二分法, x^n = x^(n/2) * x^(n/2) * x^(n%2)

class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0) 
			return 1.0 / power(x, -n);
		else 
			return power(x, n);
	}
private:
	//二分法
	double power(double x, int n) {
		if (n == 0)
			return 1;
		double v = power(x, n/2);
		if (n % 2 == 0)
			return v * v;
		else
			return v * v * x;
	}
};
