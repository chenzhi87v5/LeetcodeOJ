/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

//1-:前后夹逼
//STL
//transform(first,last,result,op);
  //first是容器的首迭代器，last为容器的末迭代器，result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。 
//tolower() 将大写转换成小写
//prev() 返回迭代器的前一个迭代器
//isalnum()如果参数是数字或字母字符，函数返回非零值，否则返回零值
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
