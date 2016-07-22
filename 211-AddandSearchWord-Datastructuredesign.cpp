//Add and Search Word - Data structure design 添加和查找单词-数据结构设计   Trie 单词查找树 Prefix Tree 前缀树实现
/*
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
click to show hint.
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/
//Trie 单词查找树 Prefix Tree 前缀树  先构造单词查找树 
class TrieNode {      				//TrieNode类设计
public:
	bool isEnd;
	TrieNode *children[26];
	TrieNode() : isEnd(false) {    		//":默认初始化方式" 构造函数
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
	}
};

//具体实现类
class WordDictionary {
private:
	TrieNode *root;
public:
	//构造函数
	WordDictionary() {
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode *cur = root;
		for (int i = 0; i < word.size(); i++) {
			int index = word[i] - 'a';
			if (cur->children[index] == NULL) {
				cur->children[index] = new TrieNode();
			}
			cur = cur->children[index];
		}
		cur->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		int n = word.size();
		return search(word, n, 0, root);
	}
	
	//使用递归函数
	bool search(string &word, int n, int pos, TrieNode *cur) {
		if (cur == NULL) {
			return false;
		}
		if (pos == n) {
			return cur->isEnd;
		}

		if (word[pos] == '.') {
			for (int i = 0; i < 26; i++) {
				if (cur->children[i]) {
					if (search(word, n, pos + 1, cur->children[i])) {
						return true;
					}
				}
			}
		} else {
			int index = word[pos] - 'a';
			if (cur->children[index]) {
				return search(word, n, pos + 1, cur->children[index]);
			}
		}
		return false;
	}
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
