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
//使用模板函数递归创建
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}
	
	template<typename InputIterator>  	   //模板定义
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
/*
这道题要求用先序和中序遍历来建立二叉树，跟之前那道Construct Binary Tree from Inorder and Postorder Traversal 由中序和后序遍历建立二叉树原理基本相同，针对这道题，由于先序的顺序的第一个肯定是根，所以原二叉树的根节点可以知道，题目中给了一个很关键的条件就是树中没有相同元素，有了这个条件我们就可以在中序遍历中也定位出根节点的位置，并以根节点的位置将中序遍历拆分为左右两个部分，分别对其递归调用原函数。代码如下： 
*/
class Solution {
public:	
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	
	TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
		if (pLeft > pRight || iLeft > iRight) return NULL;
		
		int i = 0;
		for (i = iLeft; i <= iRight; i++) {
			if (preorder[pLeft] == inorder[i]) break;
		}
		
		TreeNode *cur = new TreeNode(preorder[pLeft]);
		cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
		cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
		return cur;
	}
}
/*
我们下面来看一个例子, 某一二叉树的中序和后序遍历分别为：

Preorder:　  　5　　4　　11　　8　　13　　9

Inorder:　　 　11　　4　　5　　13　　8　　9

 

5　　4　　11　　8　　13　　9　　　　　　=>　　　　　　　　　 5

11　　4　　5　　13　　8　　9　　　　　　　　　　　　　　　 /　　\

 

4　　11　　 　　8　　 13　　9　　　　　　=>　　　　　　　　　5

11　　4　　　　 13　　8　　9　　 　　　　　　　　　　　　　/　　\

　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 4　　　8

 

11　　　　 　　13　　　　9　　　　　　　　=>　　　　　　　　　5

11　　　　　　 13　　　　9　　　　 　　　　　　　　　　　　/　　\

　　　　　　　　　　　　　　　　　　　　　　　　　　　　　4　　　8

　　　　　　　　　　　　　　　　　　　　　　　　　　　　/　　　/     \

　　　　　　　　　　　　　　　　　　　　　　　　　　　11　　  13　　  9

做完这道题后，大多人可能会有个疑问，怎么没有由先序和后序遍历建立二叉树呢，这是因为先序和后序遍历不能唯一的确定一个二叉树，比如下面五棵树：
     1　 　　　　 preorder:　　   1　　2　　3
    / \　　　　　 inorder:　　    2　　1　　3
   2   3　　  　　postorder:　　  2　　3　　1
  
     1   　 　　　preorder:　　   1　　2　　3
    / 　　　 　　 inorder:　　    3　　2　　1
   2 　　　　     postorder: 　 　3　　2　　1
  /
 3

     1　　　　    preorder:　　   1　　2　　3
    / 　　　　　  inorder:　　    2　　3　　1
   2 　　　　 　　postorder:　　  3　　2　　1
    \
     3

     1　　　　    preorder:　　   1　　2　　3
      \ 　　　　  inorder:　　    1　　3　　2
       2 　　　　 postorder:　　  3　　2　　1
      /
     3

     1　　　　    preorder:　　   1　　2　　3
      \ 　　　　　inorder:　　    1　　2　　3
       2 　　　　 postorder:　　  3　　2　　1
        \
	 3

从上面我们可以看出，对于先序遍历都为1 2 3的五棵二叉树，它们的中序遍历都不相同，而它们的后序遍历却有相同的，所以只有和中序遍历一起才能唯一的确定一棵二叉树。
*/
