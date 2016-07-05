//Divide Two Integers 两数相除
/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.
*/
// int取值范围： -2147483648～2147483647
//加 减 位运算
class Solution {
public:
	int divide(int dividend, int divisor) {
		// dividend = INT_MIN时 -dividend 溢出
		long long a = dividend >= 0 ? dividend : -(long long)dividend;
		long long b = divisor >= 0 ? divisor : -(long long)divisor;

		long long result = 0;
		while (a >= b) {
			long long c = b;
			for (int i = 0; a >= c; i++, c <<= 1) {   //关键点:每次除数翻倍，加速
				a -= c;
				result += 1 << i;
			}
		}
		result = ((dividend^divisor) >> 31) ? -result : result;	
		
		//判断溢出情况
		if (result > INT_MAX)
			return INT_MAX;
		return result;
	}		        
};

int main()
{
	Solution A;
	cout<< A.divide(-2147483648, -1)<<endl;
	return 0;
}
