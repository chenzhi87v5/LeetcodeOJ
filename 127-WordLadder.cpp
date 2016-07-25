//Word Ladder 词语阶梯
/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation 
sequence from beginWord to endWord, such that:
	1.Only one letter can be changed at a time
	2.Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
	Return 0 if there is no such transformation sequence.
	All words have the same length.
	All words contain only lowercase alphabetic characters.
*/
//1-:广度优先搜索
//unordered_set 数据结构   //1.关联容器map与set  //2.顺序容器 vector list deque stack queue
class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

		if (beginWord.size() != endWord.size())
			return 0;
		if (beginWord.empty() || endWord.empty())
			return 0;

		queue<string> path;		//广度优先 存储相差一个字符的存在于wordList的字符串
		path.push(beginWord);
		int level = 1;          	//路径长度
		int count = 1;          	//广度优先当前层的字符串数量
		wordList.erase(beginWord);   	//防止重复使用，必须删除

		while (wordList.size() > 0 && !path.empty()) {
			string curword = path.front();
			path.pop();
			count--;
			for (int i = 0; i < curword.size(); i++) {
				string tmp = curword;
				for (char j = 'a'; j <= 'z'; j++) {
					if (tmp[i] == j)
						continue;

					tmp[i] = j;
					if (tmp == endWord)     		  //找到目标结果返回length
						return level + 1;

					if (wordList.find(tmp) != wordList.end()) //将相差一个字符的在wordList的字符串加入path
						path.push(tmp);
					
					ordList.erase(tmp);    			  //防止重复使用 删除
				}
			}
			//当前层处理完，处理广度优先下一层字符
			if (count == 0) {
				count = path.size();
				level++;
			}
		}
		return 0;
	}
};
