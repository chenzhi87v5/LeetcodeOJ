//Rotate List 旋转链表
/*
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
这道旋转链表的题和之前那道 Rotate Array 旋转数组 很类似，但是比那道要难一些，因为链表的值不能通过下表来访问，只能一个一个的走
，我刚开始拿到这题首先想到的就是用快慢指针来解，快指针先走k步，然后两个指针一起走，当快指针走到末尾时，慢指针的下一个位置是新
的顺序的头结点，这样就可以旋转链表了，自信满满的写完程序，放到OJ上跑，以为能一次通过，结果跪在了各种特殊情况，首先一个就是当原
链表为空时，直接返回NULL，还有就是当k大于链表长度和k远远大于链表长度时该如何处理，我们需要首先遍历一遍原链表得到链表长度n，然
后k对n取余，这样k肯定小于n，就可以用上面的算法了，代码如下: 
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode dummy(-1);
		dummy.next = head;
		
		if (head == NULL || head->next == NULL || k == 0)  //判断是否需要旋转
			return dummy.next;

		ListNode *p = head, *q;
		int n = 1;
		while (p->next != NULL) {   	//计算链表长度
			p = p->next;
			n++;
		}
		
		k = k % n;
		if (k == 0)        		// 判断是否需要旋转
			return dummy.next;

		p = head;
		q = head;
		while (k--) {
			q = q->next;
		}

		while (q->next != NULL) {
			p = p->next;
			q = q->next;
		}
		dummy.next = p->next;
		p->next = NULL;
		q->next = head;

		return dummy.next;
	}
};

//2-形成环,向后跑len-k步
/*
这道题还有一种解法，跟上面的方法类似，但是不用快慢指针，一个指针就够了，原理是先遍历整个链表获得链表长度n，然后此时把链表头和
尾链接起来，在往后走n - k % n个节点就到达新链表的头结点前一个点，这时断开链表即可，代码如下: 
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || k == 0)
			return head;

		int len = 1;
		ListNode *p = head;
		while (p->next) { //求链表长度
			len++;
			p = p->next;
		}

		k = len - k % len;
		if(k == len)   //不需要旋转
			return head;

		p->next = head; //首尾想连
		for (int step = 0; step < k; step++)
			p = p->next; //接着往后跑
		head = p->next;  //新的首节点
		p->next = NULL;   // 断开环
		return head;	
	}
};
