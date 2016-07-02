//Construct Binary Tree from Preorder and Inorder Traversal 由先序和中序遍历建立二叉树
/*
Given preorder and inorder traversal of a tree, construct the binary tree. 
Note:
You may assume that duplicates do not exist in the tree.
*/

/**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

/*
先序序列 与 中序序列还原二叉树
  递归法：每一层继续生成先序遍历 与 中序遍历
  时间复杂度n 空间复杂度logn
  
STL 函数用法
  begin()函数返回一个指向当前vector起始元素的迭代器
  end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器.注意,如果你要访问末尾元素,需要先将此迭代器自减1.
  find( , , val)返回val在第一次出现的位置迭代器
  distance() The number of elements between first and last.
  next() next( , n) 下n个迭代器位置
*/
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}
	
	template<typename InputIterator>
	TreeNode * buildTree(InputIterator pre_first, InputIterator pre_last, InputIterator in_first, InputIterator in_last) {
		if (pre_first == pre_last)         //空元素
			return NULL;
		if (in_first == in_last)           //空元素
			return NULL;

		auto root = new TreeNode(*pre_first);

		auto inRootPos = find(in_first, in_last, *pre_first);  
		auto leftSize = distance(in_first, inRootPos);       //关键点

		root->left = buildTree(next(pre_first), next(pre_first, leftSize + 1), in_first, next(in_first, leftSize));
		root->right = buildTree(next(pre_first, leftSize + 1), pre_last, next(inRootPos), in_last);

		return root;
	}
};
