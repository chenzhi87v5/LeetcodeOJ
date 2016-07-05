//Reverse Linked List 倒置链表  
/* 
Reverse a singly linked list.
click to show more hints.
Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
/*反转单链表 递归与迭代均需掌握*/
//ME-头插法 迭代
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *prev = NULL; //新的链表头
		while (head != NULL) {
			ListNode *temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
		return prev;
	}
};
/*
之前做到 Reverse Linked List II 倒置链表之二的时候我还纳闷怎么只有二没有一呢，原来真是忘了啊，现在才加上，这道题跟之前那道比起来简单不少，题目为了增加些许难度，让我们分别用迭代和递归来实现，但难度还是不大。
我们先来看迭代的解法，思路是在原链表之前建立一个dummy node，因为首节点会变，然后从head开始，将之后的一个节点移到dummy node之后，重复此操作知道head成为末节点为止，代码如下： 
*/
//Iterative 迭代
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *cur = head;
		while (cur->next) {
			ListNode *tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = dummy->next;
			dummy->next = tmp;
		}
		return dummy->next;
	}
}
/*
下面我们来看递归解法，代码量更少，递归解法的思路是，不断的进入递归函数，直到head指向最后一个节点，p指向之前一个节点，然后调换head和p的位置，再返回上一层递归函数，再交换p和head的位置，每次交换后，head节点后面都是交换好的顺序，直到p为首节点，然后再交换，首节点就成了为节点，此时整个链表也完成了翻转，代码如下： 
*/
//Recursive 递归
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *p = head;
		head = reverseList(p->next);
		p->next->next = p;
		p->next = NULL;
		return head;
	}
}
