//Word Pattern 词语模式
/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
	pattern = "abba", str = "dog cat cat dog" should return true.
	pattern = "abba", str = "dog cat cat fish" should return false.
	pattern = "aaaa", str = "dog cat cat dog" should return false.
	pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

/*
使用Map:
定义一个map，每遇到一个新的模式，以模式为key，将对应的单词存入map；遇到map里已有的模式，检查当前str的单词是否与map记载模式
所对应的value值相同，只要出现不同，直接返回false。

这种判断方法可以解决：pattern = "abba", str = "dog cat cat fish"这种情况。
但是，只使用一个map无法判断这种情况：pattern = "abba", str = "dog dog dog dog"，一开始a作为一个新模式，被存入map，到了第二
次迭代，b作为一个新模式，也被存入map，dog被分配到两个不同的模式，显然这是不对的。

为了解决这个问题，需要两个map。另一个map2用于记载单词与模式的对应关系。
总的来说，map1用于记载模式到单词的对应关系，但可能出现多个模式对应到同个单词的情形。
而map2用于记载单词到模式的对应关系，在判断中同时加入对两个map的判断，才可以分辨所有情况。
*/

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> map1;   	//模式对应单词
		unordered_map<string, char> map2;	//单词对应模式
		vector<string> vec;  			//逐个存储单词

		//以下操作分割str为多个单词
		for (int i = 0, j = 0; i < str.size(); i++) {
			if (i == str.size() - 1) {
				string temp = str.substr(j, i - j + 1);
				vec.push_back(temp);
			} 
			if (str[i] == ' ') {
				string temp = str.substr(j, i - j);
				vec.push_back(temp);
				j = i + 1;
			}
		}

		if (pattern.size() != vec.size())
			return false;

		for (int i = 0; i < pattern.size(); i ++) {
			//当前模式未出现，且对应的单词也未出现，才将键值对存入表
			if (map1.find(pattern[i]) == map1.end() && map2.find(vec[i]) == map2.end()) {
				map1.insert(make_pair(pattern[i], vec[i]));
				map2.insert(make_pair(vec[i], pattern[i]));
			} else if (map1[pattern[i]] != vec[i]) {
				return false;
			}
		}

		return true;
	}
};
