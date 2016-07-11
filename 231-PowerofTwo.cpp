//Power of Two 判断2的次方数
/*
Given an integer, write a function to determine if it is a power of two. 
*/

//确定一个数是否是2的幂
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0)              //注意临界情况 0 不是2 的幂  1 = 2^0
			return false;
		
		while (n % 2 == 0) {
			n /= 2;
		}
		
		return n == 1;
	}
};

/*
如果一个数是2的次方数的话，根据上面分析，那么它的二进数必然是最高位为1，其它都为0，那么如果此时我们减1的话，则最高位会降一位，其余为0的位现在都为变为1，那么我们把两数相与，就会得到0，用这个性质也能来解题，而且只需一行代码就可以搞定，如下所示： 
*/

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n > 0) && (!(n & (n - 1)));
	}
};
