/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//遍历一遍存储到vector，前后夹逼对比判断是否是回文

class Solution {
public:
	bool isPalindrome(ListNode* head) {		            
		if (head == NULL) {
			return true;
		}

		vector<int> v;
		while(head) {
			v.push_back(head->val);
			head = head->next;
		}
		for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
			if (v[i] != v[j])
				return false;
		}

		return true;
	}
};
