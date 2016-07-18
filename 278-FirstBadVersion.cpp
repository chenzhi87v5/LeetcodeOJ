//First Bad Version 第一个坏版本
/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

//二分法 效率为 logn  题意为找出第一个为bad的点 使用二分查找法 效率最高
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int start = 1, end = n;
		
		while (start + 1 < end) {
			int mid = start + (end - start) / 2; //取中间节点
			
			if (isBadVersion(mid)) {       //如果为bad 则end = mid
				end = mid;
			} else {                       //如果中间节点不为bad 则 start = mid
				start = mid;
			}
		}
		
		if (isBadVersion(start)) {
			return start;
		}


		return end;
	}
};
