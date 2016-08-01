//Linked List Cycle II 单链表中的环之二
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
 法一：于是我们可以从head 开始另设一个指针slow2，两个慢指针每次前进一步，它俩一定会在环入口点相遇。
 这个求单链表中的环的起始点是之前那个判断单链表中是否有环的延伸. 还是要设快慢指针，不过这次要记录两个指针相遇的位置，
 当两个指针相遇了后，让其一指针从链表头开始，此时再相遇的位置就是链表中环的起始位置。代码如下：
 
 法二： 计算环中节点数目，剑指OFFER  270页
 */
// 时间复杂度n 空间复杂度1  法一:感觉逻辑性不强
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {    //相遇点 再起一个slow2 依次向后移动必在环入口相遇
				ListNode *slow2 = head;
				while (slow2 != slow) {
					slow2 = slow2->next;
					slow = slow->next;
				}
				return slow2;
			}
		}
		return NULL;
	}
}

//法二 逻辑性强
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head)
			return NULL;
		ListNode *p, *p2;
		
		ListNode * mNode = meetNode(head);
		if (mNode == NULL)
			return NULL;
		
		int num = 1;              //计算环的长度
		p = mNode;
		while (p->next != mNode) {
			p = p->next;
			num++;
		}

		p = head;
		for (int i = 0; i < num; i++) 
			p = p->next;
		p2 = head;
		while (p != p2) {
			p = p->next;
			p2 = p2->next;
		}
		return p;
	}

	//找到环内一点
	ListNode* meetNode(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
				return slow;
		}
		return NULL;
	}
}
