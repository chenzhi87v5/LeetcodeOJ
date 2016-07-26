//Implement Trie (Prefix Tree)     实现字典树(前缀树)
/*  
Implement a trie with insert, search, and startsWith methods. 
Note: You may assume that all inputs are consist of lowercase letters a-z.
*/
class TrieNode {   //节点类
public:
	// Initialize your data structure here.
	//构造函数
	TrieNode() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}	
		isString = false;
	}

	//变量
	TrieNode *next[26];
	bool isString;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	
	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->next[word[i] - 'a'] == NULL) {
				p->next[word[i] - 'a'] = new TrieNode();
			}
			p = p->next[word[i] - 'a'];
		}
		p->isString = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p == NULL) 
				return false;
			p = p->next[word[i] - 'a'];
		}
		if (p == NULL || p->isString == false)
			return false;
		return true;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (int i = 0; i < prefix.size(); i++) {
			p = p->next[prefix[i] - 'a'];
			if(p == NULL)
				return false;
		}
		return true;
	}
private:
	TrieNode* root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
