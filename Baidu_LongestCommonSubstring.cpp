//最长公共子串(Longest Common Substring)
//法一： 暴力
/*
该解法的思路就如前所说，以字符串中的每个字符作为子串的端点，判定以此为开始的子串的相同字符最长能达到的长度。其实从表层上想，这个算法的复杂度应该只有O(n2)因为该算法把每个字符都成对相互比较一遍，但关键问题在于比较两个字符串的效率并非是O(1)，这也导致了实际的时间复杂度应该是满足Ω(n2)和O(n3)。 
*/
int longestCommonSubstring_n3(const string& str1, const string& str2) {
	size_t size1 = str1.size();
	size_t size2 = str2.size();
	if (size1 == 0 || size2 == 0) return 0;

	// the start position of substring in original string
	int start1 = -1;
	int start2 = -1;
	// the longest length of common substring 
	int longest = 0; 
	
	// record how many comparisons the solution did;
	// it can be used to know which algorithm is better
	int comparisons = 0;
	
	for (int i = 0; i < size1; ++i) {
		for (int j = 0; j < size2; ++j) {
			// find longest length of prefix 
			int length = 0;
			int m = i;
			int n = j;
			while(m < size1 && n < size2) {
				++comparisons;
				if (str1[m] != str2[n]) break;
				
				++length;
				++m;
				++n;
			}

			if (longest < length) {
				longest = length;
				start1 = i;
				start2 = j;
			}
		}
	}
	
	return longest;
}

//法二：
/*
假设两个字符串分别为s和t，s[i]和t[j]分别表示其第i和第j个字符(字符顺序从0开始)，再令L[i, j]表示以s[i]和s[j]为结尾的相同子串的最大长度。应该不难递推出L[i, j]和L[i+1,j+1]之间的关系，因为两者其实只差s[i+1]和t[j+1]这一对字符。若s[i+1]和t[j+1]不同，那么L[i+1, j+1]自然应该是0，因为任何以它们为结尾的子串都不可能完全相同；而如果s[i+1]和t[j+1]相同，那么就只要在以s[i]和t[j]结尾的最长相同子串之后分别添上这两个字符即可，这样就可以让长度增加一位。合并上述两种情况，也就得到L[i+1,j+1]=(s[i + 1]==t[j + 1]?L[i,j]+1:0)这样的关系。

最后就是要小心的就是临界位置：如若两个字符串中任何一个是空串，那么最长公共子串的长度只能是0；当i为0时，L[0,j]应该是等于L[-1,j-1]再加上s[0]和t[j]提供的值，但L[-1,j-1]本是无效，但可以视s[-1]是空字符也就变成了前面一种临界情况，这样就可知L[-1,j-1]==0，所以L[0,j]=(s[0]==t[j]?1:0)。对于j为0也是一样的，同样可得L[i,0]=(s[i]==t[0]?1:0)。
*/
int longestCommonSubstring_n2_n2(const string& str1, const string& str2) {
	size_t size1 = str1.size();
	size_t size2 = str2.size();
	if (size1 == 0 || size2 == 0) return 0;

	vector<vector<int> > table(size1, vector<int>(size2, 0));
	// the start position of substring in original string
	int start1 = -1;
	int start2 = -1;
	// the longest length of common substring 
	int longest = 0; 

	// record how many comparisons the solution did;
	// it can be used to know which algorithm is better
	int comparisons = 0;
	for (int j = 0; j < size2; ++j) {
		++comparisons;
		table[0][j] = (str1[0] == str2[j] ? 1 :0);
	}

	for (int i = 1; i < size1; ++i) {
		++comparisons;
		table[i][0] = (str1[i] == str2[0] ? 1 :0);
		for (int j = 1; j < size2; ++j) {
			++comparisons;
			if (str1[i] == str2[j]) {
				table[i][j] = table[i-1][j-1]+1;
			}
		}
	}

	for (int i = 0; i < size1; ++i) {
		for (int j = 0; j < size2; ++j) {
			if (longest < table[i][j]) {
				longest = table[i][j];
				start1 = i-longest+1;
				start2 = j-longest+1;
			}
		}
	}
	return longest;
}
