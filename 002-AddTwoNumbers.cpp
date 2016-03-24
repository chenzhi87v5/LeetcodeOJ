/*
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*1-mySolution，时间复杂度 n ,空间复杂度 n */
/*使用long int 防止溢出*/
/*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {		            
		long int num1 = 0, num2 = 0, num3;
		long int idx = 1, tem = 10, pval;
		ListNode *p1 = NULL, *p2 = NULL, *ph =NULL;

		for (ListNode* p = l1;; p = p->next) {
			num1 +=  p->val*idx;
			idx *= 10;
			if (p->next == NULL)
				break;
		}
	
		idx = 1;
		for (ListNode* p = l2;; p = p->next) {
			num2 += p->val*idx;
			idx *= 10;
			if (p->next == NULL)
				break;
		}	
		
		num3 = num1 + num2;
		pval = num3 % 10;
		num3 = num3 / 10;
		p1 = new ListNode(pval);
		ph = p1;
		while (num3 != 0) {
			pval = num3 % 10;
			num3 = num3 / 10;
			p2 = new ListNode(pval);
			p1->next = p2;
			p1 = p2;
		}
		return  ph;
	}
};
*/

/*2-最优解法 时间复杂度 m + n ,空间复杂度 1*/
/*自定义加算法，使用int carry作为进位值*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		int carry = 0;
		ListNode *prev = &dummy;
		for (ListNode *pa = l1, *pb = l2; pa != NULL || pb != NULL; pa = pa == NULL ? NULL : pa->next, pb = pb == NULL ? NULL : pb->next, prev = prev->next) {
			const int ai = pa == NULL ? 0 : pa->val;
			const int bi = pb == NULL ? 0 : pb->val;
			const int value = (ai + bi +carry) % 10;
			carry = (ai + bi + carry) / 10;
			prev->next = new ListNode(value);
		}
		if (carry > 0)
			prev->next = new ListNode(carry);
		return dummy.next;
	}
};

int main() {
	ListNode *p1 = new ListNode(9);
	ListNode *p2 = new ListNode(1);
	Solution S;
	
	ListNode *p3 = S.addTwoNumbers(p1, p2);
	cout<< p3->val <<endl;
	
	return 0;
}

