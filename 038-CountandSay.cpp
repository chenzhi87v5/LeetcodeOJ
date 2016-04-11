/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

/*1-mySolution:*/
//理解题意 

class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		
		while (--n) {
			result = getNext(result);
		}
		
		return result;
	}

	//根据s的读法计算下一个string
	string getNext(string s) {
		string ret;
		char pre = s[0];
		int count = 1;

		for(int i = 1; i < s.size(); i++) {
			if (s[i] == pre) {
				count++;
			} else {
				char tmp = count + '0';
				ret = ret + tmp +pre;
				pre = s[i];
				count = 1;
			}
		}

		char tmp = count + '0';
		ret = ret + tmp + pre;
		return ret;
	}
};
