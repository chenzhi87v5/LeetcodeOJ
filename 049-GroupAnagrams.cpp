//Group Anagrams 错位词分组
/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

//map<string, vector<string>> 使用map
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;		
		if(strs.empty())
			return result;

		sort(strs.begin(), strs.end());
		//hash 思想构建map，将排序后的字符串存储到相应的vector
		map<string, vector<string>> mv;
		for (auto str : strs) {
			string tmp = str;
			sort(tmp.begin(), tmp.end());
			mv[tmp].push_back(str);
		}
		for (auto it : mv) {
			result.push_back(it.second);
		}
		return result;
	}
};
