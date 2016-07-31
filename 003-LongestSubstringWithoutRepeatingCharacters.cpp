//Longest Substring Without Repeating Characters 最长无重复子串
/*
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

/*
贪心法,时间复杂度n，空间复杂度1
       贪心法：单个子问题决定父问题
       动规法：单个子问题只能影响父问题不能决定父问题
hash数组记录 ASCII字符 共有256个  类似窗口法
*//*
我们还是建立一个256位大小的整型数组来代替哈希表，这样做的原因是ASCII表共能表示256个字符，所以可以记录所有字符，
然后我们需要定义两个变量max_len和start，其中max_len用来记录最长无重复子串的长度，start指向该无重复子串左边的起始位置，
然后我们遍历整个字符串，对于每一个遍历到的字符，如果哈希表中该字符串对应的值为-1，说明没有遇到过该字符，
则此时将其位置记录last中，如果遇到相同的字符，则其上次为值>=start 则此时计算max_len, start向字符上次出现的位置右移一位，
last更新! */
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const int ASCII_MAX = 256; 	// ASCII 共有256个
		int last[ASCII_MAX]; 		//记录字符上次出现的位置
		int start = 0; 			//记录当前子串的起始位置

		fill(last, last + ASCII_MAX, -1); //所有字符位置初始化为-1  fill STL
		int max_len = 0;
		for (int i = 0; i < s.size(); i++) {
			if (last[s[i]] >= start) {
				max_len = max (i - start, max_len);
				start = last[s[i]] + 1;
			}
			last[s[i]] = i;
		}
		return max((int)s.size() - start, max_len); //勿忘最后一次取值
	}
};
/*
if (i - start > max_len) {
	max_len = max(i - start);
	max_start = start;
}
.....
return s.substr(start, max_len);
*/
