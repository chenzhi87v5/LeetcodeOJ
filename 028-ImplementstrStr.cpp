//Implement strStr() 实现strStr()函数
/*
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

/*
这道题让我们在一个字符串中找另一个字符串第一次出现的位置，那我们首先要做一些判断，如果子字符串为空，则返回0，如果子字符串长度大于母字符串长度，则返回-1。然后我们开始遍历母字符串，我们并不需要遍历整个母字符串，而是遍历到剩下的长度和子字符串相等的位置即可，这样可以提高运算效率。然后对于每一个字符，我们都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即可，代码如下： 
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		//return haystack.find(needle);
		int i, j, lenh = haystack.length(), lenn = needle.length();
		if (lenn == 0)
			return 0;
		if (lenh < lenn)
			return -1;
		for (i = 0; i <= lenh - lenn; i++) {  //关键
			for (j = 0; j < lenn; j++)
				if (haystack[i + j] != needle[j])
					break;
			//匹配成功
			if (j == lenn)
				return i;		
		}
		return -1;
	}
};
