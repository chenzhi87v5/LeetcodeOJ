//Intersection of Two Linked Lists 求两个链表的交点
/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:

A:          a1 → a2
                    ↘
		      c1 → c2 → c3
		     ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:
	If the two linked lists have no intersection at all, return null.
	The linked lists must retain their original structure after the function returns.
	You may assume there are no cycles anywhere in the entire linked structure.
	Your code should preferably run in O(n) time and use only O(1) memory.
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
具体算法为：分别遍历两个链表，得到分别对应的长度。然后求长度的差值，把较长的那个链表向后移动这个差值的个数，然后一一比较
即可。代码如下：
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		
		ListNode *iter1 = headA;
		ListNode *iter2 = headB;
		
		//求两个链表长度len1 len2
		int len1 = 1;
		while (iter1->next != NULL) {
			iter1 = iter1->next;
			len1++;
		}
		int len2 = 1;
		while (iter2->next != NULL) {
			iter2 = iter2->next;
			len2++;
		}
		
		if (iter1 != iter2)     //判断是否相交
			return NULL;
		
		if (len1 > len2) {      //对齐一起走
			for (int i = 0; i < len1 - len2; i++)
				headA = headA->next;
		} else if (len1 < len2) {
			for (int i = 0; i < len2 - len1; i++ )
				headB = headB->next;
		}

		while (headA != headB) {    //获取交点
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
};
/*
 这道题还有一种特别巧妙的方法，虽然题目中强调了链表中不存在环，但是我们可以用环的思想来做，我们让两条链表分别从各自的开头i
 开始往后遍历，当其中一条遍历到末尾时，我们跳到另一个条链表的开头继续遍历。两个指针最终会相等，而且只有两种情况，一种情况
 是在交点处相遇，另一种情况是在各自的末尾的空节点处相等。为什么一定会相等呢，因为两个指针走过的路程相同，是两个链表的长
 度之和，所以一定会相等。这个思路真的很巧妙，而且更重要的是代码写起来特别的简洁，参见代码如下：
*/  //利用环的思想
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		
		ListNode *a = headA, *b = headB;
		while (a != b) {
			a = a ? a->next : headB;
			b = b ? b->next : headA;
		}
		return a;
	}
}
