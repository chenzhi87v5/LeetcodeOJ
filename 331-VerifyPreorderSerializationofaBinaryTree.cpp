//Verify Preorder Serialization of a Binary Tree 验证二叉树的先序序列化
/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

/*
这道题给了我们一个类似序列化二叉树后的字符串，关于二叉树的序列化和去序列化可以参见我之前的博客Serialize and Deserialize Binary Tree，这道题让我们判断给定是字符串是不是一个正确的序列化的二叉树的字符串。那么根据之前那边博客的解法，我们还是要用istringsteam来操作字符串，C++里面没有像Java那样有字符串的split函数，可以直接分隔任意字符串，我们只能使用getline这个函数，来将字符串流的内容都存到一个vector数组中。我们通过举一些正确的例子，比如"9,3,4,#,#,1,#,#,2,#,6,#,#" 或者"9,3,4,#,#,1,#,#,2,#,6,#,#"等等，可以观察出如下两个规律：

1. 数字的个数总是比#号少一个
2. 最后一个一定是#号

那么我们加入先不考虑最后一个#号，那么此时数字和#号的个数应该相同，如果我们初始化一个为0的计数器，遇到数字，计数器加1，遇到#号，计数器减1，那么到最后计数器应该还是0。下面我们再来看两个返回False的例子，"#,7,6,9,#,#,#"和"7,2,#,2,#,#,#,6,#"，那么通过这两个反例我们可以看出，如果根节点为空的话，后面不能再有节点，而且不能有三个连续的#号出现。所以我们再加减计数器的时候，如果遇到#号，且此时计数器已经为0了，再减就成负数了，就直接返回False了，因为正确的序列里，任何一个位置i，在[0, i]范围内的#号数都不大于数字的个数的。当循环完成后，我们检测计数器是否为0的同时还要看看最后一个字符是不是#号。参见代码如下：
*/

// istringstream ss; getline(ss, str, ',')   将字符串按照指定字符分隔
class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder.empty())
			return false;
		
		istringstream in(preorder);         //istringstream 的使用
		vector<string> v;
		string val;
		int d = 0;

		while (getline(in, val, ','))       //getline 使用，将字符串按照指定字符分隔如:getline(in, val, ',')
			v.push_back(val);
		
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == "#") {                 
				if (d == 0)
					return false;
				else
					d--;
			} else {
				d++;
			}
		}
		return d  != 0 ? false : v.back() == "#";
	}
};
