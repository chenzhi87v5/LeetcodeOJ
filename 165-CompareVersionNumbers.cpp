/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

	0.1 < 1.1 < 1.2 < 13.37
*/

//1-:逐位比较就好了，把字符串转化成整型，这样就可以忽略前置0的影响
//考虑类似 “1.2.3”版本号
class Solution {
public:
	int compareVersion(string version1, string version2) {
		int val1, val2;
		int idx1 = 0, idx2 = 0;
		
		while (idx1 < version1.length() || idx2 < version2.length()) {
			//值1
			val1 = 0;
			while (idx1 < version1.length()) {
				if (version1[idx1] == '.') {
					++idx1;
					break;
				}
				val1 = val1 * 10 + (version1[idx1] - '0');
				++idx1;
			}

			//值2
			val2 = 0;
			while (idx2 < version2.length()) {
				if (version2[idx2] == '.') {
					++idx2;
					break;
				}
				val2 = val2 * 10 + (version2[idx2] - '0');
				++idx2;
			}

			//比较
			if (val1 > val2)
				return 1;
			if (val1 < val2)
				return -1;
		}

		return 0;  //相等
	}
};
