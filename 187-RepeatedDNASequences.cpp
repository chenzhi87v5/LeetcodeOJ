//Repeated DNA Sequences 求重复的DNA序列    Ignore
/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA
, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

//使用hash unordered_set实现  将子字符串编码成int数字，每个字符串的值是唯一确定的
class Solution {
public:
	//将字符串编码成int数字，每个字符串的值是唯一确定的
	int encode (string s) {
		int sum = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A') {
				sum = sum * 4;
			} else if (s[i] == 'C') {
				sum = sum * 4 + 1;
			} else if (s[i] == 'G') {
				sum = sum * 4 + 2;
			} else {
				sum = sum * 4 + 3;
			}
		}
		return sum;
	}

	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		unordered_set<int> hash;             //hash组织的set unodered_set  关键字不可以重复出现
		unordered_set<string> tmp_res;
		
		if (s.size() <= 10)      	     //边界检测
			return result;

		for (int i = 9; i < s.size(); i++) {
			string subs = s.substr(i - 9, 10);  //substr() 用法
			int sum = encode(subs);
			
			if (hash.find(sum) != hash.end()) {
				tmp_res.insert(subs);
			} else {
				hash.insert(sum);
			}
		}
		
		for (auto str : tmp_res) {
			result.push_back(str);
		}
		return result;
	}
};
