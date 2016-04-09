/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

/*1-mySolution:*/
//JiuZhang Answers:
class Solution {
public:
	int strStr(string haystack, string needle) {
		//return haystack.find(needle);
		int i, j, lenh = haystack.length(), lenn = needle.length();
		if (lenn == 0)
			return 0;
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
