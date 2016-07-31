//Longest Palindromic Substring 最长回文串
/*
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum 
 length of S is 1000, and there exists one unique longest palindromic substring.
*//*
这道题让我们求最长回文子串，首先说下什么是回文串，就是正读反读都一样的字符串，比如 "bob", "level", "noon" 等等。
那么最长回文子串就是在一个字符串中的那个最长的回文子串。LeetCode中关于回文串的题共有五道，除了这道，其他的四道为 
Palindrome Number 验证回文数字， Validate Palindrome 验证回文字符串， Palindrome Partitioning 拆分回文串，
Palindrome Partitioning II 拆分回文串之二，我们知道传统的验证回文串的方法就是两个两个的对称验证是否相等，
那么对于找回文字串的问题，就要以每一个字符为中心，像两边扩散来寻找回文串，这个算法的时间复杂度是O(n*n)，
可以通过OJ，就是要注意奇偶情况，由于回文串的长度可奇可偶，比如"bob"是奇数形式的回文，"noon"就是偶数形式的回文，
两种形式的回文都要搜索，参见代码如下： 
*/
//时间复杂度n^2
class Solution {
public:
	string longestPalindrome(string s) {
		int startIdx = 0, left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1]) {
				left = i;
				right = i + 1;
				searchPalindrome(s, left, right, startIdx, len);
			}
			left = right = i;
			searchPalindrome(s, left, right, startIdx, len);
		}

		if (len == 0) len = s.size();
		return s.substr(startIdx, len);
	}

	void searchPalindrome(string s, int left, int right, int &startIdx, int &len) {
		int step = 1;
		while ((left - step) >= 0 && (right + step) < s.size()) {
			if (s[left - step] != s[right + step]) break;
			++step;
		}
		int wide = right - left + 2 * step - 1;
		if (wide > len) {
			len = wide;
			startIdx = left - step + 1;
		}
	}
};

/*
此题还可以用动态规划Dynamic Programming来解，根Palindrome Partitioning II 拆分回文串之二的解法很类似，我们维护
一个二维数组dp，其中dp[i][j]表示字符串区间[i, j]是否为回文串，当i = j时，只有一个字符，肯定是回文串，
如果j = i + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，如果i和j不相邻，即j - i >= 2时，
除了判断s[i]和s[j]相等之外，dp[i + 1][j - 1]若为真，就是回文串，通过以上分析，可以写出递推式如下：

dp[i, j] = 1                                   if i == j

         = s[i] == s[j]                        if j = i + 1

	 = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1      

这里有个有趣的现象就是如果我把下面的代码中的二维数组由int改为vector<vector<int> >后，就会超时，
这说明int型的二维数组访问执行速度完爆std的vector啊，所以以后尽可能的还是用最原始的数据类型吧。
*/
//DP
class Solution {
public:
	string longestPalindrome(string s) {
		int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
		
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < i; j++) {
				
				dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
				
				if (dp[j][i] && len < i - j + 1) {
					len = i - j + 1;
					left = j;
					right = i;
				}
			
			}
			
			dp[i][i] = 1;
		}

		return s.substr(left, right - left + 1);
	}
}
