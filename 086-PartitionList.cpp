//Partition List 划分链表
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or 
equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
	Given 1->4->3->2->5->2 and x = 3,
	return 1->2->2->4->3->5.
*/
/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
*/
/*
这道题要求我们划分链表，把所有小于给定值的节点都移到前面，大于该值的节点顺序不变，相当于一个局部排序的问题。
此题还有一种解法，就是将所有小于给定值的节点取出组成一个新的链表，此时原链表中剩余的节点的值都大于或等于给定值，
只要将原链表直接接在新链表后即可，代码如下：
*/
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode left_dummy(-1); //头结点
		ListNode right_dummy(-1); //头结点
		
		auto left_cur = &left_dummy;   
		auto right_cur = &right_dummy;

		for (ListNode *cur = head; cur; cur = cur->next) {
			if (cur->val < x) {    //小于x的节点连接在左支
				left_cur->next = cur;
				left_cur = cur;
			} else {                   //大于等于x的节点连接与右支
				right_cur->next = cur;
				right_cur = cur;
			}
		}
		left_cur->next = right_dummy.next;    //左右两支连接
		right_cur->next = NULL;

		return left_dummy.next;	
	}
};
