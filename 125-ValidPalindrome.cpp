//Valid Palindrome 验证回文字符串
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

//前后夹逼
/*STL  transform(first,last,result,op);
       first是容器的首迭代器，last为容器的末迭代器，result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。 
       tolower() 将大写转换成小写
       prev() 返回迭代器的前一个迭代器
       isalnum()如果参数是数字或字母字符，函数返回非零值，否则返回零值
*/
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty() || s.size() <= 1)
			return true;
	
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while (left < right) {
			if (!::isalnum(*left))
				left++;
			else if (!::isalnum(*right))
				right--;
			else if (*left != *right)
				return false;
			else {
				left++;
				right--;
			}
		}
		return true;
	}
};
/*
验证回文字符串是比较常见的问题，所谓回文，就是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。但是这里，加入了空格和非字母数字的字符，增加了些难度，但其实原理还是很简单：只需要建立两个指针，left和right, 分别从字符的开头和结尾处开始遍历整个字符串，如果遇到非字母数字的字符就跳过，继续往下找，直到找到下一个字母数字或者结束遍历，如果遇到大写字母，就将其转为小写。等左右指针都找到字母数字时，比较这两个字符，若相等，则继续比较下面两个分别找到的字母数字，若不相等，直接返回false. 

时间复杂度为O(n), 代码如下：
*/
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.length() < 2) return true;
		int left = 0, right = s.length() - 1;
		while (left < right) {
			while (left < s.length() - 1 && !isAlphaNumber(s[left])) ++left;
			while (right >= 0 && !isAlphaNumber(s[right])) --right;
			if (s[left] != s[right] && left <= right) return false;
			++left;
			--right;
		}
		return true;
	}
	 bool isAlphaNumber(char &ch) {
	 	if (ch >= 'a' && ch <= 'z') return true;
		if (ch >= 'A' && ch <= 'Z') {
			ch += 32;
			return true;
		}
		if (ch >= '0' && ch <= '9') return true;
		return false;
	 }
}
